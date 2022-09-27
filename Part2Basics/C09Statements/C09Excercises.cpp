/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cinttypes>
#include <cstring>
#include <fstream>
#include "C09Excercises.h"


namespace C09Ex {
    void exam01() {
        
        
        
        char arr[] = "asdfasf?dsgf??asdfasda3dhg?";
        int maxLength = sizeof(arr) / sizeof(arr[0]);
        int count = 0;
        for(int i = 0; i < maxLength; ++i) {
            if(arr[i] == '?') {
                count++;
            }
        }
        std::cout << "for: " << count << std::endl;
        //rewrite the loop with while
        count = 0;
        
        int i = 0;
        while(i < maxLength) {
            if(arr[i] == '?') {
                count++;
            }
            i++;
        }
        std::cout << "while: " << count << std::endl;
        i = 0;
        count = 0;
        
        char* pArr = &arr[0];
        while(*pArr != '\0') {
            if(*pArr == '?') {
                count++;
            }
            pArr++;
        }
        std::cout << "*pArr: " << count << std::endl;
        
        count = 0;
        for(auto it = std::begin(arr); it != std::end(arr); ++it) {
            if(*it == '?') {
                count++;
            }
        }
        std::cout << "*it: " << count << std::endl;
    }
    
    
    void exam04() {
        
        auto atoi = [] (const char* str, int base = 10) -> int {
            
            int result = 0;
            int length = 1;
            
            int strSize = strlen(str);
            
            while(strSize > 0){
                char c = str[strSize - 1];
                int temp = 0;
                switch(int(c)) {
                    case 48:
                        temp = 0;
                        break;
                    case 49:
                        temp = 1;
                        break;
                    case 50:
                        temp = 2;
                        break;
                    case 51:
                        temp = 3;
                        break;
                    case 52:
                        temp = 4;
                        break;
                    case 53:
                        temp = 5;
                        break;
                    case 54:
                        temp = 6;
                        break;
                    case 55:
                        temp = 7;
                        break;
                    case 56:
                        temp = 8;
                        break;
                    case 57:
                        temp = 9;
                        break;
                    case 65:
                        temp = 10;
                        break;
                    case 66:
                        temp = 11;
                        break;
                    case 67:
                        temp = 12;
                        break;
                    case 68:
                        temp = 13;
                        break;
                    case 69:
                        temp = 14;
                        break;
                    case 70:
                        temp = 15;
                        break;
                    case 97:
                        temp = 10;
                        break;
                    case 98:
                        temp = 11;
                        break;
                    case 99:
                        temp = 12;
                        break;
                    case 100:
                        temp = 13;
                        break;
                    case 101:
                        temp = 14;
                        break;
                    case 102:
                        temp = 15;
                        break;
                }
                temp *= length;
                result += temp;
                switch(base) {
                    case 10:
                      length *= 10;
                      break;
                    case 8:
                        length *= 8;
                        break;
                    case 16:
                        length *= 16;
                        break;
                }
                
                strSize--;
            }
            
            return result;
        };
        int result = atoi("30071", 8);
        std::cout << result << std::endl;
    }
    
    void exam05() {
        
        auto intToStr = [] (int num, char res[]) -> void {
            int temp = num;
            int index = 0;
            
            auto intLength = [] (int num) -> int {
                int count = 0;
                int temp = num;
                while(temp > 0) {
                    count++;
                    temp /= 10;
                }
                return count;
            };  
            int size = intLength(num);
            while(temp > 0) {
                int tmp = temp % 10;
                temp /= 10;
//                std::cout << tmp << std::endl;
                char c = ' ';
                switch(tmp) {
                    case 0:
                        c = '0';
                        break;
                    case 1:
                        c = '1';
                        break;
                    case 2:
                        c = '2';
                        break;
                    case 3:
                        c = '3';
                        break;
                    case 4:
                        c = '4';
                        break;
                    case 5:
                        c = '5';
                        break;
                    case 6:
                        c = '6';
                        break;
                    case 7:
                        c = '7';
                        break;
                    case 8:
                        c = '8';
                        break;
                    case 9:
                        c = '9';
                        break;
                }
                --size;
                res[size] = c;
                
            }
        };
        constexpr int length = strlen("2512351");
        char res[length];
        intToStr(2512351, res);
        for(int i = 0; i < length; ++i) {
            std::cout << res[i];
        }
    }
    
    void stripComments(const std::string& fileName) {
        std::ifstream file(fileName);
        if(!file.is_open()) {
            std::cerr << "filename: " << fileName << " not found!" << std::endl;
            return;
        }
        
        std::string line;
        std::string result = "";
        std::string comm1 = "/*";
        std::string comm2 = "//";
        std::string comm3 = "*/";
        std::string comm4 = " *";
        
        while(std::getline(file, line)) {
            std::string temp = "";
            bool bSkipLine = false;
            temp += line[0];
            temp += line[1];
            if(temp == comm1 || temp == comm2 || temp == comm3 || temp == comm4) {
                bSkipLine = true;
            }
            if(!bSkipLine) {
                result.append(line + '\n');
            }
        }
        
        std::cout << result << std::endl;
    }
}