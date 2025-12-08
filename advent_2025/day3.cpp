#include "common.hpp"
#include "solution_includes.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <vector>


//#define DEBUG_PRINT
// Joltages - a value from 1 to 9
// each line of digits is a single bank of batteries
// Need to turn on 2 batteries in the bank so that the largest joltage is produced
// 987654321111111
// 811111111111119
// 234234234234278
// 818181911112111
unsigned int day3_part1_function(std::string filename) {
    unsigned int total_joltage = 0;
    std::vector<std::string> file_lines = ReadFile(filename, false);

    for (std::string line : file_lines) {
        unsigned int battery_joltage = 0;

        char max_battery_voltage = 0;
        unsigned int max_battery_index;

        for (unsigned int index = 0; index < line.size() - 1; index++) {
            char voltage = line.at(index);
            if (voltage > max_battery_voltage) {
                max_battery_voltage = voltage;
                max_battery_index = index;
            }
        }

        // find the next largest number
        char second_battery_voltage = 0;
        for (unsigned int index = max_battery_index + 1; index < line.size(); index++) {
            char voltage = line.at(index);

            if (voltage > second_battery_voltage) {
                second_battery_voltage = voltage;
            }
        }


        //std::cout << "max_battery_voltage " << max_battery_voltage << " max_battery_index " << max_battery_index << std::endl;
        //std::cout << "second_battery_voltage " << second_battery_voltage << std::endl;

        std::string voltage_str = { max_battery_voltage, second_battery_voltage };
        battery_joltage = std::atoi(voltage_str.c_str());

        total_joltage += battery_joltage;
    }

    return total_joltage;
}


void day3_part2_function(std::string filename) {

}


void day3_main() {
    std::cout << "Day 2 part 1 example max joltage = " << day3_part1_function("inputs/day3_example.txt") << std::endl;
    std::cout << "Day 2 part 1 puzzle invalid id sum = " << day3_part1_function("inputs/day3_puzzle.txt") << std::endl;

    //std::cout << "Day 2 part 2 example invalid id sum = " <<  day3_part2_function("inputs/day2_example.txt") << std::endl;
    //std::cout << "Day 2 part 2 puzzle invalid id sum = " <<  day3_part2_function("inputs/day2_puzzle.txt") << std::endl;
}
