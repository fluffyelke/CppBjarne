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
#include "utils/ImprovedAlgs.h"
#include "RNGGenerator.h"
#include "Part1Introduction/C02CppBasics/Basics.h"
#include "Part1Introduction/C02CppBasics/X3Excercises.h"
#include "Part1Introduction/C03AbstractionMechanisms/C03Abstraction.h"
#include "Part1Introduction/C04TourOfContainersAndAlgorithms/C04Excercises.h"
#include "Part1Introduction/C05TourOfConcurrencyAndUtilities/C05Excercises.h"
#include "Part2Basics/C06TypesAndDeclaration/C06TypesAndDeclaration.h"
#include "Part2Basics/C07PtrsArraysReferences/PtrsArraysAndRefs.h"
#include "Part2Basics/C08StructuresUnionsEnums/StructsUnionsEnums.h"
#include "Part2Basics/C09Statements/C09Statements.h"
#include "Part2Basics/C09Statements/C09Excercises.h"
#include "Part2Basics/C10Expressions/C10Expressions.h"
#include "Part2Basics/C10Expressions/C10Excercises.h"
#include "Part2Basics/C11SelectOperations/C11SelectOperations.h"

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

void c06Types() {
    auto typesC06 = [] () -> void {
//        C06Types::exam01();
//        C06Types::exam02();
//        C06Types::exam03();
//        C06Types::exam04();
        C06Types::largestAndSmallest();
    };
    
    typesC06();
}

void c07PtrsArraysAndReferences() {
    auto run = [] () -> void {
//        C07Ptrs::examples();
//        C07Ptrs::exam02();
//        C07Ptrs::exam04();
//        C07Ptrs::exam07();
//        C07Ptrs::exam09();
//        C07Ptrs::exam10();
//        C07Ptrs::exam11();
        C07Ptrs::exam12();
    };
    run();
}


void c08StructuresUnionsEnumerations() {
    auto run = [] () -> void {
//        C08Structs::examples();
//        C08Structs::exam01();
//        C08Structs::exam02();
//        C08Structs::exam04();
        C08Structs::exam05();
    };
    
    run();
}

void c09Statements() {
    auto runExamples = [] () -> void {
        C09Statements::examples();
    };
    
    runExamples();
    
    auto runExcercises = [] () -> void {
//        C09Ex::exam01();
//        C09Ex::exam04();
//        C09Ex::exam05();
        C09Ex::stripComments("Part2Basics/C09Statements/C09Statements.cpp");
    };
    
    runExcercises();
}

void c10Expressions() {
    auto runExamples = [] () -> void {
//        C10Expressions::examples();
//        C10Expressions::runCalculator();
    };
    
    auto runEx = [] () -> void {
//        C10Ex::ex02();
//        C10Ex::ex07();
//        C10Ex::ex09();
//        C10Ex::ex10();
        C10Ex::ex11();
    };
//    runExamples();
    
    runEx();
}

void c11SelectOps() {
    auto runExamples = [] () -> void {
        C11SelectOperations::examples();
    };
    
    runExamples();
}
void part02() {
    
//    c06Types();
//    c07PtrsArraysAndReferences();
//    c08StructuresUnionsEnumerations();
//    c09Statements();
//    c10Expressions(); 
    c11SelectOps();
}

int main(int argc, char** argv) {

    part02();

    return 0;
}

