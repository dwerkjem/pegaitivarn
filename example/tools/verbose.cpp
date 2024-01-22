#include "../../tools/verbose.hpp"


int main() {
    pai_verbose::level = 4;
    pai_verbose::msg(
      "not visible debug",
      "example",
      6
    );
    pai_verbose::msg(
      "visible debug",
      "example",
      3
    );

}
