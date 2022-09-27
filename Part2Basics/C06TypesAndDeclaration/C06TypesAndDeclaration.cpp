/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <type_traits>
#include <ios>
#include <limits>
#include "C06TypesAndDeclaration.h"


namespace C06Types {
    void exam01() {
        std::cout << "Hello World!" << std::endl;
    }
    
    void exam02() {
        if(std::is_signed<char>::value) {
            std::cout << "Char is signed on this pc" << std::endl;
        }
    }
    
    void exam03() {
        
        enum class myEnum{
            one,
            two,
            three
        };
        
        enum class myEnum2{
            one,
            two,
            three,
            four,
            five
        };
        
        std::cout << "sizeof(char): " << sizeof(char) << std::endl;
        std::cout << "sizeof(short): " << sizeof(short) << std::endl;
        std::cout << "sizeof(int): " << sizeof(int) << std::endl;
        std::cout << "sizeof(long): " << sizeof(long) << std::endl;
        std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;
        std::cout << "sizeof(double ): " << sizeof(double) << std::endl;
        std::cout << "sizeof(float): " << sizeof(float) << std::endl;
        std::cout << "sizeof(long double): " << sizeof(long double) << std::endl;
        std::cout << "sizeof(int*): " << sizeof(int*) << std::endl;
        std::cout << "sizeof(long long*): " << sizeof(long long*) << std::endl;
        std::cout << "sizeof(double*): " << sizeof(double*) << std::endl;
        std::cout << "sizeof(myEnum): " << sizeof(myEnum) << std::endl;
        std::cout << "sizeof(myEnum2): " << sizeof(myEnum2) << std::endl;
    }
    
    void exam04() {
        for(char c = 'a'; c <= 'z'; ++c) {
            std::cout << int(c) << ": " << c << std::endl;
        }
        for(char c = '0'; c <= '9'; ++c) {
            std::cout << int(c) << ": " << c << std::endl;
        }
        for(char c = 'a'; c <= 'z'; ++c) {
            std::cout << std::hex << int(c) << ": " << c << std::endl;
        }
        for(char c = '0'; c <= '9'; ++c) {
            std::cout << std::hex << int(c) << ": " << c << std::endl;
        }
    }
    
    void largestAndSmallest() {
        //bool, char, short, int, long, long long, float, double, long double, unsigned , unsigned long
        std::cout << "std::numeric_limits<bool>::lowest(): " << std::numeric_limits<bool>::lowest() << std::endl;
        std::cout << "std::numeric_limits<bool>::min(): " << std::numeric_limits<bool>::min() << std::endl;
        std::cout << "std::numeric_limits<bool>::max(): " << std::numeric_limits<bool>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<char>::lowest(): " << std::numeric_limits<char>::lowest() << std::endl;
        std::cout << "std::numeric_limits<char>::min(): " << std::numeric_limits<char>::min() << std::endl;
        std::cout << "std::numeric_limits<char>::max(): " << std::numeric_limits<char>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<short>::lowest(): " << std::numeric_limits<short>::lowest() << std::endl;
        std::cout << "std::numeric_limits<short>::min(): " << std::numeric_limits<short>::min() << std::endl;
        std::cout << "std::numeric_limits<short>::max(): " << std::numeric_limits<short>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<int>::lowest(): " << std::numeric_limits<int>::lowest() << std::endl;
        std::cout << "std::numeric_limits<int>::min(): " << std::numeric_limits<int>::min() << std::endl;
        std::cout << "std::numeric_limits<int>::max(): " << std::numeric_limits<int>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<long>::lowest(): " << std::numeric_limits<long>::lowest() << std::endl;
        std::cout << "std::numeric_limits<long>::min(): " << std::numeric_limits<long>::min() << std::endl;
        std::cout << "std::numeric_limits<long>::max(): " << std::numeric_limits<long>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<long long>::lowest(): " << std::numeric_limits<long long>::lowest() << std::endl;
        std::cout << "std::numeric_limits<long long>::min(): " << std::numeric_limits<long long>::min() << std::endl;
        std::cout << "std::numeric_limits<long long>::max(): " << std::numeric_limits<long long>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<float>::lowest(): " << std::numeric_limits<float>::lowest() << std::endl;
        std::cout << "std::numeric_limits<float>::min(): " << std::numeric_limits<float>::min() << std::endl;
        std::cout << "std::numeric_limits<float>::max(): " << std::numeric_limits<float>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<double>::lowest(): " << std::numeric_limits<double>::lowest() << std::endl;
        std::cout << "std::numeric_limits<double>::min(): " << std::numeric_limits<double>::min() << std::endl;
        std::cout << "std::numeric_limits<double>::max(): " << std::numeric_limits<double>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<long double>::lowest(): " << std::numeric_limits<long double>::lowest() << std::endl;
        std::cout << "std::numeric_limits<long double>::min(): " << std::numeric_limits<long double>::min() << std::endl;
        std::cout << "std::numeric_limits<long double>::max(): " << std::numeric_limits<long double>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<unsigned>::lowest(): " << std::numeric_limits<unsigned>::lowest() << std::endl;
        std::cout << "std::numeric_limits<unsigned>::min(): " << std::numeric_limits<unsigned>::min() << std::endl;
        std::cout << "std::numeric_limits<unsigned>::max(): " << std::numeric_limits<unsigned>::max() << std::endl;
        std::cout << std::endl;
        
        std::cout << "std::numeric_limits<unsigned long>::lowest(): " << std::numeric_limits<unsigned long>::lowest() << std::endl;
        std::cout << "std::numeric_limits<unsigned long>::min(): " << std::numeric_limits<unsigned long>::min() << std::endl;
        std::cout << "std::numeric_limits<unsigned long>::max(): " << std::numeric_limits<unsigned long>::max() << std::endl;
        std::cout << std::endl;
    }

}