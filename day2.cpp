#include <iostream>
#include <fstream>
#include "solutions.hpp"

int day2_first();
int day2_second();

int day2(){
    day2_first();
    day2_second();
}
int day2_first() {
    std::ifstream infile("/Users/rico/CLionProjects/AdventOfCode2024/inputs/day2_first.txt");
    std::string line;
    std::string delimiter = "   ";
    size_t pos = 0;

    std::vector<int> first_list;
    std::vector<int> second_list;

    while (std::getline(infile, line)) {
        std::string first_number_str = line.substr(0, pos = line.find(delimiter));
        first_list.emplace_back(std::stoi(first_number_str));

        std::string second_number_str = line.erase(0, pos + delimiter.length());
        second_list.emplace_back(std::stoi(second_number_str));

    }
    std::sort(std::begin(first_list), std::end(first_list));
    std::sort(std::begin(second_list), std::end(second_list));

    int diff = 0;
    for(int i=0; i< first_list.size(); i++){
        diff += std::abs(first_list[i] - second_list[i]);
    }
    std::cout << "The differences on the list elements sum up to: " << diff << std::endl;
    return 0;
}

int day2_second(){
    return 0;
}
