#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "../../tools/menu.hpp"


void println(std::string text) {
    std::cout << 
      "\n\n====\n" << 
      text <<
      "\n====\n" <<
      std::endl;
}

int main(){
    std::shared_ptr<
      pai_menu::Menu
    > menu {new pai_menu::Menu()};
    menu->add(
      [](){
        println("test 1");
      },
      "1",
      "test 1"
    );
    menu->add(
      [](){
        println("test 2");
      },
      std::vector<std::string> {"2"},
      "test 2"
    );
    pai_menu::Point third = {
      [](){
        println("test 3");
      },
      std::vector<std::string> {"3"},
      "test 3"
    };
    menu->add(
        third
    );
    menu->render();
    println("go to loop");
    menu->add(
      [menu](){
        menu->quit();
        println("quit!");
      },
      std::vector<std::string> {"q"},
      "quit"
    );
    menu->loop();
}
