#include "../include/operations.hpp"
#include "../lib/json.hpp"
#include <fstream>

using json = nlohmann::json;

bool check_correct_value_type(std::string value, std::string column_type) {

}

json create_table(std::string path, COMMAND_PARSED_TYPE command) {
    json database;

    if (!path.empty()) database = json::parse(path);

    const std::string TABLE_NAME = command["CREATE"][0];

    database[TABLE_NAME]["columns_type"] = command["TYPE"];
    database[TABLE_NAME]["columns_names"] = command["COLUMNS"];

    return database;
}

bool create_database(std::string path, COMMAND_PARSED_TYPE command) {
    std::ofstream json_archive { path };
    json database = create_table(path, command);

    if (json_archive.is_open()) {
        json_archive << database.dump(4);
        json_archive.close();
        return true;
    }

    return false;
}

void insert_table(std::string path, COMMAND_PARSED_TYPE command) {
    json database = json::parse(path);

    const std::string TABLE_NAME = command["INSERT_INTO"][0];
    const int VALUES_SIZE = command["VALUES"].size();
    
    for (int i = 0; i < VALUES_SIZE; i++) {
        
    }

}
