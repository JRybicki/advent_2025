#include "common.hpp"
#include "solution_includes.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>


void day4_part1_function(std::string filename) {
    unsigned int total_joltage = 0;
    std::vector<std::string> file_lines = ReadFile(filename, false);

    for (std::string line : file_lines) {


    }
}


void day4_part2_function(std::string filename) {

}


void day4_main() {
    day4_part1_function("inputs/day4_example.txt");
    // std::cout << "Day 4 part 1 example max joltage = " << day4_part1_function("inputs/day4_example.txt") << std::endl;
    // std::cout << "Day 4 part 1 puzzle invalid id sum = " << day4_part1_function("inputs/day4_puzzle.txt") << std::endl;

    // std::cout << "Day 4 part 2 example invalid id sum = " << day4_part2_function("inputs/day4_example.txt") << std::endl;
    // ::cout << "Day 4 part 2 puzzle invalid id sum = " << day4_part2_function("inputs/day4_puzzle.txt") << std::endl;
}
