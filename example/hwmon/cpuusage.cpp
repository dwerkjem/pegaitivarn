#include <chrono>
#include <thread>
#include <iostream>
#include "../../hwmon/cpuusage.hpp"

int main(){
    pai_cpuusage::update(); 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    pai_cpuusage::update();
    std::cout << pai_cpuusage::cpu_usage << std::endl;
    return 0;
}
