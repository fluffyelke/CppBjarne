/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Macros.h"


namespace PreDefMacros {
    void printDate() {
        std::cout << __DATE__ << std::endl;
    }
    void printTime() {
        std::cout << __TIME__ << std::endl;
    }
    void printCurrSourceFile() {
        std::cout << __FILE__ << std::endl;
    }
    void printLine() {
        std::cout << __LINE__ << std::endl;
    }
    void printCurrFuncName() {
        std::cout << __func__ << "()" << std::endl;
    }
    void printFunction() {
        std::cout << __FUNCTION__ << "()" << std::endl;
    }
    void printPrettyFunction() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    void printLog() {
        std::cout << __func__ << "() in file: " << __FILE__ << " on line " << __LINE__ << std::endl;
    }
}