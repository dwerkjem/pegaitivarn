#include <iostream>
#include <string>
#include <vector>
#include "../../tools/input_integer.hpp"


int main(){
   pai_input::integer_details details;
   details.title = "test titles";
   details.value = -2;
   details.size.minimum = -2;
   details.size.maximum = 255;
   int32_t testone = pai_input::integer(details);
   std::cout << 
     "\n\n====\n" << 
     testone <<
     std::endl;
   int32_t testtwo = pai_input::integer("Test field");
   std::cout << 
     "\n\n====\n" << 
     testtwo <<
     std::endl;
   return 0;
}

