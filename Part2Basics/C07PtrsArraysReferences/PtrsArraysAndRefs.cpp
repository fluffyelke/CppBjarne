/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "PtrsArraysAndRefs.h"


namespace C07Ptrs {
    void examples() {
        
    }
    
    void exam01() {
        char c = 'a';
        char* cPtr = &c;
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        
        int& arrRef = *arr;
        
        char charArr[] = "12345";
        char* arrPtr = &charArr[0];
        
        char* secPtr = cPtr;
        
        const int num = 5;
        const int* numPtr = &num;
        
        int num2 = 10;
        int *const constNumPtr = &num2;
    }
    
    void exam02() {
        std::cout << "alignof(char*): " << alignof(char*) << std::endl;
        std::cout << "alignof(int*): " << alignof(int*) << std::endl;
        std::cout << "alignof(void*): " << alignof(void*) << std::endl;
    }
    
    void exam03() {

        
        using UChar = unsigned char;
        using CUChar = const unsigned char;
        using intPtr = int*;
        using PtrToPtrChar = char**;
        using PtrToArrOfChar = char*[];
        using IntArrayOf7Ptrs = int*[7];
        using PtrToIntArrayOf7Ptrs = IntArrayOf7Ptrs*;
        using Int8ArraysOfSevenPtrs = PtrToIntArrayOf7Ptrs[8];
    }

    
    void exam04() {
        char arr[] = {"What the fuck are you talking about man..."};
        int arrInt[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        std::cout << "chars: " << distance(&arr[15], &arr[15]);
        std::cout << std::endl;
        std::cout << "ints: " << distance(&arrInt[0], &arrInt[5]);
    }
    
    void exam07() {
        auto swapPtrs = [] (int* left, int* right) -> void {
            int temp = *left; 
            *left = *right;
            *right = temp;
        };
        
        auto swapsRefs = [] (int& left, int& right) -> void {
            int temp = left;
            left = right;
            right = temp;
        };
        
        int a = 100;
        int b = 200;
        std::cout << "init: " << a << " - " << b << std::endl;
        swapPtrs(&a, &b);
        std::cout << "swapPtrs: " << a << " - " << b << std::endl;
        swapsRefs(a, b);
        std::cout << "swapsRefs: " << a << " - " << b << std::endl;
    }
    
        
    void exam09() {
        auto f = [] (char c) {
          std::cout << "f(char): " <<c << std::endl;  
        };
        auto g = [] (char& c) {
            std::cout << "f(char&): " << c << std::endl;
        };
        auto h = [] (const char& c) {
            std::cout << "f(const char&): " << c << std::endl;  
        };
        
        f('a'); 
//        g('a');
        h('a');
        
        
        f(49);
//        g(49);
        h(49);
        
//        f(3300);
//        g(3300);
//        h(3300);
        
        char c = 'b';
        f(c);
        g(c);
        h(c);
        
        unsigned char uc = 'c';
        f(uc);
//        g(uc);
        h(uc);
        
        signed char sc = 'd';
        f(sc);
//        g(sc);
        h(sc);
    }
    
    void exam10() {
        std::string months[] = {"January", "February", "March", "April", "May", "June", "July", 
        "August", "September", "October", "November", "December"};
        
        for(int i = 0; i < 12; ++i) {
            std::cout << months[i] << " ";
        }
        
        std::cout << std::endl;
        auto printMonths = [months] (std::string* m, std::size_t length) -> void {
            for(int i = 0; i < length; ++i) {
                std::cout << m[i] << " ";
            }
        };
        printMonths(months, (sizeof(months) / sizeof(months[0])));
    }
    
    void exam11() {
        std::string word;
        
        std::vector<std::string> words;
        
        while(std::cin >> word) {
            
            if(word == "Quit") {
                break;
            }
            bool skipPush = false;
            for(int i = 0; i < words.size(); ++i) {
                if(word == words.at(i)) {
                    skipPush = true;
                    break;
                }
            }
            if(skipPush == false) {
                words.push_back(word);
            }
            
        }
        
        auto printWords = [] (const std::vector<std::string>& container) -> void {
            for(const auto& elem : container) {
                std::cout << elem << " ";
            }  
        };
        
        auto swap = [] (std::string& left, std::string& right) -> void {
            std::string temp = left;
            left = right;
            right = temp;
        };
        
        auto bubleSort = [swap] (std::vector<std::string>& cont) -> void {
            for(int i = 0; i < cont.size(); ++i) {
                for(int j = 0; j < cont.size() - i; ++j) {
                    if(cont[j] > cont[j + 1]) {
                        swap(cont[j], cont[j + 1]);
                    }
                }
            }
        };
        
        
        printWords(words);
        
        std::cout << std::endl;
        bubleSort(words);
        printWords(words);
        
    }
    
    void exam12() {
        auto countOccurencesInString = [] (const std::string& word, const std::string& key) -> void {
            int count = 0;
            
            for(int i = 0; i < word.length() - 1; ++i) {
                std::string temp = "";
                temp += word[i];
                temp += word[i + 1];
                if(temp == key) {
                    count++;
                }
            }
            
            std::cout << key << " apears: " << count << " times" << std::endl; 
        };
        
        std::string word = "xabaacbaxabb";
        countOccurencesInString(word, "ab");
        
        
        char myArr[] = "xabaacbaxabb";
        auto countOccurencesInCharArr = [] (char arr[], const char* key) {
            int count = 0;
            int index = 0;
            char first = key[0];
            char second = key[1];
            
            for(char c = arr[index]; c != '\0';) {
                if(c == first) {
                    c = arr[index + 1];
                    if(c == '\0') {
                        break;
                    }
                    if(c == second) {
                        count++;
                    }
                }
                index++;
                c = arr[index];
            }
            std::cout << std::string(key) << " apears: " << count << " times" << std::endl;
        };
        
        countOccurencesInCharArr(myArr, "ab");
    }
}