/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "X3Excercises.h"


namespace C02Basics {
    void ex05() {
        bool b = 42;
        int a = 42;
        char c = 42;
        double d = 42.5;
        std::string s = "42";
        
        std::cout << std::boolalpha;
        std::cout << "bool b:   " << b << std::endl;
        std::cout << "int a:    " << a << std::endl;
        std::cout << "char c:   " << c << std::endl;
        std::cout << "double :  " << d << std::endl;
        std::cout << "string s: " << s << std::endl;
    }
    void ex06() {
        bool b;
        int a;
        char c;
        double d;
        std::string s;
        
        std::cin >> b >> a >> c >> d >> s;
        
        std::cout << std::boolalpha;
        std::cout << "bool b:   " << b << std::endl;
        std::cout << "int a:    " << a << std::endl;
        std::cout << "char c:   " << c << std::endl;
        std::cout << "double :  " << d << std::endl;
        std::cout << "string s: " << s << std::endl;
    }
}