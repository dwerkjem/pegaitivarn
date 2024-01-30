#include <map>
#include <string>
#include <iostream>
#include <memory>
#include "../../buffer/config.hpp"

int main(){
    std::shared_ptr<
      pai_buffer::Config
    > config (new pai_buffer::Config());
    config->set("TEST", "test");
    std::cout << config->get("TEST") << std::endl;
    std::cout << config->get("TEST_2", "Empty") << std::endl;
    config->set("TEST_2", "Not Empty");
    std::cout << config->get("TEST_2", "Empty") << std::endl;
    config->map({
       {"MAP_1", "Map 1"},
       {"MAP_2", "Map 2"}
    });
    std::cout << config->get("MAP_2", "Empty") << std::endl;
    return 0;
}
