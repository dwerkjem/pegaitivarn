#ifndef __PEGAITIVARN_BUFFER_ONETIMEPIN
#define __PEGAITIVARN_BUFFER_ONETIMEPIN
#include <iostream>
#include <string>
#include <tuple>
#include <random>
#include <map>
#include <ctime>

namespace pai_buffer{

struct Pin{
    std::string pin;
    int64_t timeout;
    bool used = false;
};


class OneTimePin{
 private: 
   int _timeout = 15; 
   std::map<std::string, Pin> _buffer;
   int64_t timestamp (){
       return static_cast<int64_t>(std::time(0));
   }
 public:
   bool check(std::string id, std::string pass){
       if ( !this->_buffer.contains(id) ){
           return false;
       }
       if (
           this->_buffer[id].pin == pass &&
           this->_buffer[id].timeout > this->timestamp() &&
           this->_buffer[id].used == false
        ){
           this->_buffer[id].used = true;
           return true;
       }
       return false;
   };
   std::string get(std::string id){
       Pin out;
       int number; 
       std::random_device dev;
       std::mt19937 rng(dev());
       std::uniform_int_distribution<
         std::mt19937::result_type
       > random(0,(999999));
       number = random(rng);
       out.pin = std::to_string(number);
       out.pin.insert(out.pin.begin(), 6 - out.pin.length(), '0');
       int64_t t = this->timestamp();
       out.timeout = (t + (this->_timeout * 60));
       this->_buffer[id] = out;
       return out.pin;
   };  
};

}
#endif
