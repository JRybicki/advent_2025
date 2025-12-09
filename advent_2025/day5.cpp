#include "common.hpp"
#include "solution_includes.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

// can't figure out which ingrediats are fresh or spoiled
// database - contains a list of fresh id ranges
// blank line
// avaliable ingrediant ids

// ranges are inclusive and can overlap
// how many avaliable ingrediants are fresh?

// we can't use sets here because it takes way too much memory
// we'll have to instead just keep track of the ranges
// even more exciting can we try and use ranges?
// range find is SUPER SLOW for this example
// instead we'll just use some boring simple fast code
unsigned long long day5_part1_function(std::string filename) {
    std::vector<std::string> file_lines = ReadFile(filename, false);

    // make a set of the ingrediants
    std::vector<std::pair<unsigned long long, unsigned long long>> fresh_ranges;
    bool fresh_set_done = false;
    unsigned long long num_fresh_ingrediants = 0;

    for (std::string line : file_lines) {
        std::cout << line << std::endl;

        if (line.empty()) {
            fresh_set_done = true;
        }

        if (!fresh_set_done) {
            unsigned int range_index = line.find('-');
            std::string start_id = line.substr(0, range_index);
            std::string end_id = line.substr(range_index + 1);

            unsigned long long start_num = std::atoll(start_id.c_str());
            unsigned long long end_num = std::atoll(end_id.c_str());

            // ranges include the low end but not the max so we inc by 1
            fresh_ranges.push_back({ start_num , end_num });
        }
        else {
            // now we are checking the avaliable ingrediants
            if (!line.empty()) {
                int test3 = 0;

                unsigned long long ingrediant_id = std::atoll(line.c_str());
                for (auto fresh_range : fresh_ranges) {
                    if (ingrediant_id >= fresh_range.first && ingrediant_id <= fresh_range.second) {
                        num_fresh_ingrediants++;
                        break;
                    }
                }
            }
        }
    }

    return num_fresh_ingrediants;
}

// How many possible fresh ids are there
unsigned long long day5_part2_function(std::string filename) {

    std::vector<std::string> file_lines = ReadFile(filename, false);

    // make a set of the ingrediants
    std::vector<std::pair<unsigned long long, unsigned long long>> fresh_ranges;
    bool fresh_set_done = false;
    unsigned long long num_fresh_ingrediants = 0;

    for (std::string line : file_lines) {
        std::cout << line << std::endl;

        if (line.empty()) {
            fresh_set_done = true;
        }

        if (!fresh_set_done) {
            unsigned int range_index = line.find('-');
            std::string start_id = line.substr(0, range_index);
            std::string end_id = line.substr(range_index + 1);

            unsigned long long start_num = std::atoll(start_id.c_str());
            unsigned long long end_num = std::atoll(end_id.c_str());

            // ranges include the low end but not the max so we inc by 1
            fresh_ranges.push_back({ start_num , end_num });
        }
    }

    std::vector<std::pair<unsigned long long, unsigned long long>> overlap_ranges;

    for (auto fresh_range : fresh_ranges) {


    }


    return num_fresh_ingrediants;
}
    

void day5_main() {

    day5_part2_function("inputs/day5_example.txt");
    // std::cout << "Day 5 part 1 example good paper rolls = " << day5_part1_function("inputs/day5_example.txt") << std::endl;
    // std::cout << "Day 5 part 1 puzzle good paper rolls = " << day5_part1_function("inputs/day5_puzzle.txt") << std::endl;

    // std::cout << "Day 5 part 2 example good paper rolls = " << day5_part2_function("inputs/day5_example.txt") << std::endl;
    // std::cout << "Day 5 part 2 puzzle good paper rolls = " << day5_part2_function("inputs/day5_puzzle.txt") << std::endl;
}
