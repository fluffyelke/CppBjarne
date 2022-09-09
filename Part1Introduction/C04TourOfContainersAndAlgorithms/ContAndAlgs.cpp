/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <ostream>
#include <istream>
#include "ContAndAlgs.h"


namespace C04ContAndAlgs {
    
    std::ostream& operator << (std::ostream& os, const Entry& obj) {
        return os << "{\"" << obj.name << "\"," << obj.number << "}";
    }
    
    std::istream& operator >> (std::istream& is, Entry& obj) {
        //read {"name", number}
        char c, c2;
        if(is >> c && c == '{' && is >> c2 && c2 == '"') {  //start with { "
            std::string name;   
            
            while(is.get(c) && c != '"') {
                name += c;
            }
            
            if(is >> c && c == ',') {
                int number = 0;
                if(is >> number && c == '}') {      //read the number and a }
                    obj = {name, number};   //assign to the entry
                    return is;
                }
            }
        }
        is.setstate(std::ios_base::failbit);    //register the failure in the stream
        return is;
    }
}