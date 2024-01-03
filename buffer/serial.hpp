#ifndef __PEGAITIVARN_BUFFER_SERIAL
#define __PEGAITIVARN_BUFFER_SERIAL
#include <atomic>
#include <iostream>
#include <thread>
#include <vector>


namespace pai_buffer{

class Serial{
  private:
     std::atomic_ullong _serial = 0;
  public:
    unsigned long long int get(){
        this->_serial++;
        return (unsigned long long int) this->serial;
    };
    bool set(
        const unsigned long long int number
    ){
        this->_serial = number;
        return true;
    };
    unsigned long long int current(){
        return (unsigned long long int) this->_serial;
    }
}

}
#endif
