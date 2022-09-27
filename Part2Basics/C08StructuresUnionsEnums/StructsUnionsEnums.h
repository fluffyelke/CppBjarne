/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StructsUnionsEnums.h
 * Author: default
 *
 * Created on September 20, 2022, 12:00 PM
 */

#ifndef STRUCTSUNIONSENUMS_H
#define STRUCTSUNIONSENUMS_H

#include <istream>


namespace C08Structs {
    extern void examples();
    
    struct Address {
        const char* name;       // "Jim Dandy"
        int number;             // 61
        const char* street;     // "South Str"
        const char* town;       // "New Providence"
        char state[2];          // 'N' 'J'
        const char* zip;        // "07974"
    };
    
    struct Readout {
        char hour;
        int value;
        char seq;
    };
    struct ReadoutOptimized {
        int value;
        char hour;
        char seq;
    };
    
    struct Address2 {
        std::string name;       // "Jim Dandy"
        int number;             // 61
        std::string street;     // "South Str"
        std::string town;       // "New Providence"
        char state[2];          // 'N' 'J'
        char zip[5];        // 07974
    };
    
    //simplified std::array
    template<typename T, std::size_t N>
    class array {
        T elem[N];
        
        T* begin() noexcept {
            return elem;
        }
        const T* begin() const noexcept {
            return elem;
        } 
        T* end() noexcept {
            return elem + N;
        }
        const T* end() const noexcept {
            return elem + N;
        } 
        
        constexpr std::size_t size() noexcept;
        
        T& operator [] (std::size_t index) {
            return elem[index];
        }
        const T& operator [] (std::size_t index) const {
            return elem[index];
        }
        
        T* data() noexcept {
            return elem;
        }
        const T* data() const noexcept {
            return elem;
        }
        ///...
    };
    
    //the default enum type is int
    enum class Color : int{
        red,
        blue,
        green,
    };
    //we can specify to use char
    enum class TraficLight : char {
        red,
        blue,
        green,
    };
    
    
    //using enum as bits
    enum class PrinterFlags {
        aknowledge = 1,
        paperEmptry = 2,
        busy = 4,
        outOfBlack = 8,
        outOfColor = 16,
    };
    constexpr PrinterFlags operator | (PrinterFlags a, PrinterFlags b) {
        return static_cast<PrinterFlags>(static_cast<int>(a) | static_cast<int>(b));
    }
    constexpr PrinterFlags operator & (PrinterFlags a, PrinterFlags b) {
        return static_cast<PrinterFlags>(static_cast<int>(a) & static_cast<int>(b));
    }
    
    extern void tryToPrint(PrinterFlags flag);
    
    
    struct SizeOfStruct {
        long double ld;
        double d;
        char c;
        int i;
        bool b;
        long l;
    };
    
    extern void exam01();
    
    struct Year {
        const char* month;
        int days;
    };
    
    extern void exam02();
    
    struct Date {
        int year;
        std::string month;
        int day;
    };
    std::istream& operator >> (std::istream& is, Date& obj);
    std::ostream& operator << (std::ostream& os, const Date& obj);
    
    extern void exam04();
    
    enum class Seasons {
        spring,
        summer,
        autumn,
        winter
    };
    Seasons& operator ++ (Seasons& obj);
    Seasons& operator -- (Seasons& obj);
    std::ostream& operator << (std::ostream& os, const Seasons& obj);
//    std::istream& operator >> (std::istream& is, Seasons& obj);
    extern void exam05();
}

#endif /* STRUCTSUNIONSENUMS_H */

