//
// Created by cacoethes on 9/21/20.
//

#ifndef PERFORMANCEEXPERIMENT_UNCOUPLEDOOP_H
#define PERFORMANCEEXPERIMENT_UNCOUPLEDOOP_H
#include <Uncoupled.h>

class UncoupledOOP : public Uncoupled {
private:
    void FirstThreadFunc() override ;
    void SecondThreadFunc() override ;
    void shortFunc(void *data) override;
public:
    uint32_t m_counter;
};


#endif //PERFORMANCEEXPERIMENT_UNCOUPLEDOOP_H
