#include "../include/utils.hpp"
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <map>

std::string trim_string(std::string string) {
    std::string string_trimmed { "" };
    int index_start = 0, index_end = string.length() - 1;

    // gets the index of the first character non-space
    // (removes spaces from the start of the string)
    for (char character : string) {
        if (character != ' ') break;
        else index_start++;
    }

    // gets the index of the last character non-space
    // (removes spaces from the end of the string)
    for (int i = index_end; i > index_start; i--) {
        if (string[i] == ' ') index_end--;
        else break;
    }

    // adds all character in the range of index_start to index_end
    for (int i = index_start; i <= index_end; i++) string_trimmed += string[i];

    return string_trimmed;
}

bool check_keyword(std::string word) {
    if (word == "FROM" || word == "SELECT" || word == "WHERE") return true;
    else return false;
}

std::vector<std::map<std::string, std::vector<std::string>>> parse_command(std::string command) {
    std::stringstream ss {command};

    std::vector<std::string> command_splited;

    while (std::getline(ss, command, DELIMITER)) command_splited.push_back(trim_string(command) + ' ');

    std::vector<std::map<std::string, std::vector<std::string>>> command_parsed;

    // gets every partition to partition again and store them in a pair, to adds to command_parsed vector
    for (std::string partition : command_splited) {
        std::string temp { "" }, key;
        std::map<std::string, std::vector<std::string>> map;
        std::vector<std::string> values;
        bool first_element = true;
    
        std::cout << "partition: " << '\'' << partition << '\'' << std::endl;

        for (int i = 0; i < partition.length(); i++) {
            char character = partition[i];
            temp += character;

            if (character == ' ') {
                temp.pop_back();

                if (first_element) {
                    key = temp;
                    first_element = false;
                } else values.push_back(temp);
                
                std::cout << "Temp: " << '\'' << temp << '\'' << std::endl;
                temp = "";
            }
        }

        map[key] = values;

        command_parsed.push_back(map);
    }

    

    // checks if very value is not empty or if key of the map contains a valid keyword
    for (auto map : command_parsed) {
        for (auto iterator = map.begin(); iterator != map.end(); iterator++) {
            if (iterator->second.empty()) return {};
            else if (!check_keyword(iterator->first)) return {};
        }
    }

    return command_parsed;
}
