#include <string>
#include <tuple>
#include <map>
#include <ctime>

namespace buffers{

class oneTimePine{
 private: 
   int _timeout = 15; 
   std::map<std::string, std::tuple<std::string, int, int>> _buffer;
 public:
   bool std::check(std::string id, std::string pass){
       if ( this->_buffer.contains(id) ){
           return false;
       }
       if ( std::get<0>(this->_buffer[id]) == pass ){
           return true;
       }
       return false;
   };
   std::string get(std::string id){
       int number; 
       std::random_device dev;
       std::mt19937 rng(dev());
       std::uniform_int_distribution<
         std::mt19937::result_type
       > random(0,(999999));
       number = random(rng);
       std::string out = std::to_string(number);
       int size = out.size();
       out.insert(out.begin(), 20 - out.length(), '0');
       std::time_t t = std::time(0);
       int timeout = (t + (this->_timeout * 60));
       this->_buffer[id] = {out, timeout, 0};
       return out
   }  


}

