#include <iostream>
#include "CoupledThreadOOP.h"
#include "UncoupledOOP.h"
void TestCoupled();
void TestUncoupled();
int main() {
    std::cout << "Hello, World!" << std::endl;

//    TestCoupled();
    TestUncoupled();


//coupledThreadOop.showCount();
    return 0;
}

void TestCoupled() {
    CoupledThreadOOP coupledThreadOop(CT_STARTS_RELEASED | CT_PRIORITY_FIRST);

    auto t_start = std::chrono::high_resolution_clock::now();

    coupledThreadOop.start(2);

    coupledThreadOop.join_all();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << "Elapsed Time : " <<std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms" <<std::endl;
}
void TestUncoupled() {
    UncoupledOOP uncoupledOop;
    uncoupledOop.setInitialCounter(3);
    auto t_start = std::chrono::high_resolution_clock::now();

    uncoupledOop.start();

    uncoupledOop.join_all();
    auto t_end = std::chrono::high_resolution_clock::now();

    std::cout << "Elapsed Time : " <<std::chrono::duration<double, std::milli>(t_end-t_start).count()
              << " ms" <<std::endl;
}
