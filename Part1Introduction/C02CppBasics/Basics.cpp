/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <complex>

#include "Basics.h"


namespace C02Basics {
    void initVector(Vector& v, int s) {
        v.elem = new double[s];
        v.size = s;
    }
    double readAndSum(int length) {
        Vector v;
        initVector(v, length);
        
        for(int i = 0; i < length; ++i) {
            std::cin >> v.elem[i];
        }
        
        double sum = 0; 
        for(int i = 0; i < length; ++i) {
            sum += v.elem[i];
        }
        return sum;
    }
    
    void exampleVector() {
        double result = readAndSum(10);
        std::cout << "Total sum is: " << result << std::endl;
    }
    

    //end of Vector
    
    
    //Beginning of MyVector
    MyVector::MyVector(int s) 
        : elem{new double[s]},
          count{s} {}        //construct a vector
          
    double& MyVector::operator [] (int index) {
        return elem[index];
    } 
    
    int MyVector::size() {
        return count;
    }

    double readAndSumMyVector(int length) {
        MyVector v(length);

        for(int i = 0; i < length; ++i) {
            std::cin >> v[i];
        }
        
        double sum = 0; 
        for(int i = 0; i < length; ++i) {
            sum += v[i];
        }
        return sum;
    }
    
    void exampleMyVector() {
        double result = readAndSum(10);
        std::cout << "Total sum is: " << result << std::endl;
    }

    double mySqrt(MyVector& v) {
        double sum = 0;
        for(int i = 0; i < v.size(); ++i) {
            sum += std::sqrt(v[i]);
        }
        return sum;
    }
    
    void exampleSqrt() {
        MyVector v(10);
        for (int i = 0; i < v.size(); ++i) {
            std::cin >> v[i];
        }
        double squaredSum = mySqrt(v);
        std::cout << "Squared sum is: " << squaredSum << std::endl;
    }
    
    //end of MyVector
    TrafficLight& operator ++ (TrafficLight& curr) {
        switch(curr) {
            case TrafficLight::green: 
                return curr = TrafficLight::yellow;
            case TrafficLight::yellow: 
                return curr = TrafficLight::red;
            case TrafficLight::red:
                return curr =TrafficLight::green;
        }
    }
}