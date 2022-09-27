/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PtrsArraysAndRefs.h
 * Author: default
 *
 * Created on September 19, 2022, 2:18 PM
 */

#ifndef PTRSARRAYSANDREFS_H
#define PTRSARRAYSANDREFS_H

namespace C07Ptrs {
    extern void examples();
    
    extern void exam01();
    
    extern void exam02();
    
    extern void exam03();
    
    template<typename T> 
    int distance(T* first, T* second) {
        if(first == second) {
            return 0;
        }
        return second - first;
    }
    
    extern void exam04();
    
    extern void exam07();
           
    extern void exam09();
    
    extern void exam10();
    
    extern void exam11();
    
    extern void exam12();
}

#endif /* PTRSARRAYSANDREFS_H */

