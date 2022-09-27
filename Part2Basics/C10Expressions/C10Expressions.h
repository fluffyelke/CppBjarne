/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C10Expressions.h
 * Author: default
 *
 * Created on September 21, 2022, 3:42 PM
 */

#ifndef C10EXPRESSIONS_H
#define C10EXPRESSIONS_H

#include <istream>


namespace C10Expressions {
    extern void examples();
    
    enum class Kind : char {
        name,
        number,
        end,
        plus = '+',
        minus = '-',
        multiply = '*',
        divide = '/',
        print = ',',
        assign = '=',
        leftP = '(',
        rightP = ')'
    };
    
    struct Token {
        Kind kind;
        std::string stringValue;
        double numberValue;
    };
    
    class TokenStream {
    public:
        TokenStream(std::istream& s) 
            : is(&s),
              owns(false) {
                
            }
        TokenStream(std::istream* s) 
            : is(s),
              owns(true) {
                
            } 
        ~TokenStream() {
            close();
        }
        
        Token get();        //read and return next token
        const Token& current();    //most recently read token.
        
        void setInput(std::istream& s){
            close();
            is = &s;
            owns = false;
        }
        void setInput(std::istream* s){
            close();
            is = s;
            owns = true;
        }
        
    private:
        
        void close() {
            if(owns){
                delete is;
            }
        }
        
        std::istream* is;           //pointer to an input stream
        bool owns;                  //does TokenStream own the stream?
        Token ct{Kind::end};        //curent token           
    };
    
    extern double expr(bool get);
    extern double term(bool get);
    extern double prim(bool get);
    
    
    extern void calculator();
    
    extern void runCalculator();
}

#endif /* C10EXPRESSIONS_H */

