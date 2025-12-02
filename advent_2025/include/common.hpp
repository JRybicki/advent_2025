// SOLUTION_INCLUDES.hpp
#ifndef COMMON
#define COMMON

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> ReadFile(std::string filename, bool print_lines) {

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

#endif // SOLUTION_INCLUDES