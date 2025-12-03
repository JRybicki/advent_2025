#include "common.hpp"
#include "solution_includes.hpp"

#include <iostream>
#include <vector>
#include <array>

//#define DEBUG_PRINT
// This code is pretty slow but it does work
long long int day2_part1_function(std::string filename) {

    long long int invalid_id_sum = 0;
    char range_delimiter = '-';

    std::vector<std::string> id_ranges = ReadCSV(filename, false);

    for (std::string range : id_ranges) {
#ifdef DEBUG_PRINT
        std::cout << range << std::endl;
#endif DEBUG_PRINT
        unsigned int range_delimiter_pos = range.find(range_delimiter);
        long long int start_range = std::atoll(range.substr(0, range_delimiter_pos).c_str());
        long long int end_range = std::atoll(range.substr(range_delimiter_pos + 1, range.size()).c_str());

        for (long long int id_value = start_range; id_value <= end_range; id_value++) {
            // for a number to be repated it needs to be an even number of digits
            std::string id_str = std::to_string(id_value);

            // for a number to be repated it needs to be an even number of digits
            if (id_str.size() % 2 == 0) {
#ifdef DEBUG_PRINT
                std::cout << "id_str " << id_str << std::endl;
#endif DEBUG_PRINT
                // get first half of string
                std::string id_str_start_sequence = id_str.substr(0, id_str.size() / 2);
                std::string id_str_end_sequence = id_str.substr(id_str.size() / 2);
#ifdef DEBUG_PRINT
                std::cout << "id_str_start_sequence " << id_str_start_sequence << std::endl;
                std::cout << "id_str_end_sequence " << id_str_end_sequence << std::endl;
#endif DEBUG_PRINT
                if (id_str_start_sequence.compare(id_str_end_sequence) == 0) {
#ifdef DEBUG_PRINT
                    std::cout << "found invalid id " << id_value << std::endl;
#endif DEBUG_PRINT
                    invalid_id_sum += id_value;
                }
            }
        }
    }
    return invalid_id_sum;
}

long long int day2_part2_function(std::string filename) {
    long long int invalid_id_sum = 0;
    char range_delimiter = '-';

    std::vector<std::string> id_ranges = ReadCSV(filename, false);

    for (std::string range : id_ranges) {
// #ifdef DEBUG_PRINT
        std::cout << range << std::endl;
// #endif DEBUG_PRINT
        unsigned int range_delimiter_pos = range.find(range_delimiter);
        long long int start_range = std::atoll(range.substr(0, range_delimiter_pos).c_str());
        long long int end_range = std::atoll(range.substr(range_delimiter_pos + 1, range.size()).c_str());


        for (long long int id_value = start_range; id_value <= end_range; id_value++) {
            // for a number to be repated it needs to be an even number of digits
            std::string id_str = std::to_string(id_value);
            //std::cout << "id_str " << id_str << std::endl;
            bool invalid_id = true;

            // check for single length numbers
            if (id_value < 10) {
                invalid_id = false;
            } else {
                // check for any repeating digits, start with size 1 up to half of len of str
                for (unsigned int id_index = 0; id_index < id_str.size() / 2; id_index++) {

                    invalid_id = true;

                    std::string id_substr = id_str.substr(0, id_index + 1);
                    //std::cout << "id_substr " << id_substr << std::endl;

                    // How many more substrings can there be
                    unsigned int substr_count = id_str.size() / id_substr.size();
                    //std::cout << "substr_count " << substr_count << std::endl;

                    for (unsigned int i = 0; i < substr_count; i++) {
                        std::string next_id = id_str.substr(id_substr.size() * i, id_substr.size());
                        //std::cout << "next_id " << next_id << std::endl;

                        // check if this is a repating id
                        if (id_substr.compare(next_id) != 0) {
                            invalid_id = false;
                        }
                    }

                    if (invalid_id) {
                        // only need to check this number once so break the loop
                        break;
                    }
                }
            }

            if (invalid_id) {
                std::cout << "invalid id " << id_value << std::endl;
                invalid_id_sum += id_value;
            }
        }
    }

    std::cout << "invalid_id_sum " << invalid_id_sum << std::endl;
    return invalid_id_sum;
}

// invalid database ids in gift shop
// puzzle only needs to check a few ranges
// Test data (csv value on a single line)
// 11-22,95-115,998-1012,1188511880-1188511890,222220-222224,
// 1698522 - 1698528, 446443 - 446449, 38593856 - 38593862, 565653 - 565659,
// 824824821 - 824824827, 2121212118 - 2121212124

// only looking for ids with silly digits (ex 55, 6464, 123123)
// none of the numbers have leading zeros (ex 0101)
void day2_main() {
    //std::cout << "Day 2 part 1 example invalid id sum = " << day2_part1_function("inputs/day2_example.txt") << std::endl;
    //std::cout << "Day 2 part 1 puzzle invalid id sum = " << day2_part1_function("inputs/day2_puzzle.txt") << std::endl;

    day2_part2_function("inputs/day2_example.txt");

}
