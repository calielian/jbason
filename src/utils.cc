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
    if (word == "FROM" || word == "SELECT" || word == "WHERE" || word == "INSERT_INTO" || word == "VALUES") return true;
    else return false;
}

std::map<std::string, std::vector<std::string>> parse_command(std::string command) {
    std::stringstream ss {command};

    std::vector<std::string> command_splited;

    while (std::getline(ss, command, DELIMITER)) command_splited.push_back(trim_string(command) + ' ');

    if (command_splited[0].find("INSERT_INTO") != std::string::npos) {
        auto res = parse_insert(command_splited);
        res["_insert_into"] = { "true" };

        return res;
    }

    std::map<std::string, std::vector<std::string>> command_parsed;

    // gets every partition to partition again and store them in command_parsed
    for (std::string partition : command_splited) {
        std::string temp { "" }, key;
        std::vector<std::string> values;
        bool first_element = true;
    
        std::cout << "partition: " << '\'' << partition << '\'' << std::endl;

        for (int i = 0; i < partition.length(); i++) {
            char character = partition[i];
            temp += character;

            if (character == ' ' || character == '=') {
                temp.pop_back();

                if (first_element) {
                    key = temp;
                    first_element = false;
                } else if (!temp.empty()) values.push_back(temp);
                
                std::cout << "Temp: " << '\'' << temp << '\'' << std::endl;
                temp = "";
            }
        }

        command_parsed[key] = values;
    }

    // checks if very value is not empty or if key of the map contains a valid keyword
    for (auto iterator = command_parsed.begin(); iterator != command_parsed.end(); iterator++) {
        if (iterator->second.empty()) return {};
        else if (!check_keyword(iterator->first)) return {};
    }

    return command_parsed;
}

std::map<std::string, std::vector<std::string>> parse_insert(std::vector<std::string> command) {
    std::map<std::string, std::vector<std::string>> command_parsed;
    std::vector<std::string> values_to_insert;
    std::string temp { "" }, key;
    bool first_element = true;
    int index;

    const int VALUES_SIZE = command[1].length();

    for (char character : command[0]) {
        if (character != ' ') {
            temp += character;
        } else {
            if (first_element) {
                key = temp;
                temp = "";
                first_element = false;
            } else {
                command_parsed[key] = { temp };
                temp = "";
                key = "";
            }
        }
    }

    for (index = 0; index < command[1].length(); index++) {
        char character = command[1][index];
        if (character != ' ') {
            temp += character;
        } else {
            index += 2;
            key = temp;
            temp = "";
            break;
        }
    }

    while (index < VALUES_SIZE) {
        if (command[1][index] != ' ' && command[1][index] != ',') {
            values_to_insert.push_back( { command[1][index] } );
        } else if (command[1][index] == '}') {
            command_parsed[key] = values_to_insert;
        }
    }

    return command_parsed;
}
