#include <iostream>
#include <memory>
#include <map>
#include "../../../virtual/casino/roulett_wheels.hpp"


int main(){
    std::shared_ptr<
      casino_roulette::Wheel
    > wheel (new casino_roulette::Wheel("two zero"));

    std::shared_ptr<
      casino_roulette::Wheel
    > wheelCustom (new casino_roulette::Wheel({
      "work", "eat", "sleep"
    }));

    std::cout <<
      std::endl <<
      "spin a little:" <<
      std::endl;
    for (int i{0}; i < 10; i++)
        std::cout << wheel->spin() << std::endl;

    std::cout <<
      std::endl <<
      "check history:" <<
      std::endl;
    std::vector<std::string> history = wheel->history();
    for (int i{0}; i < history.size() ; i++)
        std::cout << history[i] << std::endl;

    std::cout <<
      std::endl <<
      "custom wheel:" <<
      std::endl;
    std::cout << wheelCustom->spin() << std::endl;
    return 0;
}
