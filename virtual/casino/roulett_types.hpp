#include <vector>
#include <string>
#include <map>
#include <atomic>

namespace casino_roulette{

struct Type_collector {
    std::vector<std::string> wheel_order;
    std::vector<std::string> collection;
    std::map<std::string, int> values;
    std::vector<std::string> names;
}

std::map<std::string, int> g_values {
    {"0", 0},
    {"00", 0},
    {"000", 0},
    {"bone", 88},
};

std::vector<std::string> g_names;

std::atomic_int g_serial {0}; 

}
