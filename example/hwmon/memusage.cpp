#include <iostream>
#include "../../hwmon/memusage.hpp"

int main(){
    pai_memusage::update();
    std::cout << pai_memusage::mem_usage << std::endl;
    return 0;
}
