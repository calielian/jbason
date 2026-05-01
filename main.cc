#include "include/parse.hpp"
#include "include/utils.hpp"
#include "include/operations.hpp"
#include <ncurses.h>
#include <string>
#include <utility>
#include <iostream>

int main() {

    std::string select_test = "FROM table; SELECT number; WHERE number = 10";
    std::string insert_test = "INSERT_INTO table; VALUES {10, jane_doe, 40}";
    std::string create_test = "CREATE table; TYPE {int, string, int}; COLUMNS { number, name, other_number }";

    std::cout << select_column("/home/calielian/Pessoal/Prog/C++/Apps/jbason/test.json", parse_command(trim_string(select_test))) << std::endl;

    // std::cout << insert_table("/home/calielian/Pessoal/Prog/C++/Apps/jbason/test.json", parse_command(trim_string(insert_test))) << std::endl;

    // std::cout << create_database("/home/calielian/Pessoal/Prog/C++/Apps/jbason/test.json", parse_command(trim_string(create_test))) << std::endl;

    /*
    auto command_parsed = parse_command(trim_string(select_test));
    
    if (command_parsed.empty()) {
        std::cout << "Command parsed is empty" << std::endl;
    }

    for (auto it = command_parsed.begin(); it != command_parsed.end(); it++) {
        std::cout << "Key:" << '\'' << it->first << '\'' << std::endl;

        for (std::string value : it->second) {
            std::cout << "Values:" << '\'' << value << '\'' << std::endl;
        }
    }
    */
    return 0;
}