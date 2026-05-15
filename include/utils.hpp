#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

#define DELIMITER ';'
#define WHERE_COLUMN_NAME_INDEX 0
#define WHERE_VALUE_INDEX 1

bool in(char value, std::vector<int> vector);
bool check_correct_value_type(std::string value, std::string column_type);
std::string trim_string(std::string string);
bool check_keyword(std::string word);

#endif // UTILS_HPP