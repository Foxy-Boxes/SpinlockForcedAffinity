//
// Created by cacoethes on 9/21/20.
//

#include <zconf.h>
#include "UncoupledOOP.h"
#include "globalMacro.h"
void UncoupledOOP::FirstThreadFunc() {
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

void UncoupledOOP::SecondThreadFunc() {
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

void UncoupledOOP::shortFunc(void *data) {
    static timespec Spec = {0,2};
    nanosleep(&Spec, nullptr);
}
