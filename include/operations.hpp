#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <string>
#include <map>
#include <vector>
#include "../lib/json.hpp"

#define COMMAND_PARSED_TYPE std::map<std::string, std::vector<std::string>>

using json = nlohmann::json;

json create_table(std::string path, COMMAND_PARSED_TYPE command);
bool create_database(std::string path, COMMAND_PARSED_TYPE command);

bool insert_table(std::string path, COMMAND_PARSED_TYPE command);

#endif // OPERATIONS_HPP