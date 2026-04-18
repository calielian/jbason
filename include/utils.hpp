#ifndef UTILS
#define UTILS

#include <string>
#include <vector>
#include <map>

#define DELIMITER ';'

std::string trim_string(std::string string);
bool check_keyword(std::string word);
// a vector of dictionarys (maps) with a string as a key and a vector of strings as a value
std::vector<std::map<std::string, std::vector<std::string>>> parse_command(std::string command);

#endif // UTILS