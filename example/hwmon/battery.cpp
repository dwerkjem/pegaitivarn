#include <memory>
#include <vector>
#include "../../hwmon/battery.hpp"

int main(){
    std::vector<double> batts;
    std::shared_ptr<pegaitivarn_battery::Reader> batt (new pegaitivarn_battery::Reader());
    batt->discovery();
    batt->refresh();
    batts = batt->getAll();
    for (int i{0}; i < batts.size(); i++)
        std::cout << batts[i] << std::endl;
}
