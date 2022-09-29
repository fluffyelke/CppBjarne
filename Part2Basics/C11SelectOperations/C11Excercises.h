/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C11Excercises.h
 * Author: default
 *
 * Created on September 27, 2022, 3:17 PM
 */

#ifndef C11EXCERCISES_H
#define C11EXCERCISES_H

#include <functional>


namespace C11Ex {
    
    extern void ex01();
    
    extern void ex02();
    
    extern void apply(const std::vector<int>& myVec, const std::function<void(int)> op);
    
    extern void ex03();
    
    extern void ex04();
}

#endif /* C11EXCERCISES_H */

