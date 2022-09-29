/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <functional>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "../../Date/Date.h"
#include "C12Excercises.h"


namespace C12Ex {
    
    void ex01Func1(const char* c, int& num) {
        std::cout << c << " " << num << std::endl;
    }
    
    void (*fp)(const char*, int&);
    
    
    void ex01() {
        fp = &ex01Func1;
        int a = 5;
        fp("psst", a);
        
        using fPtr = void (*) (const char*, int&);
        fPtr one = &ex01Func1;
        one("2psst", a);
        
        auto myFunc = [&a](fPtr obj) {   
            obj("3pssst", a);
        };
        myFunc(one);
        
        auto funcPtr2 = [&one] (const char* c, int& num) {
          return one(c, num);  
        };
        funcPtr2("4psst" , a);
        
        auto funcPtr3 = [] (fPtr obj) {
            obj = &ex01Func1;
            return obj;
        };
        auto funcNew = funcPtr3(one);
        funcNew("5psst", a);
    }
    
    void ex02() {
//        using riffi = int (&) (int)(int);
    }
    
    void ex03(int size, char** arr) {
        for(int i = 1; i < size; ++i) {
            std::cout << "Hello " << arr[i] << "!" << std::endl;
        }
    }
    
    void readFilesFromCommandLine(int size, char** arr) {
        
        for(int i = 1; i < size; ++i) {
            std::ifstream file(arr[i]);
            if(!file.is_open()) {
                std::cerr << "File not Exist: " << arr[i] << std::endl;
            }
            std::cout << file.rdbuf() << std::endl;
            std::cout << "\n\n\n################### NEXT FILE #################\n\n\n";
            std::cout << std::endl;
            file.close();
        } 
    }
    
    
    Tnode* addTNode(const std::string& value, int num) {
        Tnode* tree = new Tnode;
        tree->word = value;
        tree->count = num;
        tree->left = nullptr;
        tree->right = nullptr;
        return tree;
    }
    
    void printTree(Tnode* root) {
        if(root == nullptr) {
            return;
        }
        printTree(root->left);
        std::cout << root->word << ": " << root->count << std::endl;
        printTree(root->right);
    }
    
    void deleteTree(Tnode* root) {
        if(root == nullptr) {
            return;
        }
        deleteTree(root->left);
        std::cout << root->word << ", deleted!" << std::endl;
        deleteTree(root->right);
        delete root;
    }
    
    void ex08() {
        Tnode* head = addTNode("first", 1);     
        head->left = addTNode("second",2);
        head->right = addTNode("third", 3);
        head->left->left = addTNode("fourth", 4);
        head->left->right = addTNode("fifth", 5);
        head->right->left = addTNode("sixth", 6);
        head->right->right = addTNode("seventh", 7);
        
        printTree(head);
        deleteTree(head);
    }
    
    void ex09() {
        auto revertArr = [] (int arr[3][5]) {
            for(int i = 0; i < 3; ++i) {
                int start = 0;
                int end = 5 - 1;
                while(start < end) {
                    std::swap(arr[i][start], arr[i][end]);
                    start++;
                    end--;
                }
            } 
        };
        
        int arr[3][5] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
        };
        auto printArr = [] (int arr[3][5]) {
           for(int i = 0; i < 3; ++i) {
               for(int j = 0; j < 5; ++j) {
                   std::cout << arr[i][j] << " ";
               }
               std::cout << std::endl;
           }  
        };
        
        printArr(arr);
        revertArr(arr);
        std::cout << "\n\n after invert\n";
        printArr(arr);
    }
    
    void ex10(int size, char** arr) {
        std::string encrypt = arr[1];
        std::string line = "";
        std::getline(std::cin, line);
        std::string result = "";
        for(int i = 0; i < line.length(); ++i) {
            std::string temp = "";
            temp += line[i] + encrypt;
            result.append(temp);
        }
        std::cout << line << std::endl;
        std::cout << result << std::endl;
        //wencrypthencryptaencrypttencrypt encryptwencryptiencryptlencryptlencrypt encrypthencryptaencryptpencryptpencrypteencryptnencrypt encryptnencryptoencryptwencrypt
        
        std::cout << "Re-Encrypt" << std::endl;
        std::string encrWord = arr[1];
        std::size_t keyWord = result.find(encrWord.c_str(), 0);
        while(keyWord != std::string::npos){
            result.erase(keyWord, encrWord.length());
            keyWord = result.find(encrWord.c_str(), 0);
        }
        std::cout << result << std::endl;
    }
    
    void ex21() {
//        Obj::Date d;
//        std::cin >> d;
//        std::cout << d;
        
        Obj::Date currentDate;
        currentDate.day = 29;
        currentDate.currMonth = Obj::Month::September;
        currentDate.year = 2022;
        currentDate.wd = Obj::weekDay::thursday;
        
        Obj::Date checkDate;
        checkDate.day = 9;
        checkDate.currMonth = Obj::Month::May;
        checkDate.year = 1945;
        
        std::cout << currentDate.dayOfTheWeek(checkDate) << std::endl;

        currentDate.day = 29;
        currentDate.currMonth = Obj::Month::September;
        currentDate.year = 2022;
        currentDate.wd = Obj::weekDay::thursday;
        std::cout << currentDate << std::endl;
        currentDate.nextMonday();
        std::cout << "Next Monday: " << currentDate << std::endl;
        
        
    }
}