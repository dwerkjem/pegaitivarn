#ifndef __PEGAITIVARN_INPUT_INTEGER_
#define __PEGAITIVARN_INPUT_INTEGER_
#include <string>
#include "input_limits.hpp"
#include "input_string.hpp"

/**
* cin based not raw integer input fields. 
* for usage example check the: 
* example/tools/input_integer.cpp
*/

namespace pai_input { 

struct integer_details{
    std::string title = " ";
    int32_t value = 0;
    pai_input::number_limits size;
};

bool integerCheck(
  int32_t value,
  std::string original,
  pai_input::integer_details details
){
    // valid number check 
    if(
      std::to_string(
        strtol(original.c_str(), NULL, 0)
      ) != original &&
      original != "."
    )
       return false;
    // limit check 
    if(
      value > details.size.maximum ||
      value < details.size.minimum 
    )
        return false;
    return true;
};

int32_t integerToDefault(
  std::string value,
  pai_input::integer_details details
){
    if(
      value == "."
    ){
        return details.value;
    }
    return strtol(value.c_str(), NULL, 0);
};

int32_t integer(std::string title, int32_t value){
    return strtol(
      (pai_input::string(
        title,
        std::to_string(value)
      )).c_str(), NULL, 0
    );
};

int32_t integer(std::string title){
    return pai_input::integer(
      title,
      0
    );
};

int32_t integer (pai_input::integer_details details){
    bool failed {true};
    int32_t out;
    std::string temp;
    while (failed){
        temp = pai_input::string(
          details.title,
          std::to_string(details.value)
        );
        out = integerToDefault(
          temp,
          details
        );
        failed = (!pai_input::integerCheck(
          out, 
          temp,
          details
        ));
    }
    return out;
};

}
#endif
