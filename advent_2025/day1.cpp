#include "common.hpp"
#include "solution_includes.hpp"

#include <iostream>
#include <vector>

// Test data -
// The dial starts by pointing at 50.
// The dial is rotated L68 to point at 82.
// The dial is rotated L30 to point at 52.
// The dial is rotated R48 to point at 0.
// The dial is rotated L5 to point at 95.
// The dial is rotated R60 to point at 55.
// 
// The dial is rotated L55 to point at 0.
// The dial is rotated L1 to point at 99.
// The dial is rotated L99 to point at 0.
// The dial is rotated R14 to point at 14.
// The dial is rotated L82 to point at 32.
const int kdial_maximum = 99;
const int kdial_minimum = 0;
int day1_function(std::string filename) {
    std::vector<std::string> file_lines = ReadFile(filename, false);

    int dial_position = 50;
    unsigned int password = 0;

    // Loop over the lines
    int dial_modifier = 0;
    for (std::string line : file_lines) {
        dial_modifier = std::atoi(line.c_str() + 1);

        // the dial wraps around so keep the remainder
        if (dial_modifier > kdial_maximum) {
            dial_modifier = dial_modifier % (kdial_maximum + 1);
        }

        // subtract
        if (line[0] == 'L') {
#ifdef DEBUG_PRINT
            std::cout << "L modifier " << dial_modifier << std::endl;
#endif DEBUG_PRINT
            dial_position = dial_position - dial_modifier;
            if (dial_position < kdial_minimum) {
                dial_position = kdial_maximum + dial_position + 1;
            }
        }
        // add
        else {
#ifdef DEBUG_PRINT
            std::cout << "R modifier " << dial_modifier << std::endl;
#endif DEBUG_PRINT
            dial_position = dial_position + dial_modifier;
            if (dial_position > kdial_maximum) {
                dial_position = dial_position - kdial_maximum - 1;
            }
        }
#ifdef DEBUG_PRINT
        std::cout << "dial_position " << dial_position << std::endl;
#endif DEBUG_PRINT
        if (dial_position == kdial_minimum) {
            password++;
#ifdef DEBUG_PRINT
            std::cout << "password " << password << std::endl;
#endif DEBUG_PRINT
        }
    }
    return password;
}

// dial with number 0-99
// sequence of rotations, L (down) R (up) then a number
// rotate goes back to 0
// dial starts at 50

// safe is a decoy
// password - number of times dial is left pointing at 0 after each rotation
void day1_main() {
    std::cout << "Day 1 example password = " << day1_function("inputs/day1_example.txt") << std::endl;
    std::cout << "Day 1 puzzle password = " << day1_function("inputs/day1_puzzle.txt") << std::endl;
}
