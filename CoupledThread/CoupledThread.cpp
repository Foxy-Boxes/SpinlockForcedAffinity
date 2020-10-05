#include "CoupledThread.h"

#include <iostream>
#include <cassert>

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

CoupledThread::CoupledThread(CtPropertyFlag flag) {
    m_flag = flag;
    assert(flag & (CT_STARTS_CAPTURED|CT_STARTS_RELEASED));
    assert(flag != (CT_STARTS_RELEASED|CT_PRIORITY_NONE));
    assert(flag & (CT_PRIORITY_FIRST | CT_PRIORITY_SECOND | CT_PRIORITY_NONE));
    if(flag & CT_STARTS_CAPTURED){
        counter.store((((flag & CT_PRIORITY_FIRST) + (flag & CT_PRIORITY_SECOND)+ (flag & CT_PRIORITY_NONE)) >> 2)
            ,std::memory_order_relaxed);//use flag because maybe m_flag is not assigned yet}
    } else{
        switch(flag & (CT_PRIORITY_FIRST | CT_PRIORITY_SECOND)){
            case CT_PRIORITY_FIRST:
                counter.store(0,std::memory_order_relaxed);
                break;
            case CT_PRIORITY_SECOND:
                counter.store(3,std::memory_order_relaxed);
                break;
            default:
                break;
        }

    }
}

void CoupledThread::start(uint32_t selectedCpu=0) {
#ifdef __unix__
    pthread_attr_t attr[3]{};
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    CPU_SET(selectedCpu, &cpuset);
    uint8_t rc;
    rc = pthread_attr_setaffinity_np(attr,
                                   sizeof(cpu_set_t), &cpuset);
    if (rc) {
        std::cerr << "Error calling pthread_setaffinity_np: " << rc << "\n";
    }
    rc = pthread_attr_setaffinity_np(&attr[1],
                                     sizeof(cpu_set_t), &cpuset);
    if (rc) {
        std::cerr << "Error calling pthread_setaffinity_np: " << rc << "\n";
    }
    rc = pthread_attr_setaffinity_np(&attr[2],
                                     sizeof(cpu_set_t), &cpuset);
    if (rc) {
        std::cerr << "Error calling pthread_setaffinity_np: " << rc << "\n";
    }
    pthread_attr_setdetachstate(&attr[0],PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attr[1],PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attr[2],PTHREAD_CREATE_JOINABLE);
    pthread_t regThread;
    m_firstThread = &firstThread;
    m_secondThread = &secondThread;

    pthread_create(&regThread, &attr[0], RegisterHint, this);


#endif
#ifdef WIN32
    DWORD_PTR processAffMask = 1 << selectedCpu;
    SetProcessAffinityMask(GetCurrentProcess(), processAffMask);
    //Not Sure if this trick will work in windows
    //Windows seems to give each thread a copy of all registers?
    //its already in the register wtf?
    __asm__(""::"r"(counter));
    m_firstThread = CreateThread(NULL, 0, FirstThreadStatic, this, CREATE_SUSPENDED, NULL);
    m_secondThread = CreateThread(NULL, 0, SecondThreadStatic, this, CREATE_SUSPENDED, NULL);
    SetThreadAffinityMask(m_firstThread, processAffMask);
    SetThreadAffinityMask(m_secondThread, processAffMask);
#endif
    switch(m_flag & (CT_PRIORITY_NONE | CT_PRIORITY_FIRST | CT_PRIORITY_SECOND)){
        case CT_PRIORITY_NONE:
#if defined(WIN32)
            ResumeThread(m_firstThread);
            ResumeThread(m_secondThread);
#elif defined(__unix__)
            pthread_join(regThread, nullptr);
            pthread_create((pthread_t*)m_firstThread, &attr[1], FirstThreadStatic, this);
            pthread_create((pthread_t*)m_secondThread, &attr[2], SecondThreadStatic, this);
#endif
            break;
        case CT_PRIORITY_FIRST:
#if defined(WIN32)
            ResumeThread(m_firstThread);
            Sleep(100);
            ResumeThread(m_secondThread);
#elif defined(__unix__)
            pthread_join(regThread, nullptr);
            pthread_create((pthread_t*)m_firstThread, &attr[1], FirstThreadStatic, this);
            pthread_create((pthread_t*)m_secondThread, &attr[2], SecondThreadStatic, this);
#endif
            break;
        case CT_PRIORITY_SECOND:
#if defined(WIN32)
            ResumeThread(m_secondThread);
            Sleep(100);
            ResumeThread(m_firstThread);
#elif defined(__unix__)
            pthread_join(regThread, nullptr);
            pthread_create((pthread_t*)m_secondThread, &attr[1], SecondThreadStatic, this);
            pthread_create((pthread_t*)m_firstThread, &attr[2], FirstThreadStatic, this);
#endif
            break;
    }

}

