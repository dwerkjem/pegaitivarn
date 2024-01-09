#include <iostream>
#include <memory>
#include "../../buffer/salted_serial.hpp"

int main(){
    std::shared_ptr<
      pai_buffer::SaltedSerial
    > serial (new pai_buffer::SaltedSerial());
    std::cout << serial->get() << std::endl;
    serial->set(10);
    std::cout << serial->get() << std::endl;
    return 0;
}
