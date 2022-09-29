/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <ostream>
#include <iostream>
#include "../utils/Macros.h"
#include "Date.h"


namespace Obj {
    
    std::string convertMonthToString(Month currMonth) {
        switch(currMonth) {
            case Month::January: return "January";
            case Month::February: return "February";
            case Month::March: return "March";
            case Month::April: return "April";
            case Month::May: return "May";
            case Month::June: return "June";
            case Month::July: return "July";
            case Month::August: return "August";
            case Month::September: return "September";
            case Month::October: return "October";
            case Month::November: return "November";
            case Month::December: return "December";
        }
    }

    void setCurrentMonth(int n, Date& obj) {
        switch(n) {
            case 1:
                obj.currMonth = Month::January;
                break;
            case 2:
                obj.currMonth = Month::February;
                break;
            case 3:
                obj.currMonth = Month::March;
                break;
            case 4:
                obj.currMonth = Month::April;
                break;
            case 5:
                obj.currMonth = Month::May;
                break;
            case 6:
                obj.currMonth = Month::June;
                break;
            case 7:
                obj.currMonth = Month::July;
                break;
            case 8:
                obj.currMonth = Month::August;
                break;
            case 9:
                obj.currMonth = Month::September;
                break;
            case 10:
                obj.currMonth = Month::October;
                break;
            case 11:
                obj.currMonth = Month::November;
                break;
            case 12:
                obj.currMonth = Month::December;
                break;
        }
    }
    
    std::string convertWeekDayToString(weekDay currDay) {
        switch(currDay) {
            case weekDay::monday: return "Monday";
            case weekDay::tuesday: return "Tuesday";
            case weekDay::wednesday: return "Wednesday";
            case weekDay::thursday: return "Thursday";
            case weekDay::friday: return "Friday";
            case weekDay::saturday: return "Saturday";
            case weekDay::sunday: return "Sunday";

        }
    }
    
    void setCurrentWeekDay(int n, Date& obj) {
        switch(n) {
            case 1:
                obj.wd = weekDay::monday;
                break;
            case 2:
                obj.wd = weekDay::tuesday;
                break;
            case 3:
                obj.wd = weekDay::wednesday;
                break;
            case 4:
                obj.wd = weekDay::thursday;
                break;
            case 5:
                obj.wd = weekDay::friday;
                break;
            case 6:
                obj.wd = weekDay::saturday;
                break;
            case 7:
                obj.wd = weekDay::sunday;
                break;
        }
    }
    
