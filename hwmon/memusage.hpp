#include <cstdlib>
extern "C" {
#include <sys/sysinfo.h>
}


namespace pai_memusage { 
float mem_usage;
struct sysinfo sys_info;
void update(){
    sysinfo(&sys_info);
     mem_usage = 100.00-(100.00*((float)sys_info.freeram/(float)sys_info.totalram));
};
}
