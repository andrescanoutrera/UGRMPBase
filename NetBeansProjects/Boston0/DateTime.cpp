/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file DateTime.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on September 17, 2024, 5:43 PM
 */

#include <iostream>
#include <sstream>
#include "DateTime.h"

#include "Crime.h"

using namespace std;

/*
 * Initialization of a static string with the default value for a 
 * DateTime object 
 */
const string DateTime::DATETIME_STRING_DEFAULT="2000-01-01 00:00:00"; 

/*
 * Initialization of an array of string with the names of the days of the 
 * week
 */
const string DateTime::DAY_NAMES [] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", 
                                "THURSDAY", "FRIDAY", "SATURDAY"};

DateTime::DateTime() {
    initDefault();
}

DateTime::DateTime(const string & line) {
    set(line);
}

void DateTime::initDefault() {
    set(DATETIME_STRING_DEFAULT);
}

bool isCorrect(int year, int month, int day, int hour, int min, int sec) {
    bool ok;
    int lastDay = 31; // by default length of the month
    if (month == 4 || month == 6 || month == 9 || month == 11)
        lastDay = 30;
    else if (month == 2) { // february
        lastDay = 28;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) // leap year
            lastDay = 29;
    }
    ok = (month >= 1 && month <= 12) &&(day > 0 && day <= lastDay) && 
            (hour >= 0 && hour < 24) && (min >= 0 && min < 60) && 
            (sec >= 0 && sec < 60);
    return ok;
}

void split(const std::string& line, int &y, int & m, int & d, int & h, int &mn, int &s) {
    string line2;
    try {
        line2 = line.substr(line.find_first_not_of(" \t")); // to remove initial spaces
        y = stoi(line2.substr(0, 4));
        m = stoi(line2.substr(5, 2));
        d = stoi(line2.substr(8, 2));
        h = stoi(line2.substr(11, 2));
        mn = stoi(line2.substr(14, 2));
        s = stoi(line2.substr(17, 2));
    } catch (const std::invalid_argument &e) {
        split(DateTime::DATETIME_STRING_DEFAULT, y, m, d, h, mn, s);
    }
}

void DateTime::set(const std::string & line) {
    int year, month, day, hour, min, sec;
    split(line, year, month, day, hour, min, sec);
    if (isCorrect(year, month, day, hour, min, sec)) {
        _year = year;
        _month = month;
        _day = day;
        _hour = hour;
        _min = min;
        _sec = sec;
    } else
        initDefault();
}

int DateTime::year() const {
    return _year;
}

int DateTime::month() const {
    return _month;
}

int DateTime::day() const {
    return _day;
}

int DateTime::hour() const {
    return _hour;
}

int DateTime::minutes() const {
    return _min;
}

int DateTime::seconds() const {
    return _sec;
}

string DateTime::toString() const {
    char local[64];
    sprintf(local, "%04i-%02i-%02i %02i:%02i:%02i", _year, _month, _day, _hour, _min, _sec);
    return local;
}

int DateTime::weekDay() const {
    int a = (14 - _month) / 12;
    int y = _year - a;
    int m = _month + 12 * a - 2;
    int wDay;
    wDay = (_day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    return wDay;
}

const string& DateTime::dayName(int day){
     if(day<0 || day>6){
         throw std::invalid_argument(
            std::string("void DateTime::dayName(int day): ") +
            "day is not correct " + to_string(day));
     }
     return DAY_NAMES[day];
 }

bool operator<(const DateTime& dateTime1, const DateTime& dateTime2) {
    bool result = false;
    if (dateTime1.toString() < dateTime2.toString()) {
        result = true;
    }
    return result;
}

bool operator>(const DateTime& dateTime1, const DateTime& dateTime2) {
    return dateTime2<dateTime1;
}

bool operator==(const DateTime& dateTime1, const DateTime& dateTime2) {
    return dateTime1.toString() == dateTime2.toString();
}

bool operator!=(const DateTime& dateTime1, const DateTime& dateTime2) {
    return !(dateTime1 == dateTime2);
}

bool operator<=(const DateTime& dateTime1, const DateTime& dateTime2) {
    return dateTime1 < dateTime2 || dateTime1 == dateTime2;
}

bool operator>=(const DateTime& dateTime1, const DateTime& dateTime2) {
    return dateTime1 > dateTime2 || dateTime1 == dateTime2;
}