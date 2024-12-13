#include <iostream>
#include <fstream>
#include "solutions.hpp"
#include <sstream>

int day2_first();

void day2_second();

void day2_second_inefficient_solution();
void day2_first_try2();

void day2() {
    //day2_first();
    //day2_first_try2();
   day2_second_inefficient_solution();
}

bool check_differences(std::vector<int> pVector);

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
        if (check_numbers_ascending(numbers_in_line) || check_numbers_descending(numbers_in_line)) {
            safe = true;
            for (int i = 0; i < numbers_in_line.size() - 1; ++i) {
                if (std::abs(numbers_in_line[i] - numbers_in_line[i + 1]) > 3) {
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

bool check_criteria_day1(std::vector<int> &numbers_in_line) {

    if (check_numbers_ascending(numbers_in_line) || check_numbers_descending(numbers_in_line)) {
        if (check_differences(numbers_in_line)) {
            for (const auto &item: numbers_in_line) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
            return true;
        }
    }
    return false;
}


bool checkline_ascending(std::vector<int> numbers_in_line, int raphaelszahl) {

    int error_count = 0;
    for (int i = 0; i < numbers_in_line.size() - 1; i++) {
        int diff = numbers_in_line[i] - numbers_in_line[i + 1];
        if (diff < 0 && diff > -4) {
            continue;
        }

        if (error_count) {
            return false;
        }
        error_count++;
        numbers_in_line.erase(numbers_in_line.begin() + i + raphaelszahl);
        i = 0; // check the same number again in case of consecutive numbers
    }
    return true;
}

bool checkline_descending(std::vector<int> numbers_in_line, int raphaelszahl) {

    int error_count = 0;
    for (int i = 0; i < numbers_in_line.size() - 1; i++) {
        int diff = numbers_in_line[i] - numbers_in_line[i + 1];
        if (diff > 0 && diff < 4) {
            continue;
        }

        if (error_count) {
            return false;
        }
        error_count++;
        numbers_in_line.erase(numbers_in_line.begin() + i + raphaelszahl);
        i--; // check the same number again in case of consecutive numbers
    }
    return true;
}


void day2_second_inefficient_solution() {
    std::ifstream infile("inputs/day2_first.txt");
    std::string line;
    size_t safe_reports{0};


    while (std::getline(infile, line)) {
        std::vector<int> numbers_in_line;
        std::string word;
        std::stringstream ss(line);
        while (ss >> word) {
            numbers_in_line.emplace_back(std::stoi(word));
        }

        // now numbers_in_line contains a vector of all numbers
        for (int i = 0; i < numbers_in_line.size(); i++) {
            std::vector<int> numbers_cpy(numbers_in_line); // copy the vector
            numbers_cpy.erase(numbers_cpy.begin() + i);
            if(check_criteria_day1(numbers_cpy)){
                safe_reports++;
                break;
            }
        }
    }
    std::cout << "thee soluciii avenue today c'est " << safe_reports << std::endl;
}

void day2_second() {
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
        bool c1 = checkline_ascending(numbers_in_line, 0);
        bool c2 = checkline_ascending(numbers_in_line, 1);
        bool c3 = checkline_descending(numbers_in_line, 0);
        bool c4 = checkline_descending(numbers_in_line, 1);
        if (c1 || c2 || c3 || c4) {
            for (const auto &item: numbers_in_line) {
                std::cout << item << " ";
            }
            std::cout << std::endl;
            result++;
        }

    }
    std::cout << "After succesfully evaluating the safety dampener, the results have bumped up to: " << result
              << std::endl;
}

void day2_first_try2() {
    std::ifstream infile("inputs/day2_first.txt");
    std::string line;
    size_t safe_reports{0};


    while (std::getline(infile, line)) {
        std::vector<int> numbers_in_line;
        std::string word;
        std::stringstream ss(line);
        while (ss >> word) {
            numbers_in_line.emplace_back(std::stoi(word));
        }

        // now numbers_in_line contains a vector of all numbers
        if (check_criteria_day1(numbers_in_line)) {
            safe_reports++;
        }
    }
    std::cout << "Thee solucia shall be la numerta: " << safe_reports << std::endl;
}

bool check_differences(std::vector<int> pVector) {
    for (int i = 0; i < pVector.size() - 1; i++) {
        if (std::abs(pVector[i] - pVector[i + 1]) > 3 || std::abs(pVector[i] - pVector[i + 1]) < 1) {
            return false;
        }
    }
    return true;
}