/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <string>
#include <regex>
#include <fstream>
#include "C05Excercises.h"


namespace C05ConcurrencyEx {
    
    void excercise02() {
        std::mutex currMut;
        std::string word = "";
        
        std::thread t1{
                        [&currMut, &word]() -> void {
//                          std::unique_lock<std::mutex> myLock{currMut};
//                          currMut.lock();
//                          word = "Hello ";
                          std::cout << "Hello ";
                          std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                          
                          std::cout.flush();
//                          currMut.unlock();
                        }
        };
                      
        std::thread t2 {
                        [&currMut, &word]() -> void {
//                          std::unique_lock<std::mutex> myLock{currMut};
//                          currMut.lock();
//                          word = "World ";
                          std::cout << " World\n";
                          std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                          
                          std::cout.flush();
//                          currMut.unlock();
                        }
        };
        
        t1.join();
        t2.join();               
    }
    
    void runEx02(int times) {
        for(int i = 0; i < times; ++i) {
            excercise02();
        }
    }
    
    void excercise03(int times) {
        auto start = std::chrono::high_resolution_clock::now();
        
        for(int i = 0; i < times; ++i) {
//            std::cout << i << " ";
//            if(i > 0 && i % 100 == 0) {
//                std::cout << std::endl;
//            }
        }
        
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "\nTask done in: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " nanoseconds." <<std::endl;
    }
    
    RandInt::RandInt(int from, int to) 
        :dist(from, to) {

    }

    int RandInt::operator()() {
        return dist(dre);
    }

    void excercise04() {
        RandInt myRand(0, 30);
        
        std::vector<int> myVec(30);
        for(int i = 0; i < 200; ++i) {
            ++myVec[myRand()];
        }
        
        for(int i = 0; i < myVec.size(); ++i) {
            std::cout << i << "\t";
            for(int j = 0; j < myVec[i]; ++j) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
    
    void excercise05() {
        std::regex pattern(R"(\d{3})");
        std::ifstream file("Part1Introduction/C04TourOfContainersAndAlgorithms/files/ints.txt");
        
        std::string line;
        while(std::getline(file, line)) {
            std::smatch matches;
            if(std::regex_search(line, matches, pattern)) {
                for(auto elem : matches) {
                    std::cout << elem << " ";
                }
                std::cout << std::endl;
            }
        }
    }
}