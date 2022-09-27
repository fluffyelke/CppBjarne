/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "C10Expressions.h"
#include <iostream>
#include <map>

namespace C10Expressions {
    void examples() {
        
    }
        
    
    TokenStream ts{ std::cin };
    std::map<std::string, double> table;
        
    int noOfErrors = 0;
    double error(const std::string& s) {
        noOfErrors++;
        std::cerr << "error: " << s << std::endl;
        return 1;
    }
    
    Token TokenStream::get() {
        char ch = 0;
        
        do {        //skip whitespaces except '\n'
            if(!is->get(ch)) {
                return ct = { Kind::end };
            }
        }
        while(ch != '\n' && std::isspace(ch));
//        *is >> ch;
        
        switch(ch) {
            case 0:
                return ct = { Kind::end };  //assign and return //equvalent ot token(kind, 0, 0);
            case ';':
            case '*':
            case '/':
            case '+':
            case '-':
            case '(':
            case ')':
            case '=':
                return ct = { static_cast<Kind>(ch) };      //equvalent ot token(kind, 0, 0);
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':   
                is->putback(ch);            // put the first digit or(.) back into input stream
                *is >> ct.numberValue;      //read the number into ct.
                ct.kind = Kind::number;
                return ct;
            default:    //name, name = , or error
                if(std::isalpha(ch)) {
                    ct.stringValue = ch;
                    while(is->get(ch) && std::isalnum(ch)) {
                        ct.stringValue += ch;       //append to the end of stringValue.
                    }
                    is->putback(ch);    //put the character back into the input stream
//                    *is->ct.stringValue;    //read the string into ct
//                    ct.kind = Kind::name; ???
                    return ct;
                }
                error("TokenStream::get(): Bad Token");
                return ct = { Kind::print }; 
        }
    }

    
    void calculator() {
        for(;;) {
            Token t = ts.get();
            if(t.kind == Kind::end) {
                break;
            }
            if(t.kind == Kind::print) {
                continue;
            }
            std::cout << expr(false) << std::endl;
        }
    }
    
    double expr(bool get) {     //add and subtract
        double left = term(get);
        
        while(true) {       //forever
            Token t = ts.get();
            switch(t.kind) {
                case Kind::plus:
                    left += term(true);
                    break;
                case Kind::minus:
                    left -= term(true);
                    break;
                default:
                    return left;
            }
        }
    }
    
    double term(bool get) {     //multiply and divide
        double left = prim(get);
        
        while(true) {       //forever
            Token t = ts.get();
            switch(t.kind) {
                case Kind::multiply:
                    left *= prim(true);
                    break;
                case Kind::divide:
                    if(auto div = prim(true)) {
                        left /= div;
                        break;
                    }
                    return error("Divide by Zero");
                default:
                    return left;
            }
        }
    }
    
    double prim(bool get) {     //handle primaries
        Token t;
        if(get) {
            t = ts.get();       //read next token
        }
        
        switch(t.kind) {
            case Kind::number:  //floating point constant
            {
                double value = t.numberValue;
                t = ts.get();
                return value;
            }
            case Kind::name:
            {
                double& value = table[t.stringValue];    //find the corresponding
                if(t.kind == Kind::assign) {     // '=' seen assign
                    value = expr(true); 
                }
                return value;
            }
            case Kind::minus:           //unary minus
                return -prim(true); 
            case Kind::leftP:
            {
                auto e = expr(true);
                if(t.kind != Kind::rightP) {
                    return error("')' expected");
                }
                t = ts.get();//eat ')'
                return e;
            }
            default:
                return error("primary exptected");
        }
    }
    

    
    void runCalculator() {
        table["pi"] = 3.141592;
        table["e"] = 2.718281;
        
        calculator();
        
        if(noOfErrors) {
            exit(EXIT_FAILURE);
        }
    }
}