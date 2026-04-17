#include "include/utils.hpp"
#include <ncurses.h>
#include <string>
#include <utility>
#include <iostream>


int main() {

    std::string test = "FROM table; ";

    auto command_parsed = parse_command(trim_string(test));

    for (auto pair : command_parsed) {
        for (auto pair_item : command_parsed) {
            std::cout << pair_item.first << std::endl;
            std::cout << pair_item.second << std::endl;
        }
    }

    return 0;
}