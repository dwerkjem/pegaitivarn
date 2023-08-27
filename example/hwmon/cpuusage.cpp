#include <chrono>
#include <thread>
#include <iostream>
#include "../../hwmon/cpuusage.hpp"

int main(){
    pegaitivarn_cpuusage::update(); 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    pegaitivarn_cpuusage::update();
    std::cout << pegaitivarn_cpuusage::cpu_usage << std::endl;
    return 0;
}
