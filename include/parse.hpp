#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>
#include <vector>
#include <map>

#define COMMAND_PARSED_TYPE std::map<std::string, std::vector<std::string>>

COMMAND_PARSED_TYPE parse_command(std::string command);
COMMAND_PARSED_TYPE parse_insert(std::vector<std::string> command);
COMMAND_PARSED_TYPE parse_create(std::vector<std::string> command);

#endif // PARSE_HPP