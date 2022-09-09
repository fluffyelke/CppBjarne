/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>
#include <iostream>

#include "C03Abstraction.h"


namespace C03Abstractions {
    
    //class Complex methods
    Complex& Complex::operator *= (Complex right) {

    }

    Complex& Complex::operator /= (Complex right) {

    }

    //Complex unary operators
    Complex operator + (Complex left, Complex right) {
        return left += right;
    }
    Complex operator - (Complex left, Complex right) {
        return left -= right;
    }
    Complex operator - (Complex left) {
        return {-left.getReal(), -left.getImaginary()};
    }
    Complex operator * (Complex left, Complex right) {
        return left *= right;
    }
    Complex operator / (Complex left, Complex right) {
        return left /= right;
    }
    bool operator ==(Complex left, Complex right) {
        return (left.getReal() == right.getReal()) && (left.getImaginary() == right.getImaginary());
    }
    bool operator !=(Complex left, Complex right) {
        return !(left == right);
    }
    
    void complexExample() {
        Complex c;
    }
    
    
    
    //class Vector
    template<typename T>
    Vector<T>::Vector(int sz)                  //constructor acquire resources
            : elem{new T[sz]},
              count(sz) {
        }
            
    template<typename T>
    Vector<T>::Vector(std::initializer_list<T> myList) 
        : elem{new T[myList.size()]},
          count{myList.size()}{
            std::copy(myList.begin(), myList.end(),     //source
                      elem);                            //destination
    }
    template<typename T>
    T& Vector<T>::operator[](int index) {
        return elem[index];
    }

    template<typename T>
    std::size_t Vector<T>::getSize() const {
        return count;
    }
    
    template<typename T>
    Vector<T>::Vector(const Vector<T>& obj)       //copy constructor
        : elem{new T[obj.count]},      //allocate space for elements
          count{obj.count}{                 
        
            for(int i = 0; i < count; ++i) {
                elem[i] = obj.elem[i];
            }
            
    }
    
    template<typename T>
    Vector<T>& Vector<T>::operator = (const Vector<T>& obj) {
        T* p = new T[obj.count];
        for(int i = 0; i < obj.count; ++i) {
            p[i] = obj.elem[i];
        }
        delete [] elem;
        elem = p;
        count = obj.count;
        return *this;
    }
    
    template<typename T>
    Vector<T>::Vector(Vector<T>&& obj) 
        : elem{obj.elem},           //grab the elements from obj
          count{obj.count} {
            obj.elem = nullptr;         //now obj has no elements
            obj.count = 0;
    }
    template<typename T>      
    Vector<T>& Vector<T>::operator = (Vector<T>&& obj) {
        
    }
          
    template<typename T>
    T* Vector<T>::begin() {
        return &elem[0];            //pointer to first elem
    }
    template<typename T>
    T* Vector<T>::end() {
        return begin() + getSize(); //pointer to 1 past last element
    }
    //class VectorContainer
    VectorContainer::VectorContainer(std::size_t s) 
        :  v(s) {

    }
    VectorContainer::VectorContainer(std::initializer_list<double> lst) 
        :v(lst) {

    }
    double& VectorContainer::operator[](int index) {
        return v[index];
    }

    std::size_t VectorContainer::getSize() const {
        return v.getSize();
    }

    VectorContainer::~VectorContainer() {

    }

    void useContainer(Container& obj) {
        for(int i = 0; i < obj.getSize(); ++i) {
            std::cout << obj[i] << ' '; 
        }
    }

    
    //ListContainer

    ListContainer::ListContainer() {    //empty list

    }

    ListContainer::ListContainer(std::initializer_list<double> d) 
        : myList{d} {
        
    }

    ListContainer::~ListContainer() {

    }

    double& ListContainer::operator[](int index) {
        for(auto& elem : myList) {
            if(index == 0) {
                return elem;
            }
            --index;
        }
        throw std::out_of_range("ListContainer");
    }

    std::size_t ListContainer::getSize() const {
        return myList.size();
    }

        
    void exampleOfVectorContainer() {
        VectorContainer myVec{10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        useContainer(myVec);
        
        ListContainer lc = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        useContainer(lc);
        
        Vector<double> myVec2 = {5, 10, 15, 20, 25, 30};
        for(auto& elem : myVec2) {
            std::cout << elem << " ";
        }
    }
    
}