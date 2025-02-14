/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file Crime.cpp
 *  
 * Last modified on February 12, 20245, 15:13 PM
 */

#include "Crime.h"

using namespace std;

/*
 * Initialization of the static string that contains the value assigned to any 
 * string field (string) which is found empty in the data of a Crime
 */
const std::string Crime::UNKNOWN_VALUE = "UNKNOWN";

/*
 * Initialization of the static string that contain the default value for the
 * DateTime field in a Crime 
 */
const string Crime::DATETIME_DEFAULT = "2017-01-20 02:00:00";

/* 
 * Initialization of the static string with the default values for every field in 
 * a Crime
 */
const string Crime::CRIME_DEFAULT("0," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," +
        UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE +
        "," + ((std::string)"1") + "," + Crime::DATETIME_DEFAULT + "," +
        UNKNOWN_VALUE + ",181,181");

Crime::Crime() {
}

Crime::Crime(const string &line) {
}

int Crime::getCounter() const {
}

std::string Crime::getId() const {
}

std::string Crime::getCode() const {
}

std::string Crime::getGroup() const {
}

std::string Crime::getDescription() const {
}

std::string Crime::getDistrict() const {
}

std::string Crime::getStreet() const {
}

std::string Crime::getAreaReport() const {
}

bool Crime::isShooting() const {
}

DateTime Crime::getDateTime() const {
}

Coordinates Crime::getLocation() const {
}

bool Crime::isIDUnknown() const {
}

std::string Crime::toString() const {
}

void Crime::setCounter(int c) {
}

void Crime::setId(const std::string &id) {
}

void Crime::setCode(const std::string &code) {
}

void Crime::setGroup(const std::string &group) {
}

void Crime::setDescription(const std::string &description) {
}

void Crime::setDistrict(const std::string &district) {
}

void Crime::setAreaReport(const std::string &areaReport) {
}

void Crime::setStreet(const std::string &street) {
}

void Crime::setShooting(bool shooting) {
}

void Crime::setDateTime(const string & time) {
}

void Crime::setLocation(const Coordinates & coordinates) {
}

void Crime::set(const std::string & line) {
    const int NFIELDS = 12;
    string data;        //piece of data detached from line;
    size_t pos, posn;   // aux for the beginning of the fields
 
    pos = 0;
    posn = line.find(',', pos); // beginning of the next field
    for (int nfield = 0; nfield < NFIELDS - 1 && posn != string::npos; nfield++) {
        data = line.substr(pos, posn - pos);
        pos = posn + 1;

        switch (nfield) {
            case 0: // counter
                setCounter(stoi(data));
                break;
            case 1: // ID
                setId(data);
                break;
            case 2: // code
                setCode(data);
                break;
            case 3: // group
                setGroup(data);
                break;
            case 4: // desc
                setDescription(data);
                break;
            case 5: // District alphaNumeric
                ...
        }
  ...
} //end of set()

void Trim(string & myString) {
}

void Capitalize(string & myString) {
}

void Normalize(Crime & crime) {
}
