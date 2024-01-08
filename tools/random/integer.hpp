#ifndef __PEGAITIVARN_RANDOM_INTEGER_
#define __PEGAITIVARN_RANDOM_INTEGER_
#include <cstdlib>
#include <random>
#include <time.h>
#include <thread>
#include <string>


namespace pai_random { 
int integer(const int min, const int max){
    thread_local std::random_device rd;
    thread_local std::mt19937 rng(rd());  
    thread_local std::uniform_int_distribution<int> uid;
    return uid(rng, decltype(uid)::param_type{min,max});
};
}
#endif
