/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: default
 *
 * Created on September 29, 2022, 10:22 AM
 */

#ifndef DATE_H
#define DATE_H

#include <istream>

namespace Obj {
    
    enum class Month {
        January,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December,
    };
        
    Month& operator ++ (Month& obj);
    Month& operator -- (Month& obj);
    
    enum class weekDay {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday,
        sunday,
    };
    weekDay& operator ++ (weekDay& obj);
    weekDay& operator -- (weekDay& obj);
    
    struct Date {

        int day;
        Month currMonth;
        int year;
        weekDay wd;
        
        bool inThePast;
        void addDay();
        void addMonth();
        void addYear();
        
        void substractDay();
        void substractMonth();
        void substractYear();
        
        void nextMonday();
        
        bool isLeapYear();
        
        std::string dayOfTheWeek(Date& obj);
        
        int countLeapYears(Date& obj);
        
        friend std::ostream& operator << (std::ostream& os, const Date& obj);
        friend std::istream& operator >> (std::istream& is, Date& obj);
    };
}
#endif /* DATE_H */

