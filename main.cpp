#include "LongArithmetic.hpp"
#include <iostream>
#include <time.h>

int main() {
    std::cout<<"Accuracy of Pi: ";
    int accuracy = 0;
    std::cin >> accuracy;
    clock_t time1 = clock();
    LongNumber Pi;
    LongNumber k;
    LongNumber k8;
    LongNumber k_16("1");
    for(int i = 0; i < 200; i ++) {
        k8 = k * LongNumber("8");
        Pi = Pi + k_16 * (LongNumber("4") / (k8 + LongNumber("1")) - LongNumber("2") / (k8 + LongNumber("4"))
         - LongNumber("1") / (k8 + LongNumber("5")) - LongNumber("1") / (k8 + LongNumber("6")));
        k_16 = k_16 / LongNumber("16");
        k = k + LongNumber("1");
    }
    clock_t time2 = clock();
    double time = 1000.0 * (time2 - time1) / CLOCKS_PER_SEC;
    std::cout<<"\n"<<(Pi.rounding(accuracy)).LongNumber_to_str()<<"\n";
    std::cout<<"Used time: "<< time << " ms";
    return 0; 
}