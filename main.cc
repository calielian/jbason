#include "include/utils.hpp"
#include <ncurses.h>
#include <string>
#include <utility>
#include <iostream>


int main() {

    std::string test = "FROM table;";
    std::cout << "Teste" << std::endl;

    auto command_parsed = parse_command(test);

    for (auto pair : command_parsed) {
        for (auto pair_item : command_parsed) {
            std::cout << pair_item.first << std::endl;
            std::cout << pair_item.second << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}