#include <iostream>
#include <string>
#include <vector>
#include "../../../tools/random/integer.hpp"


int main(){
   int teststring = pai_random::integer(-500, 500);
   std::cout << 
     "\n\n====\n" << 
     teststring <<
     std::endl;
}

