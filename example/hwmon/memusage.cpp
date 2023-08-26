#include <iostream>
#include "../../hwmon/memusage.hpp"

int main(){
    pegaitivarn_memusage::update();
    std::cout << pegaitivarn_memusage::mem_usage << std::endl;
    return 0;
}
