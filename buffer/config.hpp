#ifndef __PEGAITIVARN_BUFFER_CONFIG
#define __PEGAITIVARN_BUFFER_CONFIG
#include <string>
#include <vector>
#include <map>


namespace pai_buffer {
    class Config {
      public:
        ~Config(){
            this->db.clear();
        };
        std::string get (const std::string name){
            return this->db[name];
        };
        std::string get (const std::string name, std::string def){
            if(this->db[name] == "")
               return def;
            return this->db[name];
        };
        int getInt (const std::string name){
            if(this->db[name] == "")
               return 0;
            return std::stoi(this->db[name]);
        };
        int getInt (const std::string name, const int def){
            if(this->db[name] == "")
               return def;
            return std::stoi(this->db[name]);
        };
        void set (
          const std::string name,
          const std::string val
        ){
            this->db[name] = val;
        };
        void map (
            std::map<std::string, std::string> map_
        ){
            for(auto const & [name, val] : map_){
                this->set(
                    name,
                    val
                );
            }
        };
        std::map<std::string, std::string> map(){
            std::map<std::string, std::string> out;
            for(auto const & [name, val] : this->db)
                out[name] = val;
            return out;
        };
      private:
        std::map<std::string, std::string> db;
    };
};

#endif
