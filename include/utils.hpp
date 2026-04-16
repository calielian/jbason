#ifndef UTILS
#define UTILS

#include <string>
#include <vector>
#include <utility>

#define DELIMITER ';'

bool check_keyword(std::string);
std::vector<std::pair<std::string, std::string>> parse_command(std::string);

#endif // UTILS