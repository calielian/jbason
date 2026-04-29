#include "include/parse.hpp"
#include <ncurses.h>
#include <string>
#include <utility>
#include <iostream>


int main() {

    std::string select_test = "FROM table; SELECT number; WHERE number = 10";
    std::string insert_test = "INSERT_INTO table; VALUES {1, 2, 3, 4, 5, 6}";
    std::string create_test = "CREATE table; TYPE {int, string, int}; COLUMNS { number, name, other_number }";

    auto command_parsed = parse_command(trim_string(create_test));

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