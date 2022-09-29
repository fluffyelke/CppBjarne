/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Macros.h
 * Author: default
 *
 * Created on September 28, 2022, 12:38 PM
 */

#ifndef MACROS_H
#define MACROS_H

#include <iostream>


#define PRINT(value) std::cout << #value << " = " << value << std::endl

namespace PreDefMacros {
    extern void printDate();
    extern void printTime();
    extern void printCurrSourceFile();
    extern void printLine();
    extern void printCurrFuncName();
    extern void printFunction();
    extern void printPrettyFunction();
    extern void printLog();
}

#endif /* MACROS_H */

