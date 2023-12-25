#ifndef __PEGAITIVARN_INPUT_STRING_
#define __PEGAITIVARN_INPUT_STRING_
#include <string>

/**
* 
*/

namespace pegaitivarn_input { 
std::string string (std::string title){
    std::string out;
    std::cout << 
      title << 
      " ";
    std::cin >> out;
    return out;
}
}
#endif
