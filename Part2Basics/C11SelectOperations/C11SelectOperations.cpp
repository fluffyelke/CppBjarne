/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>

#include "C11SelectOperations.h"


namespace C11SelectOperations {
    void printModuloLambda(const std::vector<int>& v, std::ostream& os, int m) {
        std::for_each(v.cbegin(), v.cend(), 
                      [&os, m](int x) -> void {             //calling lambda as a function object
                         if(x % m == 0) {
                             os << x << '\n';
                         } 
                      });
    }
    void printModuloFuncObj(const std::vector<int>& v, std::ostream& os, int m) {
        std::for_each(v.cbegin(), v.cend(), 
                      ModuloPrint{os, m});          //calling a function object, class with operator () defined.
    }
    void printModuloEmbeddedClass(const std::vector<int>& v, std::ostream& os, int m) {
        class Modulo {
            std::ostream& os;
            int m;
        public:
            Modulo(std::ostream& s, int mm) 
                : os{s},
                    m{mm} {}
            void operator () (int x) {
                if(x % m == 0) {
                    os << x << '\n';
                }
            }
        };  
        std::for_each(v.cbegin(), v.cend(), 
                      Modulo{os, m});
    }
    void printModuloNamedLambda(const std::vector<int>& v, std::ostream& os, int m) {
        auto moduloPrint = [&os, m] (int x) {
            if(x % m == 0) {
                os << x << '\n';
            }
        };
        std::for_each(v.cbegin(), v.cend(),
                     moduloPrint);
    }
    void examples() {
        
    }
}