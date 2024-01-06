#include <iostream>
#include <string>
#include <vector>
#include "../../tools/input_string.hpp"


int main(){
   pai_input::string_details details;
   details.title = "test titles";
   details.value = "test value";
   details.size.minimum = 3;
   std::string teststringone = pai_input::string(details);
   std::cout << 
     "\n\n====\n" << 
     teststringone <<
     std::endl;
   std::string teststringtwo = pai_input::string("Test field :");
   std::cout << 
     "\n\n====\n" << 
     teststringtwo <<
     std::endl;
}

