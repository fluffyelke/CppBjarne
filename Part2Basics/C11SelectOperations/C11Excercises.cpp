/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <numeric>
#include "C11Excercises.h"


namespace C11Ex {
    void ex01() {
        std::vector<int*> elements;
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

        try {
            while(true) {
                int* arr = new int[100000];
                elements.push_back(arr);
                arr[0] = 1;
            }
        }
        catch(std::bad_alloc) {
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
            std::cerr << "Not enough memory!" << std::endl;
        }
    }

    void accumulate1() {
        
        std::vector<int> myVec;
        double sum = 0;
        for(int i = 0; i < 100000000; ++i){
            myVec.push_back(i);
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        for(int i = 0; i < myVec.size(); ++i) {
            sum += myVec[i];
        }
        std::cout << "accumulate1()" << std::endl;
        std::cout << "Total Sum: " << sum << std::endl;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
        
    }
    
    void accumulate2() {
        std::vector<int> myVec;
        double sum = 0;
        for(int i = 0; i < 100000000; ++i){
            myVec.push_back(i);
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        for(auto& elem : myVec) {
            sum += elem;
        }
        std::cout << "accumulate2()" << std::endl;
        std::cout << "Total Sum: " << sum << std::endl;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
       
    }
    
    void accumulate3() {
        std::vector<int> myVec;
        double sum = 0;
        for(int i = 0; i < 100000000; ++i){
            myVec.push_back(i);
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        std::for_each(myVec.cbegin(), myVec.cend(), 
                     [&sum](int value) {
                        sum += value; 
                     });
        std::cout << "accumulate3()" << std::endl;
        std::cout << "Total Sum: " << sum << std::endl;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
       
    }
    
    void accumulate4() {
        class Sum {
        public:
            void operator () (int value) {
                sum += value;
            }
            int sum{0};
        };
        std::vector<int> myVec;
        double sum = 0;
        for(int i = 0; i < 100000000; ++i){
            myVec.push_back(i);
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        std::for_each(myVec.cbegin(), myVec.cend(), 
                     Sum());
        std::cout << "accumulate4()" << std::endl;
        std::cout << "Total Sum: " << sum << std::endl;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
       
    }
    
    void accumulate5() {
        class Sum {
        public:
            void operator () (int value) {
                sum += value;
            }
            int sum{0};
        };
        std::vector<int> myVec;
        double sum = 0;
        for(int i = 0; i < 100000000; ++i){
            myVec.push_back(i);
        }
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        std::accumulate(myVec.cbegin(), myVec.cend(), 
                        sum);
        std::cout << "accumulate5()" << std::endl;
        std::cout << "Total Sum: " << sum << std::endl;
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::cout << "Total time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "ms" << std::endl;
       
    }
    
    void ex02() {
        accumulate1();
        accumulate2();
        accumulate3();
        accumulate4();
        accumulate5();
    }
    
    void apply(const std::vector<int>& myVec, const std::function<void(int)> op) {
        for(auto& elem : myVec) {
            op(elem);
        }
    }
    
    void testApply(int elem) {
        std::cout << elem << " ";
    }
    
    void ex03() {
        std::vector<int> myVec = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
        std::cout << "testApply(): ";
        apply(myVec, testApply);
        std::cout << std::endl;
        
        class Temp {
        public:
            void operator () (int elem) {
                std::cout << elem << " ";
            }
        };
        
        std::cout << "Function object: ";
        apply(myVec, Temp());
        std::cout << std::endl;
        
        std::cout << "Lambda: ";
        apply(myVec, [] (int elem) {
            std::cout << elem << " ";
        });
        std::cout << std::endl;
    }
    
    void ex04() {
        
    }
}