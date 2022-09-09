/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Basics.h
 * Author: default
 *
 * Created on September 5, 2022, 1:46 PM
 */

#ifndef BASICS_H
#define BASICS_H

namespace C02Basics {
    
    struct Vector {
        int size;
        double* elem;
    };

    
    extern void initVector(Vector& v, int s);
    extern double readAndSum(int length);
    
    extern void exampleVector();
    
    //end of struct vector
        
    class MyVector {
        double* elem;       //pointer to the elements
        int count;          // the number of elements
    public:
        MyVector(int s);        //construct a vector
        double& operator [] (int index);
        int size();
    };
    
    extern double readAndSumMyVector(int length);
    
    extern double mySqrt(MyVector& v);
    
    extern void exampleMyVector();
    extern void exampleSqrt();
    //end of class MyVector
    
    
    enum class TrafficLight {
        green,
        yellow,
        red
    };
    
    TrafficLight& operator++ (TrafficLight& curr);
    
   
}

#endif /* BASICS_H */

