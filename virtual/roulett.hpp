namespace roulet{
struct Bet_type { 
    bool even = false;
    bool odd = false;
    bool red = false;
    bool black = false;
    int8_t half = 0;
    int8_t dozen = 0;
    int8_t column = 0;
}

struct Game {
    Bet_type type,
    int8_t id,
}

std::vector<std::string> bet_names {
   "zero",
   "double zero",
   "row",
   "split",
   "street",
   "corner",
   "top line",
   "double street",
   "1st column",
   "2nd column",
   "3rd column",
   "1st dozen",
   "2nd dozen",
   "3rd dozen",
   "odd",
   "even",
   "red",
   "black",
   "one to eightteen",
   "nineteen to thirdysix"
}

struct Number {
    uint16_t id;
    int8_t value;
    std::string name;
    bool odd;
    bool even;
    bool black;
    bool red;
    int8_t colum;
    int8_t dozen;
    int8_t half;
}

struct Table { 
    std::vector<std::string> numbers;
    std::vector<std::string> odds;
    std::vector<std::string> evens;
    std::vector<std::string> reds;
    std::vector<std::string> blacks;
    std::vector<std::vector<std::string>> colums;
    std::vector<std::vector<std::string>> dozens;
    std::vector<std::vector<std::string>> halfs;
}

std::vector<std::string> table_chines_numbers_plus {
    "0",
    "00",
    "0000",
}

std::vector<std::string> table_american_numbers_plus {
    "0",
    "00",
}

std::vector<std::string> table_european_numbers_plus {
    "0",
}
