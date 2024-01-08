#include <iostream>
#include <string>
#include <vector>
#include "../../../tools/random/string.hpp"


int main(){
   std::string teststring = pai_random::string(10);
   std::cout << 
     "\n\n====\n" << 
     teststring <<
     std::endl;
}

