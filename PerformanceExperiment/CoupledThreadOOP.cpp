//
// Created by cacoethes on 9/20/20.
//

#include <iostream>
#include "CoupledThreadOOP.h"
#include "globalMacro.h"

CoupledThreadOOP::CoupledThreadOOP() : CoupledThread(){

}

CoupledThreadOOP::CoupledThreadOOP(CtPropertyFlag flag) : CoupledThread(flag) {

}

void CoupledThreadOOP::FirstThreadFunc() {
    static int mock;
    while (m_counter < TRIAL_COUNT) {

        m_counter++;
        mock = 1+2;
//        (m_counter%7) || (unlock_one(),1);
        if (!(m_counter % 7)) {
            lock_two();
            unlock_one();
            // unlokcount++;
        }
        mock = 1+2;
        mock += 2+3;
        mock -= 3+5;
    }

}

void CoupledThreadOOP::SecondThreadFunc() {
    static int mock;
    static uint32_t limit = (TRIAL_COUNT/7)*7;
    for(;;) {
        lock_one();
        m_counter--;
        m_counter++;
        unlock_two();
        if(m_counter >= limit){
            break;
        }
        mock = 1+2;
    }
}

void CoupledThreadOOP::shortFunc(void *data) {
    static timespec Spec = {0,7};
    nanosleep(&Spec, nullptr);
}
