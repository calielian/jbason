#include "include/utils.hpp"
#include <ncurses.h>
#include <string>
#include <utility>
#include <iostream>


int main() {

    std::string test = "FROM table; ";

    auto command_parsed = parse_command(trim_string(test));

    for (auto pair : command_parsed) {
        for (auto map : command_parsed) {
            for (auto it = map.begin(); it != map.end(); it++){
                std::cout << "Key:" << '\'' << it->first << '\'' << std::endl;

                for (std::string value : it->second) {
                    std::cout << "Values:" << '\'' << value << '\'' << std::endl;
                }
            }
        }
    }

    return 0;
}