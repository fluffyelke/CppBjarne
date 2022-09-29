/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TEA.h
 * Author: default
 *
 * Created on September 29, 2022, 10:04 AM
 */

#ifndef TEA_H
#define TEA_H

#include <stdint.h>


namespace Encrypt {
    extern void encrypt(uint32_t v[2], const uint32_t k[4]);
    extern void decrypt(uint32_t v[2], const uint32_t k[4]);
}

#endif /* TEA_H */

