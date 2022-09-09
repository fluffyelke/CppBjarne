/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContAndAlgs.h
 * Author: default
 *
 * Created on September 7, 2022, 1:40 PM
 */

#ifndef CONTANDALGS_H
#define CONTANDALGS_H

#include <ostream>
#include <istream>

namespace C04ContAndAlgs {
    struct Entry {
        std::string name;
        int number;
    };
    extern std::ostream& operator << (std::ostream& os, const Entry& obj);
    extern std::istream& operator >> (std::istream& os, Entry& obj);
    
    
     
}

#endif /* CONTANDALGS_H */

