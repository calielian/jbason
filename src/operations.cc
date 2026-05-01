#include "../include/operations.hpp"
#include "../include/utils.hpp"
#include "../lib/json.hpp"
#include <fstream>

#include <iostream>

#define print(msg) std::cout << msg << std::endl

using json = nlohmann::json;

json create_table(std::string path, COMMAND_PARSED_TYPE command) {
    json database;

    if (!path.empty()){
        std::ifstream json_archive { path };
        database = json::parse(json_archive);
    }

    const std::string TABLE_NAME = command["CREATE"][0];

    database[TABLE_NAME]["columns_type"] = command["TYPE"];
    database[TABLE_NAME]["columns_names"] = command["COLUMNS"];

    return database;
}

bool create_database(std::string path, COMMAND_PARSED_TYPE command) {
    std::ofstream json_archive { path };
    json database = create_table("", command);

    if (json_archive.is_open()) {
        json_archive << database.dump(4);
        json_archive.close();
        return true;
    }

    return false;
}

bool insert_table(std::string path, COMMAND_PARSED_TYPE command) {
    std::ifstream json_archive { path };
    json database = json::parse(json_archive);
    std::map<std::string, int> values_and_column_index;

    const std::string TABLE_NAME = command["INSERT_INTO"][0];
    const int VALUES_SIZE = command["VALUES"].size();
    
    for (int i = 0; i < VALUES_SIZE; i++) {
        if (!check_correct_value_type(command["VALUES"][i], database["columns_type"][i])) {
            return false;
        } else {
            values_and_column_index[command["VALUES"][i]] = i;
        }
    }

    for (auto it = values_and_column_index.begin(); it != values_and_column_index.end(); it++) {
        print(database.dump(4));
        // database[TABLE_NAME][database[TABLE_NAME]["columns_name"][it->second]] = it->first;
    }

    return true;
}
