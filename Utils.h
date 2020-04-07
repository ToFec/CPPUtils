/*
 * Utils.h
 *
 *  Created on: 14.09.2012
 *      Author: fechter
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <typeinfo>

#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif

using namespace std;

#if defined(WIN32) || defined(_WIN32)
	#ifdef COMPILE_MYLIBRARY
	  #define MYLIBRARY_EXPORT __declspec(dllexport)
	#else
	  #define MYLIBRARY_EXPORT __declspec(dllimport)
	#endif
#else
	#define MYLIBRARY_EXPORT
#endif


class MYLIBRARY_EXPORT Utils
{
public:
	virtual ~Utils();
	static Utils getInstance();
	
	static double stringToDouble(string s);
	static double charToDouble(char* c);
	static double unsignedCharToDouble(unsigned char c);
	static int charToInt(char* c);
	static int unsignedCharToInt(unsigned char c);
	static int stringToInt( string s);
	static float stringToFloat(string s);
	static int getIntLength(int i);
	static string intToString(int i);
	static string longToString(long i);
	static string doubleToString(double i);
	static int roundDoubleToInt(double d);
	static int double2IntFloor(double input);
	static int double2IntCeil(double input);
	static int double2Int(double input);
	static short double2short(double input);

	static string getVoidPoitnerValAsString(void* voidPointer,const type_info& typeInfo);
	static void* getPointer(const type_info& typeInfo);
	static string getExePath();
	static char getSeperator();

	const static short fourNeighborHood[18];

private:
	Utils();
};


#endif /* UTILS_H_ */

