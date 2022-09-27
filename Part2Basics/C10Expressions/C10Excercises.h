/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C10Excercises.h
 * Author: default
 *
 * Created on September 26, 2022, 1:22 PM
 */

#ifndef C10EXCERCISES_H
#define C10EXCERCISES_H

#include <vector>


namespace C10Ex {
    extern void ex02();
    
    extern int myStrlen(const char* str);
    
    extern void myStrcpy(const char* from, char* to);

    extern int myStrcmp(const char* left, const char* right);
    
    extern char* myConcat(const char* left, const char* right, int length);
    
    extern void myReverse(char str[]);
    
    extern void ex07();
    
    extern void ex09();
    
    extern void ex10();
    
    extern void copyFromIntToVec(int arr[], std::vector<int>& dest);
    
    extern void ex11();
}

#endif /* C10EXCERCISES_H */

