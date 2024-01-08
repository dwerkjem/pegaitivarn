#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <functional>
#include "../../tools/console_helper_termios.hpp"

int main() {
    char last;
    std::shared_ptr<
    pai_console_helper::Termios
    > cli {new pai_console_helper::Termios()};
    std::thread t([cli](){
        cli->start();
    });
    t.detach();
    while(1){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if( cli->check() == false )
            continue;
        last = cli->get();
        if (last == 'q')
            break;
        cli->print(std::string(1, last));
    }
    cli->stop();
    return 0;
}
