/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C11SelectOperations.h
 * Author: default
 *
 * Created on September 27, 2022, 10:43 AM
 */

#ifndef C11SELECTOPERATIONS_H
#define C11SELECTOPERATIONS_H

#include <ostream>
#include <vector>
#include <functional>
#include <map>

namespace C11SelectOperations {
    
    class ModuloPrint {
        std::ostream& os;   //member to hold capture list.
        int m;
    public:
        ModuloPrint(std::ostream& s, int mm) 
            : os{s},
              m{mm}  {}
              
        void operator () (int x) const{     //capture
            if(x % m == 0) {
                os << x << '\n';
            }
        }
    };
    
    
    extern void printModuloLambda(const std::vector<int>& v, std::ostream& os, int m);
    extern void printModuloFuncObj(const std::vector<int>& v, std::ostream& os, int m);
    extern void printModuloEmbeddedClass(const std::vector<int>& v, std::ostream& os, int m);
    extern void printModuloNamedLambda(const std::vector<int>& v, std::ostream& os, int m);
    
    
    
    class Request {
        std::function<std::map<std::string, std::string>(const std::map<std::string, std::string>&) > operation; //operation
        std::map<std::string, std::string> values;      //arguments
        std::map<std::string, std::string> results;     //targets
    public:
        Request(const std::string& s);      //parse and store request
        
        void execute() {
            [this] () {
                results = operation(values);
            };
        }
    };
    extern void examples();
}

#endif /* C11SELECTOPERATIONS_H */

