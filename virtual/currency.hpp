#include <string>

namespace pegaitivarn_currency{
struct currency{
    std::string code;
    int rate;
};

std::map<string, currency> currencies 
double exchange (
    int amount,
    std::string base_code,
    std::string target_code
){
    return (amount/(currencies[base_code].rate)*currencies[target_code].rate);
};
}
