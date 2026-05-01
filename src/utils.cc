#include "../include/utils.hpp"
#include <vector>

bool in(char value, std::vector<int> vector) {
    for (int value_vector : vector) {
        if (value == value_vector) return true;
    }

    return false;
}

bool check_correct_value_type(std::string value, std::string column_type) {
    std::vector<int> values; 

    if (column_type == "int") {
        for (int i = '0'; i <= '9'; i++) values.push_back(i);

        for (char character : value) {
            if (!in(character, values)) return false;
        }
    }

    return true;
}

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
    if (
        word == "FROM"        ||
        word == "SELECT"      ||
        word == "WHERE"       ||
        word == "INSERT_INTO" ||
        word == "VALUES"      ||
        word == "CREATE"      ||
        word == "TYPE"        ||
        word == "COLUMNS"
    ) return true;
    else return false;
}