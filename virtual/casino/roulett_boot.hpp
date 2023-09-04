#include <string>
#include <map>
#include "roulett_types.hpp"

namespace casino_roulette{
void bootstrap(){
    for (int i = 1; i < 37; ++i)
        g_values[std::to_string(i)] = i;

};
}

