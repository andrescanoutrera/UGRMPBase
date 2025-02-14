/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file Coordinate.cpp  
 * 
 * Last modified on February 12, 20245, 15:03 PM
 */

#include "Coordinates.h"

const float Coordinates::INVALID_COORDINATE=181.0;

using namespace std;


Coordinates::Coordinates(float latitude, float longitude) {
}

float Coordinates::getLatitude() const {
}

float Coordinates::getLongitude() const {
}

bool Coordinates::isValid() const {
}

void Coordinates::set(float latitude, float longitude){
}

void Coordinates::setLatitude(float latitude) {
}

void Coordinates::setLongitude(float longitude) {
}

std::string Coordinates::toString() const {
}

Coordinates Coordinates::length(const Coordinates &second) const{
}                        

bool Coordinates::isInsideArea(const Coordinates &bottomLeft, const Coordinates &topRight) const {
}  
