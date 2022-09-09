/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: default
 *
 * Created on September 5, 2022, 1:10 PM
 */

#include <cstdlib>
#include "RNGGenerator.h"
#include "Part1Introduction/C02CppBasics/Basics.h"
#include "Part1Introduction/C02CppBasics/X3Excercises.h"
#include "Part1Introduction/C03AbstractionMechanisms/C03Abstraction.h"
#include "Part1Introduction/C04TourOfContainersAndAlgorithms/C04Excercises.h"
#include "Part1Introduction/C05TourOfConcurrencyAndUtilities/C05Excercises.h"

using namespace std;

/*
 * 
 */

void p01Chapter02() {
    auto basics = [] () -> void {
//        C02Basics::exampleVector();
//        C02Basics::exampleMyVector();
//        C02Basics::exampleSqrt();
        C02Basics::ex05();
        C02Basics::ex06();
    };
    basics();
}
void p01Chapter03() {
    auto abstractions = [] () -> void {
//        C03Abstractions::complexExample();  
        C03Abstractions::exampleOfVectorContainer();
    };
    abstractions();
}

void p01chapter04() {
    auto contsAndAlgs = [] () -> void {
//        C04Exercises::readNameAndNumber();
//        C04Exercises::excercise06();
//        C04Exercises::excercise07();
        C04Exercises::excercise08();
    };
    contsAndAlgs();
}

void p01Chapter05() {
    auto run = [] () -> void {
//        C05ConcurrencyEx::runEx02(5);
//        C05ConcurrencyEx::excercise03(1000000000);
//        C05ConcurrencyEx::excercise04();
        C05ConcurrencyEx::excercise05();
    };
    
    run();
}

void part01() {
//    p01Chapter02();
//    p01Chapter03();
//    p01chapter04();
    p01Chapter05();
}

int main(int argc, char** argv) {

    part01();
    
    return 0;
}

