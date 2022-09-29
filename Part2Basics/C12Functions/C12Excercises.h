/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C12Excercises.h
 * Author: default
 *
 * Created on September 28, 2022, 1:46 PM
 */

#ifndef C12EXCERCISES_H
#define C12EXCERCISES_H

namespace C12Ex {
    
    extern void ex01();
    
    extern void ex02();
    
    extern void ex03(int size, char** arr);
    
    extern void readFilesFromCommandLine(int size, char** arr);
    
    struct Tnode {
        std::string word;
        int count;
        Tnode* left;
        Tnode* right;
    };
    
    Tnode* addTNode(const std::string& value, int num);
    
    void printTree(Tnode* root);
    void deleteTree(Tnode* root);
    
    void ex08();
    
    void ex09();
    
    void ex10(int size, char** arr);
    
    void ex21();
}

#endif /* C12EXCERCISES_H */

