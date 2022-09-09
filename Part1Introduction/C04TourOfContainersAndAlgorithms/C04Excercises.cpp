/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <random>
#include "../../RNGGenerator.h"
#include "../../utils/ImprovedAlgs.h"
#include "C04Excercises.h"


namespace C04Exercises {
    void readNameAndNumber() {
        std::string name;
        int number;
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter number: ";
        std::cin >> number;
        
        std::cout << "{\"" << name << "\"" << "," << number << "}";
        std::cout << std::endl;
    }
    
    std::ostream& operator << (std::ostream& os, const NameNumber& obj) {
        return os << "{\"" << obj.name << "\"" << "," << obj.number << "}";
    }
    std::istream& operator >> (std::istream& is, NameNumber& obj) {
        //read {"name", number}
        char c, c2;
        if(is >> c && c == '{' && is >> c2 && c2 == '"') {  //start with { "
            std::string name;   
            
            while(is.get(c) && c != '"') {
                name += c;
            }
            
            if(is >> c && c == ',') {
                int number = 0;
                if(is >> number >> c && c == '}') {      //read the number and a }
                    obj = {name, number};   //assign to the entry
                    return is;
                }
            }
        }
        is.setstate(std::ios_base::failbit);    //register the failure in the stream
        return is;
    }
    void excercise06() {
        std::vector<NameNumber> obj;
        for(int i = 0; i < 5; ++i) {
            NameNumber temp;
            std::cin >> temp;
            obj.push_back(temp);
        }
        for(int i = 0; i < obj.size(); ++i){
            std::cout << obj[i] << std::endl;
        }
    }
    
    
    void excercise07() {
        std::vector<int> myVec = {5, 9, -1, 200, 0};
        std::copy(myVec.begin(), myVec.end(),
                 std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        Utils::sort(myVec);
        std::copy(myVec.begin(), myVec.end(),
                 std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        std::vector<std::string> strVec = {"Vanya", "Maria", "Deska", "Victoria", "Karen"};
        std::copy(strVec.cbegin(), strVec.cend(),
                 std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
        Utils::sort(strVec);
        std::copy(strVec.begin(), strVec.end(),
                 std::ostream_iterator<std::string>(std::cout, " "));
    }
    
    void excercise08() {
        RNG::randomize();
        std::ofstream output("Part1Introduction/C04TourOfContainersAndAlgorithms/files/ints.txt");
        for(int i = 0; i < 1000; i++) {
            int number = RNG::getRandomInteger(0, 1000);
            output << number << " ";
            if(i > 0 && i % 20 == 0) {
                output << std::endl;
            }
        }
        output.close();
        
        std::ifstream input("Part1Introduction/C04TourOfContainersAndAlgorithms/files/ints.txt");
        std::cout << input.rdbuf() << std::endl;
        
    }
}