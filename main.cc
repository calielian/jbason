#include "include/utils.hpp"
#include <ncurses.h>
#include <string>
#include <utility>
#include <iostream>


int main() {

    std::string test = "FROM table; SELECT column; WHERE column = value; ";

    auto command_parsed = parse_command(trim_string(test));

    if (command_parsed.empty()) {
        std::cout << "Command parsed is empty" << std::endl;
    }

    for (auto it = command_parsed.begin(); it != command_parsed.end(); it++) {
        std::cout << "Key:" << '\'' << it->first << '\'' << std::endl;

        for (std::string value : it->second) {
            std::cout << "Values:" << '\'' << value << '\'' << std::endl;
        }
    }

    return 0;
}