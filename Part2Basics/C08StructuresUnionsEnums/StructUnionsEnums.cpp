/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "StructsUnionsEnums.h"


namespace C08Structs {
    void examples() {
        auto f = [] () -> void {
            Address jd;
            jd.name = "Jim Dandy";
            jd.number = 61;
        };
        
        f();
        Address myJD = {
          "Jim Dandy", 
          61,
          "South Str",
          "New Providence",
          {'J', 'N'},
          "07974"
        };
        
        auto printAddressPtr = [] (Address* adr) {
            std::cout << (*adr).name << '\n'                          //note adr->name, is equivalent of (*adr).name
                << adr->number << ' ' << adr->street << '\n'
                << adr->town << '\n' 
                << adr->state[0] << adr->state[1]
                << ' ' << adr->zip << std::endl;
        };
        printAddressPtr(&myJD);
        
        auto printAddressRef = [] (const Address& adr) {
            std::cout << adr.name << '\n'                          
                << adr.number << ' ' << adr.street << '\n'
                << adr.town << '\n' 
                << adr.state[0] << adr.state[1]
                << ' ' << adr.zip << std::endl;
        };
        printAddressRef(myJD);
        
        std::cout << sizeof(Readout) << std::endl;
        std::cout << sizeof(ReadoutOptimized) << std::endl;
        
        
        std::cout << "Color Size: " <<sizeof(Color) << std::endl;
        std::cout << "Trafic Size: " <<sizeof(TraficLight) << std::endl;
    }
    
    void tryToPrint(PrinterFlags flag) {
//        if(flag & PrinterFlags::aknowledge) {
//            //do something
//        }
//        else if(flag & PrinterFlags::busy) {
//            
//        }
//        else if(flag & (PrinterFlags::outOfBlack | PrinterFlags::outOfColor)) {
//            // do something
//        }
    }
    
    void exam01() {
        std::cout << "sizeof long double: " << sizeof(long double) << std::endl;
        std::cout << "sizeof double: " << sizeof(double) << std::endl;
        std::cout << "sizeof long: " << sizeof(long) << std::endl;
        std::cout << "sizeof int: " << sizeof(int) << std::endl;
        std::cout << "sizeof char: " << sizeof(char) << std::endl;
        std::cout << "sizeof bool: " << sizeof(bool) << std::endl;
        
        std::cout << "size of SizeOfStruct: " << sizeof(SizeOfStruct) << std::endl;
    }
    
    
    void exam02() {
        const char* months[] = {
          "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"  
        };
        const int days[] = {
          31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,   
        };
        
        auto printMonths = [] (const char** m, const int* d, std::size_t length) {
            for(int i = 0; i < length; ++i) {
                std::cout << m[i] << ": " << d[i] << std::endl;
            }
        };
        
        printMonths(months, days, sizeof(months)/sizeof(months[0]));
        
        Year year[12];
        for(int i = 0; i < 12; ++i) {
            year[i] = {months[i], days[i]};
        }
        auto printYear = [] (const Year& y) {
            std::cout << y.month << ": " << y.days;
        }; 
        for(int i = 0; i < sizeof(year)/sizeof(year[0]); ++i) {
            printYear(year[i]);
            std::cout << std::endl;
        }
    }
    
    std::istream& operator >> (std::istream& is, Date& obj) {
        is >> obj.year >> obj.month >> obj.day;
        return is;
    }
    std::ostream& operator << (std::ostream& os, const Date& obj) {
        os << obj.year << "/" << obj.month << "/" << obj.day;
        return os;
    }
    
    void exam04() {
        Date dates[5];
        std::size_t length = sizeof(dates) / sizeof(dates[0]);
        for(int i = 0; i < length; ++i) {
            std::cin >> dates[i];
        }
        
        for(int i = 0; i < length; ++i ) {
            std::cout << dates[i] << std::endl;
        }
    }
    
    Seasons& operator ++ (Seasons& obj) {
        switch(obj) {
            case Seasons::spring:
                return obj = Seasons::summer;
            case Seasons::summer:
                return obj = Seasons::autumn;
            case Seasons::autumn:
                return obj = Seasons::winter;
            case Seasons::winter:
                return obj = Seasons::spring;
        }
    }
    Seasons& operator -- (Seasons& obj) {
        switch(obj) {
            case Seasons::spring:
                return obj = Seasons::winter;
            case Seasons::summer:
                return obj = Seasons::spring;
            case Seasons::autumn:
                return obj = Seasons::summer;
            case Seasons::winter:
                return obj = Seasons::autumn;
        }
    }
    
    std::ostream& operator << (std::ostream& os, const Seasons& obj) {
        
        auto convertToString = [] (const Seasons& obj) -> std::string {
            switch(obj) {
                case Seasons::spring:
                    return "Spring";
                case Seasons::summer:
                    return "Summer";
                case Seasons::autumn:
                    return "Autumn";
                case Seasons::winter:
                    return "Winter";
            } 
        };
        return os << convertToString(obj);
    }
    

    std::istream& operator >> (std::istream& is, Seasons& obj) {
        std::cout << "Choose a season from: [Spring, Winter, Autumn, Winter]: ";
        std::string temp = "";
        is >> temp;
        auto convertStrToSeasons = [] (const std::string& str) -> Seasons {
            if(str == "Spring") {
                return Seasons::spring;
            }  
            else if(str == "Summer") {
                return Seasons::summer;
            }
            else if(str == "Autumn") {
                return Seasons::autumn;
            }
            else if(str == "Winter"){
                return Seasons::winter;
            }
        };
        obj = convertStrToSeasons(temp);
        return is;
    }
    void exam05() {
        Seasons obj = Seasons::winter;
        std::cout << obj << std::endl;
        obj = ++obj;
        std::cout << obj << std::endl;
        obj = ++obj;
        std::cout << obj << std::endl;
        obj = ++obj;
        std::cout << obj << std::endl;
        obj = ++obj;
        std::cout << obj << std::endl;
        obj = --obj;
        std::cout << obj << std::endl;
        obj = --obj;
        std::cout << obj << std::endl;
        
        Seasons runTimeSeason;
        std::cin >> runTimeSeason;
        std::cout << runTimeSeason << std::endl;
    }
}