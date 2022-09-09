/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ImprovedAlgs.h
 * Author: default
 *
 * Created on September 7, 2022, 4:36 PM
 */

#ifndef IMPROVEDALGS_H
#define IMPROVEDALGS_H

#include <algorithm>


namespace Utils {
    
    /**
     * Improved sort using just name of the container
     * example Utils::sort(myVector);
     * @param obj
     */
    template<typename T>
    void sort(T& obj) {
        std::sort(obj.begin(), obj.end());
    }
    
    template<typename T, typename Pred>
    void sort(T& obj, Pred op) {
        std::sort(obj.begin(), obj.end(), op);
    }
}

#endif /* IMPROVEDALGS_H */

