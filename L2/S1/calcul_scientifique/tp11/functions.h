#ifndef __functions_h
#define __functions_h

#include <string.h>

char intToChar(int a);

std::string convertIntToBase(int x, int b);

std::string convertFloatToBase(int num, int denom, int b);

std::string convertFloatToBinary(float x);

float convertIEEE754ToFloat(std::string x);

std::string convertFloatToIEEE754(float x);

#endif
