#ifndef UNCOUPLED_UNCOUPLED_H
#define UNCOUPLED_UNCOUPLED_H
#include <atomic>
#include <thread>
class Uncoupled{
private:
    std::atomic<uint32_t> counter;
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
#endif
    virtual void FirstThreadFunc();
    virtual void SecondThreadFunc();
    virtual inline void shortFunc(void* data);
    virtual inline void lock_one();
    virtual inline void lock_two();

    virtual inline void unlock_one();
    virtual inline void unlock_two();
public:
    void setInitialCounter(uint32_t c);
    void setOutsideData(void* data);
    void start();
    void join_all();
};
#endif //UNCOUPLED_UNCOUPLED_H
