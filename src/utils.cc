#include "../include/utils.hpp"
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

bool check_keyword(std::string word) {
    if (word == "FROM" || word == "SELECT" || word == "WHERE") return true;
    else return false;
}

std::vector<std::pair<std::string, std::string>> parse_command(std::string command) {
    std::stringstream ss {command};

    std::vector<std::string> command_splited;

    while (std::getline(ss, command, DELIMITER)) command_splited.push_back(command + ' ');

    std::vector<std::pair<std::string, std::string>> command_parsed;

    for (std::string partition : command_splited) {
        std::string temp { "" };
        std::pair<std::string, std::string> pair { "", "" };
        bool first_element = true;
        std::cout << "partition: " << '\'' << partition << '\'' << std::endl;

        for (int i = 0; i < partition.length(); i++) {
            char character = partition[i];
            temp += character;
            if (character == ' ') {
                temp.pop_back();
                if (first_element) pair.first = temp;
                else pair.second = temp;
                first_element = false;
                std::cout << "Temp: " << temp << std::endl;
                temp = "";
            }
        }

        std::cout << "pair.first: " << pair.first << std::endl;
        std::cout << "pair.second: " << pair.second << std::endl;

        command_parsed.push_back({pair.first, pair.second});
    }

    for (auto pair : command_parsed) {
        std::cout << "pair.first check: " << pair.first << std::endl;
        std::cout << "pair.second check: " << pair.second << std::endl;
        if (pair.second == "") return {};
        else if (!check_keyword(pair.first)) return {};
    }

    return command_parsed;
}
