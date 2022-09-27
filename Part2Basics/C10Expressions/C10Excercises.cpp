/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "C10Excercises.h"

#include <map>
#include <iostream>
#include <cstring>

namespace C10Ex {
    void ex02() {
        std::map<std::string, double> stocks;
        
        for(int i = 0; i < 5; ++i) {
            std::cout << "Enter Name: and value: ";
            std::string name = "";
            double value = 0.0;
            std::cin >> name >> value;
            stocks.emplace(std::make_pair(name, value));
        }
        
        double total = 0.0;
        for(auto elem : stocks) {
            total += elem.second;
        }
        std::cout << "Total: " << total << std::endl;
    }
    
    int myStrlen(const char* str) {
        int count = 0;
        while(*str++ != '\0'){
            count++;
        }
        return count;
    }
    
    void myStrcpy(const char* from, char* to) {
        while(*from != '\0') {
            *to++ = *from;
            from++;
        }
        *to = '\0';
    }
    
    int myStrcmp(const char* left, const char* right) {
        while(*left != '\0' || *right != '\0') {
            if(*left != *right) {
                return 0;
            }
            left++;
            right++;
        }
        return 1;
    }
    
    void ex07() {
        std::cout << myStrlen("How Long is this shit!") << std::endl;
        std::cout << myStrlen("1234567890") << std::endl;
        
        std::cout << "standard strlen: " << strlen("How Long is this shit!") << std::endl;
        std::cout << "standard strlen: " << strlen("1234567890") << std::endl;
        
        char res[] = {"I will copy this shit!"};
        std::cout << "res[] size: " << myStrlen(res) << std::endl;
        char toRes[30];
        myStrcpy(res, toRes);
        std::cout << "toRes[] size:" << myStrlen(toRes) << std::endl;
        for(int i = 0; i < myStrlen(toRes); ++i) {
            std::cout << toRes[i] << " ";
        }
        std::cout << std::endl;
        
        
        char res2[] = {"I will copy this shit!"};
        std::cout << "res2[] size: " << strlen(res2) << std::endl;
        char toRes2[30];
        strcpy(toRes2, res2);
        std::cout << "toRes2[] size:" << strlen(toRes2) << std::endl;
        for(int i = 0; i < strlen(toRes2); ++i) {
            std::cout << toRes2[i] << " ";
        }
        std::cout << std::endl;
        
        char left[] = {"1234567890"};
        char right[] = {"12345678901"};
        if(myStrcmp(left, right) == 1) {
            std::cout << "Strings are equal" << std::endl;
        }
        else {
            std::cout << "Strings are NOT equal" << std::endl;
        }
        
        char left2[] = {"1234567890"};
        char right2[] = {"12345678901"};
        if(strcmp(left, right) == 1) {
            std::cout << "2Strings are equal" << std::endl;
        }
        else {
            std::cout << "2Strings are NOT equal" << std::endl;
        }
    }
    
    char* myConcat(const char* left, const char* right) {
        const int length = strlen(left) + strlen(right);
        char* result = new char[length];
        int index = 0;
        while(*left != '\0'){
            result[index] = *left;
            ++index;
            ++left;
        }
        while(*right != '\0') {
            result[index] = *right;
            ++index;
            ++right;
        }
        return result;
    }
    
    void ex09() {
        const char* left = "Hello";
        const char* right = " World!";
        char* result = myConcat(left, right);
        for(int i = 0; i < strlen(result); ++i) {
            std::cout << result[i];
        }
        delete result;
    }
    
    void myReverse(char str[]) {
        
        int length = strlen(str);
        
        int index = 0;
        while(index < length / 2) {
            char temp = str[index];
            str[index] = str[length - index - 1];
            str[length - index - 1] = temp;
            index++;
        }
        
    }
    
    void ex10() {
        char pfff[] = "Hello World123";
        for(int i = 0; i < strlen(pfff); ++i) {
            std::cout << pfff[i];
        }
        std::cout << std::endl;
        myReverse(pfff);
        std::cout << std::endl;
        for(int i = 0; i < strlen(pfff); ++i) {
            std::cout << pfff[i];
        }
    }
    
    void copyFromIntToVec(int arr[], std::size_t length, std::vector<int>& dest) {
        for(int i = 0; i < length; ++i) {
            if(arr[i] % 2 == 0 && arr[i] != 0) {
                dest.emplace_back(arr[i]);
            }
        }
    }
    
    void ex11() {
        
        int arr[] = {0, -11, 2, 3, -4, 5, 0, 6, 7, -8, 0, 9, 10, 0, 11};
        std::vector<int> intVec;
        std:size_t length = sizeof arr / sizeof *arr;
        copyFromIntToVec(arr, length,  intVec);
        for(auto elem : intVec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        
    }
}