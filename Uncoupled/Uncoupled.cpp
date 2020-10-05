#include "Uncoupled.h"

#include <iostream>


void Uncoupled::lock_one() {
    while(!counter.load(std::memory_order_relaxed)){
        shortFunc(m_outsidePtr);
    }
    for (;;) {
        if (counter.exchange(1, std::memory_order_acquire)==3) {
            break;
        }
        while (counter.load(std::memory_order_relaxed)!=3){
            shortFunc(m_outsidePtr);
        }
    }
}

void Uncoupled::lock_two() {
    while (counter.load(std::memory_order_relaxed)==3){
        shortFunc(m_outsidePtr);
    }
    for (;;) {
        if (!counter.exchange(2, std::memory_order_acquire)) {
            break;
        }
        while (counter.load(std::memory_order_relaxed)){
            shortFunc(m_outsidePtr);
        }
    }
}

void Uncoupled::unlock_one() {
    counter.store(3, std::memory_order_release);
}

void Uncoupled::unlock_two() {
    counter.store(0, std::memory_order_release);
}

void Uncoupled::shortFunc(void *data) {

}

void Uncoupled::setInitialCounter(uint32_t c) {
    counter.store(c, std::memory_order_relaxed);
}

void Uncoupled::setOutsideData(void *data) {
    m_outsidePtr=data;
}

void Uncoupled::start() {

#ifdef __unix__
    pthread_attr_t attr[3]{};
    pthread_attr_setdetachstate(&attr[0],PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attr[1],PTHREAD_CREATE_JOINABLE);
    pthread_attr_setdetachstate(&attr[2],PTHREAD_CREATE_JOINABLE);

#endif
#ifdef WIN32
    m_firstThread = CreateThread(NULL, 0, FirstThreadStatic, this, CREATE_SUSPENDED, NULL);
    m_secondThread = CreateThread(NULL, 0, SecondThreadStatic, this, CREATE_SUSPENDED, NULL);
#endif

#if defined(WIN32)
            ResumeThread(m_firstThread);
            ResumeThread(m_secondThread);
#elif defined(__unix__)
            pthread_create(&firstThread, &attr[1], FirstThreadStatic, this);
            pthread_create(&secondThread, &attr[2], SecondThreadStatic, this);
#endif
}

void Uncoupled::join_all() {

#if defined(WIN32)
    WaitForSingleObject(m_secondThread, INFINITE);
    WaitForSingleObject(m_firstThread, INFINITE);
#elif defined(__unix__)
    pthread_join(secondThread, NULL);
    pthread_join(firstThread, NULL);
#endif
}

void Uncoupled::FirstThreadFunc() {

}

void Uncoupled::SecondThreadFunc() {

}

void *Uncoupled::FirstThreadStatic(void *lpParam) {
    ((Uncoupled*)lpParam)->FirstThreadFunc();
    return nullptr;
}

void *Uncoupled::SecondThreadStatic(void *lpParam) {
    ((Uncoupled*)lpParam)->SecondThreadFunc();
    return nullptr;
}
