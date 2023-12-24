#ifndef __PEGAITIVARN_MENU_
#define __PEGAITIVARN_MENU_
#include <string>
#include <vector>
#include <iostream>
#include <functional>

/**
* This menu helper make life a little bit easier in the future. 
* one menu class should be able to run on multiple platforms and environments.
* The goal is to extend this class not the code part that uses this.
*/

namespace pegaitivarn_menu { 
struct Point { 
    /** 
     * The function that will called after if the menu point chosen
     */
    std::function<void()> func;
    /**
     * Don't confuse that not a simple key code,
     * can be a command as well. That represents
     * the menu point call signal.
     */
    std::vector<std::string> key;
    /**
     * The name is the simple visible text.
     * Until we implement the i18n.
     */
    std::string name;
};


class Menu {
  public:
    /**
     * Adding a menu point. It has 2 ways using a 
     * menu point struct or with 3 variables.
     * Later we may a pointer support for the dynamic menus.
     * That is not supported for now. 
     */
    void add(
      std::function<void()> func,
      std::string key, 
      std::string name
    ){
        pegaitivarn_menu::Point menu_point = {
          func,
          {key},
          name
        };
        this->menu_points.push_back(menu_point);
    };
    void add(
      std::function<void()> func,
      std::vector<std::string> key, 
      std::string name
    ){
        pegaitivarn_menu::Point menu_point = {
          func,
          key,
          name
        };
        this->menu_points.push_back(menu_point);
    };
    void add(
      pegaitivarn_menu::Point menu_point
    ){
        this->menu_points.push_back(menu_point);
    };
    /**
     * The render function is rendering the menu. 
     * We have the simple iostream stdio CLI style
     * render at the moment but the main goal is to
     * support ncurses, tk, SDL, and Vulkan as well.
     */
    void render(){
        for(uint8_t i = 0; this->menu_points.size() > i; i++)
            std::cout <<
              this->menu_points[i].key <<
              " - " << 
              this->menu_points[i].name <<
              std::endl;
        std::cin >> this->pressed;
        for (uint8_t i = 0; this->menu_points.size() > i; i++)
            if (this->pressed == this->menu_points[i].key){
                tHIs->menu_points[i].func();
                break;
            }
    };
  private:
    std::vector<Point> menu_points;
    std::string pressed;
};
}
#endif
