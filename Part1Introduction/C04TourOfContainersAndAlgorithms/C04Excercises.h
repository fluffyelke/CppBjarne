/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C04Excercises.h
 * Author: default
 *
 * Created on September 7, 2022, 4:42 PM
 */

#ifndef C04EXCERCISES_H
#define C04EXCERCISES_H

#include <ostream>


namespace C04Exercises {
    extern void readNameAndNumber();
    
    class NameNumber {
    public:
        std::string name;
        int number;
    };
    extern std::ostream& operator << (std::ostream& os, const NameNumber& obj);
    extern std::istream& operator >> (std::istream& is, NameNumber& obj);
    extern void excercise06();
    
    extern void excercise07();
    
    extern void excercise08();
}

#endif /* C04EXCERCISES_H */

