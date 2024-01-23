#ifndef __PEGAITIVARN_INPUT_TEXT_EDITOR_
#define __PEGAITIVARN_INPUT_TEXT_EDITOR_
#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace pai_input { 
std::string generateRandomString(int length) {
    std::string str;
    std::srand(time(nullptr));
    for (int i = 0; i < length; i++) {
        char c = static_cast<char>(rand() % 26 + 'a');
        str += c;
    }
    return str;
};
class TextEditor {
  public:
    void setPath(std::string path){
        this->path = path;
    };
    void setExt(std::string &ext){
        this->extension = ext;
    };
    void setEditor(std::string ed){
        this->editor_cmd = ed;
    };
    std::string editor(
      std::string &text,
      std::string &ext
    ){
        this->setExt(ext);
        return editor(text);
    };
    std::string editor(std::string &text){
        this->fileName();
        this->fileWrite(text);
        this->open();
        std::string out = this->fileRead();
        this->fileRemove();
        return out;
    };
  private:
    std::string path = "/tmp/";
    std::string extension = "txt";
    std::string file_path = "";
    std::string editor_cmd = "vim";

    std::string fileRead (){
        auto ss = std::ostringstream{};
        ss << std::ifstream(this->file_path).rdbuf();
        std::string text =  ss.str();
        return text;
    };
    void fileWrite(
      std::string &text
    ){
        std::ofstream prefile (this->file_path); 
        if (!prefile.is_open())
            return;
        prefile << text;
        prefile.close();
    };
    void fileRemove(){
        std::filesystem::remove(this->file_path);
    };
    void open(){
        std::system(
          (
            this->editor_cmd+
            " "+
            this->file_path
          ).c_str()
        );
    };
    void fileName(){
        this->file_path = (
            this->path+
            cpp_editor_tool::generateRandomString(10)+
            "."+
            this->extension
        );
    };
};
};
#endif
