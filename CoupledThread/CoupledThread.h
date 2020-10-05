#ifndef COUPLEDTHREAD_COUPLEDTHREAD_H
#define COUPLEDTHREAD_COUPLEDTHREAD_H

#include <atomic>
#include <thread>

#if defined(WIN32)
#include <windows.h>
#elif defined(__unix__)
#include <unistd.h>
#endif

typedef uint32_t CtPropertyFlag;
class CoupledThread{
private:
    std::atomic<uint32_t> counter;
    void* m_firstThread;
    void* m_secondThread;
    CtPropertyFlag m_flag;
    void* m_outsidePtr;
protected:
#if defined(WIN32)
    static DWORD WINAPI FirstThreadStatic( LPVOID lpParam );
    static DWORD WINAPI SecondThreadStatic( LPVOID lpParam );
    static DWORD WINAPI RegisterHint( LPVOID lpParam );
#elif defined(__unix__)
    pthread_t firstThread;
    pthread_t secondThread;
    static void* FirstThreadStatic( void* lpParam );
    static void* SecondThreadStatic( void* lpParam );
    static void* RegisterHint( void* lpParam );
#endif
    virtual inline void unlock_one() noexcept ;
    virtual inline void unlock_two() noexcept ;
    virtual inline void unlock_all() noexcept ;
    virtual inline void lock_one() noexcept ;
    virtual inline void lock_two() noexcept ;
    virtual inline void lock_all() noexcept ;
    virtual inline bool try_lock() noexcept ;
    virtual inline void shortFunc(void* data);
    virtual void FirstThreadFunc();
    virtual void SecondThreadFunc();
public:
    CoupledThread();
    CoupledThread(CtPropertyFlag flag);
    void setOutsideData(void* data);
    void start(uint32_t selectedCpu);
    void join_all();

};
typedef enum CtPropertyFlagBits{
    CT_STARTS_CAPTURED = 0x00000001,
    CT_STARTS_RELEASED = 0x00000002,
    CT_PRIORITY_FIRST  = 0x00000004,
    CT_PRIORITY_SECOND = 0x00000008,
    CT_PRIORITY_NONE   = 0x00000010
} CtPropertyFlagBits;
void hello();

#endif //COUPLEDTHREAD_COUPLEDTHREAD_H
