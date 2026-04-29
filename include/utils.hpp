#ifndef UTILS
#define UTILS

#include <string>
#include <vector>
#include <map>

#define DELIMITER ';'
#define WHERE_COLUMN_NAME_INDEX 0
#define WHERE_VALUE_INDEX 1

std::string trim_string(std::string string);
bool check_keyword(std::string word);
std::map<std::string, std::vector<std::string>> parse_command(std::string command);
std::map<std::string, std::vector<std::string>> parse_insert(std::vector<std::string> command);
std::map<std::string, std::vector<std::string>> parse_create(std::vector<std::string> command);

#endif // UTILS