// SOLUTION_INCLUDES.hpp
#ifndef COMMON
#define COMMON

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static std::vector<std::string> ReadFile(std::string filename, bool print_lines) {

    std::vector<std::string> file_contents;
    std::ifstream input_file(filename);

    // Check if the file was opened successfully
    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return file_contents;
    }

    std::string line;

    // Read the file line by line
    while (std::getline(input_file, line)) {
        file_contents.push_back(line);
    }

    // Close the file stream
    input_file.close();

    // Optional: Print all stored lines
    if (print_lines) {
        for (const std::string& line : file_contents) {
            std::cout << line << std::endl;
        }
    }
    return file_contents;
}

static std::vector<std::string> ReadCSV(std::string filename, bool print_csv_values) {

    std::vector<std::string> csv_values;

    // Assume there's only a single line for now
    std::string csv_line = ReadFile(filename, false).back();

    std::vector<std::string> tokens;
    std::stringstream ss(csv_line);
    std::string token;

    while (std::getline(ss, token, ',')) {
        if (print_csv_values) {
            std::cout << token << std::endl;
        }
        csv_values.push_back(token);
    }

    return csv_values;
}

#endif // SOLUTION_INCLUDES