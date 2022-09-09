/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C05Excercises.h
 * Author: default
 *
 * Created on September 9, 2022, 3:16 PM
 */

#ifndef C05EXCERCISES_H
#define C05EXCERCISES_H

#include <random>


namespace C05ConcurrencyEx {
    
    extern void excercise02();
    extern void runEx02(int times);
    
    extern void excercise03(int times);
    
    
    class RandInt {
    public:
        RandInt(int from, int to);
        
        int operator() ();
    private:
        std::default_random_engine dre;
        std::uniform_int_distribution<> dist;
    };
    
    void excercise04();
    
    void excercise05();
}

#endif /* C05EXCERCISES_H */

