#include "common.hpp"
#include "solution_includes.hpp"


#include <iostream>
#include <vector>


// dial with number 0-99
// sequence of rotations, L (down) R (up) then a number
// rotate goes back to 0
// dial starts at 50

// safe is a decoy
// password - number of times dial is left pointing at 0 after each rotation
void day1_test() {
    std::vector<std::string> lines = ReadFile("inputs/day1_example.txt", true);


}

void day1_main() {
    std::cout << "hello world day1 main" << std::endl;
    day1_test();
}
