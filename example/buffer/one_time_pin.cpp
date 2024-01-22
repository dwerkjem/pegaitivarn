#include <iostream>
#include <memory>
#include "../../buffer/one_time_pin.hpp"

int main(){
    std::shared_ptr<
      pai_buffer::OneTimePin
    > pin (new pai_buffer::OneTimePin());
    std::string p = pin->get("TEST");
    std::cout << p << std::endl;
    std::cout << pin->check("TEST", "123") << std::endl;
    std::cout << pin->check("TEST", p) << std::endl;
    return 0;
}
