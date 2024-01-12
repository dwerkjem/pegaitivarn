#ifndef __PEGAITIVARN_INI_HPP_
#define __PEGAITIVARN_INI_HPP_
#include <algorithm> 
#include <cctype>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "../text/trim.hpp"


namespace pai_ini{

struct ini_line {
    bool success = false;
    std::string section;
    std::string key;
    std::string value;
};

class ProcessorClass { 
  private:
    std::string section_name;
    std::map<std::string, std::map<std::string, std::string>> db;
    ini_line splitter (std::string &input_){
        ini_line out;
        int i;
        int size = input_.size();
        if(
          input_[0] == '=' &&
          input_[0] == '#'
        )
            return out;
        if(
          input_[0] == '['
        ){
            this->sectionNameRead(input_);
            return out;
        }
        for(i = 0; size > i ; i++)
            if(input_[i] == '=')
               break;
        if (i == size)
            return out;
        out.key = input_.substr(0,i-1);
        out.value = input_.substr(i+1,size);
        out.section = this->section_name;
        pai_text::trim(out.key);
        pai_text::trim(out.value);
        return out;
    };
    void sectionNameRead(std::string &input_){
        int i;
        int size = input_.size();
        for(i = 0; size > i ; i++)
            if(input_[i] == ']')
               break;
        this->section_name = input_.substr(0,i-1);
        pai_text::trim(section_name);
    };
  public:
    void read (std::string &file_name){
         std::string section_name = "default";
         std::string line;
         ini_line one;
         std::ifstream ini_file;
         ini_file.open(file_name);
         while(getline(ini_file, line)){
             one = splitter(line);
             if(one.success == true)
                 this->db[one.section][one.key] = one.value;
         }
    };
    std::map<std::string, std::map<std::string, std::string>> all(){
        return this->db;
    };
    std::map<std::string, std::map<std::string, std::string>> get(
      std::string &section,
      std::string &name
    ){
        return this->db[section][name];
    };

};

pai_ini::ProcessorClass * mainClass = new pai_ini::ProcessorClass();

void read (std::string file_name){
    pai_ini::mainClass->read(file_name);
}; 

std::string get (
  std::string section,
  std::string name
){
    return pai_ini::mainClass->get(section, name);
};

std::map<std::string, std::map<std::string, std::string>> all(){
    return pai_ini::mainClass->all();
};
}

#endif
