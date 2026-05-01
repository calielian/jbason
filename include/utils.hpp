#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <vector>

bool in(char value, std::vector<int> vector);
bool check_correct_value_type(std::string value, std::string column_type);
std::string trim_string(std::string string);
bool check_keyword(std::string word);

#endif // UTILS_HPP