void CoupledThread::join_all() {
#if defined(WIN32)
    WaitForSingleObject(m_secondThread, INFINITE);
    WaitForSingleObject(m_firstThread, INFINITE);
#elif defined(__unix__)
    pthread_join(*(pthread_t *)m_secondThread, NULL);
    pthread_join(*(pthread_t *)m_firstThread, NULL);
#endif
}

CoupledThread::CoupledThread() {
    m_flag = CT_STARTS_CAPTURED|CT_PRIORITY_FIRST;
    counter.store(1,std::memory_order_relaxed);
}

void CoupledThread::unlock_one() noexcept {
    counter.store(3, std::memory_order_release);
}

void CoupledThread::unlock_two() noexcept {
    counter.store(0, std::memory_order_release);
}

void CoupledThread::unlock_all() noexcept {
    counter.store(5, std::memory_order_release);
}

void CoupledThread::lock_one() noexcept {
    static timespec Spec = {0,7};
    while(!counter.load(std::memory_order_relaxed)){
        nanosleep(&Spec, nullptr);
    }
    for (;;) {
        if (counter.exchange(1, std::memory_order_acquire)==3) {
            break;
        }
        while (counter.load(std::memory_order_relaxed)!=3){
            nanosleep(&Spec, nullptr);
        }
    }
}

void CoupledThread::lock_two() noexcept {
    static timespec Spec = {0,5};
    static timespec Specless = {0,5};
    while (counter.load(std::memory_order_relaxed)==3){
        nanosleep(&Specless, nullptr);
    }
    for (;;) {
        if (!counter.exchange(2, std::memory_order_acquire)) {
            break;
        }
        while (counter.load(std::memory_order_relaxed)){
            nanosleep(&Spec, nullptr);
        }
    }
}

void CoupledThread::lock_all() noexcept {
    for (;;) {
        if (counter.exchange(4, std::memory_order_acquire) == 5) {
            break;
        }
        while (counter.load(std::memory_order_relaxed)!=5){
            shortFunc(m_outsidePtr);
        }
    }
}

void CoupledThread::shortFunc(void *data) {

}

void CoupledThread::setOutsideData(void *data) {
    m_outsidePtr = data;
}

bool CoupledThread::try_lock() noexcept {
    return !counter.load(std::memory_order_relaxed) &&
           !counter.exchange(1, std::memory_order_acquire);
}

void CoupledThread::FirstThreadFunc() {

}

void CoupledThread::SecondThreadFunc() {

}

#ifdef WIN32
static DWORD WINAPI CoupledThread::FirstThreadStatic( LPVOID lpParam ){
    ((CoupledThread*)lpParam)->FirstThreadFunc();
}
static DWORD WINAPI CoupledThread::SecondThreadStatic( LPVOID lpParam ){
    ((CoupledThread*)lpParam)->SecondThreadFunc();
}
static DWORD WINAPI CoupledThread::RegisterHint( LPVOID lpParam ){
    __asm__(""::"r"(((CoupledThread*)lpParam)->counter));
}
#elif defined(__unix__)
void* CoupledThread::FirstThreadStatic( void* lpParam ){
    ((CoupledThread*)lpParam)->FirstThreadFunc();
    return nullptr;
}
void* CoupledThread::SecondThreadStatic( void* lpParam ){
    ((CoupledThread*)lpParam)->SecondThreadFunc();
    return nullptr;
}
void* CoupledThread::RegisterHint( void* lpParam ){
    ((CoupledThread*)lpParam)->counter.load(std::memory_order_relaxed);
    __asm__("mov %eax, %r8d");
    __asm__("mov %eax, %r9d");
    __asm__("mov %eax, %r10d");
    __asm__("mov %eax, %r11d");
    __asm__("mov %eax, %r12d");
    return nullptr;
}
#endif