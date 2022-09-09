/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C03Abstraction.h
 * Author: default
 *
 * Created on September 5, 2022, 4:05 PM
 */

#ifndef C03ABSTRACTION_H
#define C03ABSTRACTION_H

#include <initializer_list>
#include <cstdio>
#include <list>


namespace C03Abstractions {
    // an arithmetic type concrete type
    class Complex {
        double real;
        double imaginary;
        
    public:
        Complex(double r, double im) //complex with 2 scalars
            : real{r},
              imaginary{im} {}
        Complex(double r) //complex with 1 scalars
            : real{r},
              imaginary{0} {}
        Complex() //default
            : real{0},
              imaginary{0} {}      
        
        double getReal() {
            return real;
        }
        void setReal(double d) {
            real = d;
        }
        double getImaginary() {
            return imaginary;
        }
        void setImaginary(double d) {
            imaginary = d;
        }
        
        //operators
        Complex& operator += (Complex right) {
            real += right.real;
            imaginary += right.imaginary;
            return *this;
        }
        Complex& operator -= (Complex right) {
            real -= right.real;
            imaginary -= right.imaginary;
            return *this;
        }
        Complex& operator *= (Complex right);   //defined somewhere outside the class
        Complex& operator /= (Complex right);   //defined somewhere outside the class
    };
    
    extern Complex operator + (Complex left, Complex right);
    extern Complex operator - (Complex left, Complex right);
    extern Complex operator - (Complex left);
    extern Complex operator * (Complex left, Complex right);
    extern Complex operator / (Complex left, Complex right);
    extern bool operator == (Complex left, Complex right);
    extern bool operator != (Complex left, Complex right);
    
    extern void complexExample();
    
    
    //Vector class  concrete type
    template<typename T>
    class Vector {
        T* elem;
        std::size_t count;
    public:
        Vector(int sz);
         
        Vector(std::initializer_list<T>);  //initialize vector with the list
        
        //copy constructors
        Vector(const Vector& obj);                  //copy constructor
        Vector& operator = (const Vector& obj);     //copy assignment operator
            
        //move constructors
        Vector(Vector&& obj);
        Vector& operator = (Vector&& obj);
        
        ~Vector() {             //destructor release resources.
            delete [] elem;
        }
        
        
        //to support range for loops(for each) we must define begin() and end()
        T* begin();
        T* end();
        
        void push_back(T);             //add element at the end increase size by 1.
        T& operator [] (int index);
        std::size_t getSize() const;
    };
    
    
    //abstract types
    class Container {
    public:
        virtual double& operator [] (int) = 0;          //pure virtual function
        virtual std::size_t getSize() const = 0;        //const member function
        virtual ~Container() {}                         //destructor
    };
    
    class VectorContainer : public Container {  //VectorContainer implements Container
        Vector<double> v;
    public:
        VectorContainer(std::size_t s);     //Vector of s elements
        VectorContainer(std::initializer_list<double>);
        
        double& operator[](int) override;
        std::size_t getSize() const override;
        ~VectorContainer();
    };
    
    extern void exampleOfVectorContainer();
    
    class ListContainer : public Container {
        std::list<double> myList;
    public:
        ListContainer();
        ListContainer(std::initializer_list<double>);
        double& operator[](int) override;
        std::size_t getSize() const override;
        ~ListContainer();
    };
}

#endif /* C03ABSTRACTION_H */

