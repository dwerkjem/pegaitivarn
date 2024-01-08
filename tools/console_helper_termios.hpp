#ifndef __PEGAITIVARN_CONSOLE_HELPER_TERMIOS_
#define __PEGAITIVARN_CONSOLE_HELPER_TERMIOS_
#include <atomic>
#include <chrono>
#include <thread>
#include <cstdio>
#include <string>
#include <iostream>
#include <ctype.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

namespace pai_console_helper { 
class Termios {
  public:
    bool check(){
        return this->has_new;
    };
    void die(const char *s) {
        perror(s);
        exit(1);
    };
    void disableRawMode() {
        if (!this->raw_mode)
            return ;
        if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &this->orig_termios) == -1)
            this->die("tcsetattr");
        this->raw_mode = false;
    };
    void enableRawMode() {
        if (this->raw_mode)
            return ;
        if (tcgetattr(STDIN_FILENO, &this->orig_termios) == -1) 
            this->die("tcgetattr");
        raw = orig_termios;
        this->raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
        this->raw.c_oflag &= ~(OPOST);
        this->raw.c_cflag |= (CS8);
        this->raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
        this->raw.c_cc[VMIN] = 0;
        this->raw.c_cc[VTIME] = 1;
        if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
            this->die("tcsetattr");
        this->raw_mode = true;
    };
    void start(){
        this->key = '\0';
        this->enableRawMode();
        this->loop();
    };
    void stop(){
        this->disableRawMode();
        this->to_stop = true;
    };
    char get(){
        this->has_new = false;
        return this->key;
    };
    void print(std::string plus){
        this->has_new_print = true;
        this->out = plus;
        this->printOut();
    };
  private:
    void loop(){
        while (1) {
            char c = '\3';
            if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
                die("read");
            if (
                !iscntrl(c) ||
                c == 13
            ) {
                this->has_new = true;
                this->key = c;
            }
            if(this->to_stop == true)
                break;
            this->ser++;
        }
    };
    void printOut(){
        if ( this->has_new_print == false )
            return ;
        this->disableRawMode();
        std::cout << this->out.c_str() << std::flush;
        this->has_new_print = false;
        this->enableRawMode();
    };
    int ser = 0;
    char key = '\0';
    bool to_stop = false;
    bool has_new = false;
    bool has_new_print = false;
    bool raw_mode = false;
    std::string out = "level";
    struct termios orig_termios;
    struct termios raw;
};
}
#endif
