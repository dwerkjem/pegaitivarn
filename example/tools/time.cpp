#include <iostream>
#include <string>
#include "../../tools/time.hpp"

int main(){
    std::cout << pai_time::stamp() << std::endl;
    std::cout << pai_time::outdated(pai_time::stamp()) << std::endl;
    std::cout << pai_time::stamp() << std::endl;
};
