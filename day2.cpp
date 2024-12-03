#include <iostream>
#include <fstream>
#include "solutions.hpp"
#include <sstream>

int day2_first();

int day2_second();

void day2() {
    day2_first();
    day2_second();
}

bool check_numbers_ascending(std::vector<int> &pVector) {
    for (int i = 0; i < pVector.size() - 1; i++) {
        if (pVector[i] >= pVector[i + 1]) {
            return false;
        }
    }
    return true;
}

bool check_numbers_descending(std::vector<int> &pVector) {
    for (int i = 0; i < pVector.size() - 1; i++) {
        if (pVector[i] <= pVector[i + 1]) {
            return false;
        }
    }
    return true;
}

int day2_first() {
    std::ifstream infile("inputs/day2_first.txt");
    std::string line;
    size_t result = 0;


    while (std::getline(infile, line)) {
        std::vector<int> numbers_in_line;
        std::string word;
        std::stringstream ss(line);
        while (ss >> word) {
            numbers_in_line.emplace_back(std::stoi(word));
        }
        bool safe = false;
        if(check_numbers_ascending(numbers_in_line) || check_numbers_descending(numbers_in_line)){
            safe = true;
            for (int i = 0; i < numbers_in_line.size() - 1; ++i) {
                if(std::abs(numbers_in_line[i] - numbers_in_line[i+1]) > 2){
                    safe = false;
                    break;
                }
            }
        }
        if (safe) {
            for (const auto &item: numbers_in_line) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
            result++;
        }
    }
    std::cout << "Amount of safe reports: " << result << std::endl;
    return 0;

}

int day2_second() {
    return 0;
}
