//
// Created by cacoethes on 9/20/20.
//

#ifndef PERFORMANCEEXPERIMENT_COUPLEDTHREADOOP_H
#define PERFORMANCEEXPERIMENT_COUPLEDTHREADOOP_H
#include <CoupledThread.h>

class CoupledThreadOOP: public CoupledThread {
private:
    uint32_t m_counter = 0;
    void FirstThreadFunc() override ;
    void SecondThreadFunc() override ;
    void shortFunc(void *data) override;
    //inline void unlock() noexcept ;
    //inline void lock() noexcept ;
public:
    CoupledThreadOOP();
    CoupledThreadOOP(CtPropertyFlag flag);


};


#endif //PERFORMANCEEXPERIMENT_COUPLEDTHREADOOP_H
