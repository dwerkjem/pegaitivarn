#include <iostream>
#include "../../buffer/serial.hpp"

int main(){
    std::shared_ptr<
      pai_buffer::Serial
    > serial (new pai_buffer::Serial());
    std::cout << serial->current() << std::endl;
    std::cout << serial->get() << std::endl;
    serial->set(10) <<;
    std::cout << serial->current() << std::endl;
    std::cout << serial->get() << std::endl;
    return 0;
}