    bool Date::isLeapYear() {
        if(year % 4 != 0) {
            return false;
        }
        else if(year % 400 == 0) {
            return true;
        }
        else if(year % 100 == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    
    void Date::addDay() {
        day++;
        ++wd;
        switch(currMonth) {
            case Month::February:
                if(isLeapYear()) {
                    if(day == 30) {
                        day = 1;
                        addMonth();
                    }
                    else if(day > 30) {
                        std::cerr << "Invalid day: " << day << std::endl;
                        PreDefMacros::printLog();
                        day = 1;
                    }
                }
                else {
                    if(day == 29) {
                        day = 1;
                        addMonth();
                    }
                    else if(day > 29){
                        std::cerr << "Invalid day: " << day << std::endl;
                        PreDefMacros::printLog(); 
                        day = 1;
                    }
                }
                break;
                
            case Month::January:
            case Month::March:
            case Month::May:
            case Month::July:
            case Month::August:
            case Month::October:
            case Month::December:
                if(day == 32) {
                    day = 1;
                    if(currMonth == Month::December) {
                        addYear();
                    }
                    addMonth();
                }
                else if(day > 32) {
                    std::cerr << "Invalid day: " << day << std::endl;
                    PreDefMacros::printLog(); 
                    day = 1;
                }
                break;
                
            default:
                if(day == 31) {
                    day = 1;
                    addMonth();
                }
                else if(day > 31) {
                    std::cerr << "Invalid day: " << day << std::endl;
                    PreDefMacros::printLog(); 
                    day = 1;
                }
                break;
        }
    }
    
    void Date::substractDay() {
        --day;
        --wd;
        switch(currMonth) {
            case Month::March:
                if(isLeapYear()) {
                    if(day == 0) {
                        day = 29;
                        substractMonth();
                    }
                    else if(day < 0) {
                        std::cerr << "Invalid day: " << day << std::endl;
                        PreDefMacros::printLog();
                        day = 1;
                    }
                }
                else {
                    if(day == 0) {
                        day = 28;
                        substractMonth();
                    }
                    else if(day < 0){
                        std::cerr << "Invalid day: " << day << std::endl;
                        PreDefMacros::printLog(); 
                        day = 1;
                    }
                }
                break; 
            case Month::January:
            case Month::February:
            case Month::April:
            case Month::June:
            case Month::August:
            case Month::September:
            case Month::November:
                if(day == 0) {
                    day = 31;
                    substractMonth();
                    if(currMonth == Month::December) {
                        substractYear();
                    }
                }
                else if(day < 0) {
                    std::cerr << "Invalid day: " << day << std::endl;
                    PreDefMacros::printLog(); 
                    day = 1;
                }
                break;
                
            default:
                if(day == 0) {
                    day = 30;
                    substractMonth();
                }
                else if(day < 0) {
                    std::cerr << "Invalid day: " << day << std::endl;
                    PreDefMacros::printLog(); 
                    day = 1;
                }
                break;
        }
    }
    Month& operator ++ (Month& obj) {
        switch(obj) {
            case Month::January:
                return obj = Month::February;
            case Month::February:
                return obj = Month::March;
            case Month::March:
                return obj = Month::April;
            case Month::April:
                return obj = Month::May;
            case Month::May:
                return obj = Month::June;
            case Month::June:
                return obj = Month::July;
            case Month::July:
                return obj = Month::August;
            case Month::August:
                return obj = Month::September;
            case Month::September:
                return obj = Month::October;
            case Month::October:
                return obj = Month::November;
            case Month::November:
                return obj = Month::December;
            case Month::December:
                return obj = Month::January;
        }
    }
    Month& operator -- (Month& obj) {
        switch(obj) {
            case Month::January:
                return obj = Month::December;
            case Month::February:
                return obj = Month::January;
            case Month::March:
                return obj = Month::February;
            case Month::April:
                return obj = Month::March;
            case Month::May:
                return obj = Month::April;
            case Month::June:
                return obj = Month::May;
            case Month::July:
                return obj = Month::June;
            case Month::August:
                return obj = Month::July;
            case Month::September:
                return obj = Month::August;
            case Month::October:
                return obj = Month::September;
            case Month::November:
                return obj = Month::October;
            case Month::December:
                return obj = Month::November;
        }
    }

    weekDay& operator ++ (weekDay& obj) {
        switch(obj) {
            case weekDay::monday:
                return obj = weekDay::tuesday;
            case weekDay::tuesday:
                return obj = weekDay::wednesday;
            case weekDay::wednesday:
                return obj = weekDay::thursday;
            case weekDay::thursday:
                return obj = weekDay::friday;
            case weekDay::friday:
                return obj = weekDay::saturday;
            case weekDay::saturday:
                return obj = weekDay::sunday;
            case weekDay::sunday:
                return obj = weekDay::monday;
        }
    }
    weekDay& operator -- (weekDay& obj) {
        switch(obj) {
            case weekDay::monday:
                return obj = weekDay::sunday;
            case weekDay::tuesday:
                return obj = weekDay::monday;
            case weekDay::wednesday:
                return obj = weekDay::tuesday;
            case weekDay::thursday:
                return obj = weekDay::wednesday;
            case weekDay::friday:
                return obj = weekDay::thursday;
            case weekDay::saturday:
                return obj = weekDay::friday;
            case weekDay::sunday:
                return obj = weekDay::saturday;
        }
    }
    
    void Date::addMonth() {
        ++currMonth;
    }

    void Date::addYear() {
        ++year;
    }
    void Date::substractMonth() {
        --currMonth;
    }
    void Date::substractYear() {
        --year;
    }
    
    void Date::nextMonday() {
        while(wd != weekDay::monday) {
            ++wd;
            addDay();
        }
    }
    
    int Date::countLeapYears(Date& obj) {
        int count = 0;
        bool forwardTime = false;
        if(year < obj.year) {
            forwardTime = true;
        }
        if(forwardTime) {
            for(int i = year; i < obj.year; ++i) {
                if(isLeapYear()) {
                    count++;
                }
            }
        }
        else {
            for(int i = obj.year; i > year; --i) {
                if(isLeapYear()) {
                    count++;
                }
            }
        }
        return count;
    }

    std::string Date::dayOfTheWeek(Date& obj) {
        
        int countDays = 0;
        bool inThePast = false;
        obj.wd = wd;
        while(year != obj.year) {
            countDays++;
            if(year < obj.year) {
                addDay();  
            }
            else {
                inThePast = true;
                substractDay();
            }
        }
        while(currMonth != obj.currMonth) {
            countDays++;
            if(currMonth < obj.currMonth) {
                addDay();
            }
            else {
                inThePast = true;
                substractDay();
            }
        }
        while(day != obj.day) {
            countDays++;
            if(day < obj.day) {
                addDay();
            }
            else {
                inThePast = true;
                substractDay();
            }
        }

        for(int i = 0; i < countDays; ++i) {
            if(inThePast) {
                obj.substractDay();
            }
            else {
                obj.addDay();
            }
        }
        return convertWeekDayToString(obj.wd);
    }
    
    
    std::ostream& operator << (std::ostream& os, const Date& obj) {
        
        os << convertWeekDayToString(obj.wd) << " " << obj.day << " " << convertMonthToString(obj.currMonth) << " " <<  obj.year;
        return os;
    }

    std::istream& operator >> (std::istream& is, Date& obj) {
        std::cout << "Input a day: ";
        is >> obj.day;
        std::cout << "Input a month from [1:12]: ";
        int month = 0;
        is >> month;
        setCurrentMonth(month, obj);
        std::cout << "Input a year: ";
        is >> obj.year;
        std::cout << "Input current week day from [1:7]: ";
        int d = 0;
        is >> d;
        setCurrentMonth(d, obj);
        return is;
    }

}