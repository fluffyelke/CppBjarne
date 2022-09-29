/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TEA.h"


namespace Encrypt {
    void encrypt(uint32_t v[2], const uint32_t k[4]) {
        //set up
        uint32_t v0 = v[0];
        uint32_t v1 = v[1];
        uint32_t sum = 0;
        uint32_t i;
        
        //a key scheduled constant
        uint32_t delta = 0x9E3779B9;
        
        //cache key
        uint32_t k0 = k[0];
        uint32_t k1 = k[1];
        uint32_t k2 = k[2];
        uint32_t k3 = k[3];
        
        //basic cycle start
        for(i = 0; i < 32; ++i) {
            sum += delta;
            v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
            v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
        }
        v[0] = v0;
        v[1] = v1;
    }
    
    void decrypt(uint32_t v[2], const uint32_t k[4]) {
        //set up
        uint32_t v0 = v[0];
        uint32_t v1 = v[1];
        uint32_t sum = 0xC6EF3720;  // sum is (delta << 5) & 0xFFFFFFFF 
        uint32_t i;
        
        //a key scheduled constant
        uint32_t delta = 0x9E3779B9;
        
        //cache key
        uint32_t k0 = k[0];
        uint32_t k1 = k[1];
        uint32_t k2 = k[2];
        uint32_t k3 = k[3];
        
        //basic cycle start
        for(i = 0; i < 32; ++i) {
            v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
            v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
            sum -= delta;
        }
        v[0] = v0;
        v[1] = v1;
    }
}