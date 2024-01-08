#ifndef __PEGAITIVARN_RANDOM_STRING_
#define __PEGAITIVARN_RANDOM_STRING_
#include <string>
#include "integer.hpp"


namespace pai_random { 
std::string string(int length) {
    std::string str;
    std::srand(time(nullptr));
    for (int i = 0; i < length; i++) {
        char c = static_cast<char>(
          pai_random::integer(
            static_cast<int>(97),
            static_cast<int>(122)
          )
        );
        str += c;
    }
    return str;
};
}
#endif
