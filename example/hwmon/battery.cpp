#include <memory>
#include <vector>
#include "../../hwmon/battery.hpp"

int main(){
    std::vector<double> batts;
    std::shared_ptr<pai_battery::Reader> batt (new pai_battery::Reader());
    batt->discovery();
    batt->refresh();
    batts = batt->getAll();
    for (size_t i{0}; i < batts.size(); i++)
        std::cout << batts[i] << std::endl;
}
