#include "../include/utils.hpp"
#include <sstream>
#include <string>
#include <utility>
#include <vector>

void parse_command(std::string command) {
    std::stringstream ss {command};

    std::vector<std::string> command_splited;

    while (std::getline(ss, command, DELIMITER)) command_splited.push_back(command);

    std::vector<std::pair<std::string, std::string>> command_parsed;

    for (std::string partition : command_splited) {
        std::string temp { "" };
        std::pair<std::string, std::string> pair;
        bool first_element = true;

        for (char character : partition) {
            if (character != ' ') temp += character;
            else {
                (first_element) ? pair.first = temp : pair.second = temp;
                first_element = false;
            }
        }

        command_parsed.push_back(pair);
    }

    for (auto pair : command_parsed) {
        TODO;
    }
}