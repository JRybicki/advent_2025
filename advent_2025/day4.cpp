#include "common.hpp"
#include "solution_includes.hpp"

#include <iostream>
#include <vector>


// need to optimize forklift operations to break through the wall
// rolls of paper are @ smybol
// can only access if there are fewer than 4 rolls of paper in the 8 adjacent positions
// FEWER THAN 4 - think of below surroundings
// ...
// .@.
// ...
// How many rolls can the forklist access?
// Example map below
// ..@@.@@@@.
// @@@.@.@.@@
// @@@@@.@.@@
// @.@@@@..@.
// @@.@@@@.@@
// .@@@@@@@.@
// .@.@.@.@@@
// @.@@@.@@@@
// .@@@@@@@@.
// @.@.@@@.@.
unsigned int day4_part1_function(std::string filename) {
    unsigned int good_paper_rolls = 0;
    std::vector<std::string> file_lines = ReadFile(filename, false);

    std::vector<std::vector<int>> paper_map;
    const char paper = '@';

    // pad the paper map (peak the line size)
    std::vector<int> v(file_lines.front().size() + 2, 0);
    paper_map.push_back(v);

    for (std::string line : file_lines) {
        std::vector<int> paper_row;
        
        // pad the columns
        paper_row.push_back(0);

        for (char index : line) {
            if (index == paper) {
                paper_row.push_back(1);
            }
            else {
                paper_row.push_back(0);
            }
        }

        paper_row.push_back(0);
        paper_map.push_back(paper_row);
    }
    paper_map.push_back(v);

    std::vector<std::vector<int>> paper_count(paper_map.size(), std::vector<int>(paper_map.front().size(), 0));

    // ..@@.@@@@.
    // @@@.@.@.@@
    
    // 0011012210
    // 0033033430
    
    for (unsigned int row = 1; row < paper_map.size() - 1; row++) {
        // check the row above and below
        std::vector<int> prev_row = paper_map.at(row - 1);
        std::vector<int> current_row = paper_map.at(row);
        std::vector<int> next_row = paper_map.at(row + 1);

        for (unsigned int col = 1; col < paper_map.at(row).size() - 1; col++) {
            if (current_row.at(col) == 1) {
                paper_count.at(row).at(col) += prev_row.at(col - 1) + prev_row.at(col) + prev_row.at(col + 1);
                paper_count.at(row).at(col) += current_row.at(col - 1) + current_row.at(col + 1);
                paper_count.at(row).at(col) += next_row.at(col - 1) + next_row.at(col) + next_row.at(col + 1);
            }
        }
    }

    for (unsigned int row = 1; row < paper_count.size() - 1; row++) {

        std::vector<int> current_row = paper_count.at(row);

        for (unsigned int col = 1; col < paper_count.at(row).size() - 1; col++) {

            unsigned int paper_value = paper_count.at(row).at(col);

            if (paper_value >= 1 && paper_value <= 3) {
                good_paper_rolls++;
            }
        }
    }

    return good_paper_rolls;
}

// should use functions here but I'm mad tired
unsigned int day4_part2_function(std::string filename) {

    unsigned int good_paper_rolls = 0;
    std::vector<std::string> file_lines = ReadFile(filename, false);

    std::vector<std::vector<int>> paper_map;
    const char paper = '@';

    // pad the paper map (peak the line size)
    std::vector<int> v(file_lines.front().size() + 2, 0);
    paper_map.push_back(v);

    for (std::string line : file_lines) {
        std::vector<int> paper_row;

        // pad the columns
        paper_row.push_back(0);

        for (char index : line) {
            if (index == paper) {
                paper_row.push_back(1);
            }
            else {
                paper_row.push_back(0);
            }
        }

        paper_row.push_back(0);
        paper_map.push_back(paper_row);
    }
    paper_map.push_back(v);

    unsigned int current_good_rolls = 0;

    do {

        std::vector<std::vector<int>> paper_count(paper_map.size(), std::vector<int>(paper_map.front().size(), 0));

        for (unsigned int row = 1; row < paper_map.size() - 1; row++) {
            // check the row above and below
            std::vector<int> prev_row = paper_map.at(row - 1);
            std::vector<int> current_row = paper_map.at(row);
            std::vector<int> next_row = paper_map.at(row + 1);

            for (unsigned int col = 1; col < paper_map.at(row).size() - 1; col++) {

                if (current_row.at(col) == 1) {
                    paper_count.at(row).at(col) += prev_row.at(col - 1) + prev_row.at(col) + prev_row.at(col + 1);
                    paper_count.at(row).at(col) += current_row.at(col - 1) + current_row.at(col) + current_row.at(col + 1);
                    paper_count.at(row).at(col) += next_row.at(col - 1) + next_row.at(col) + next_row.at(col + 1);
                }
            }
        }

        // instead of just counting the good paper roll remove the ones we can grab
        current_good_rolls = 0;
        for (unsigned int row = 1; row < paper_count.size() - 1; row++) {

            std::vector<int> current_row = paper_count.at(row);

            for (unsigned int col = 1; col < paper_count.at(row).size() - 1; col++) {

                unsigned int paper_value = paper_count.at(row).at(col);

                // less than or equal to 4 cause we include current self
                if (paper_value >= 1 && paper_value <= 4) {
                    current_good_rolls++;
                    paper_map.at(row).at(col) = 0;
                }
            }
        }

        good_paper_rolls += current_good_rolls;
    } while (current_good_rolls != 0);


    // 9486 is too low
    return good_paper_rolls;

}


void day4_main() {

    std::cout << "Day 4 part 1 example good paper rolls = " << day4_part1_function("inputs/day4_example.txt") << std::endl;
    std::cout << "Day 4 part 1 puzzle good paper rolls = " << day4_part1_function("inputs/day4_puzzle.txt") << std::endl;

    std::cout << "Day 4 part 2 example good paper rolls = " << day4_part2_function("inputs/day4_example.txt") << std::endl;
    std::cout << "Day 4 part 2 puzzle good paper rolls = " << day4_part2_function("inputs/day4_puzzle.txt") << std::endl;
}
