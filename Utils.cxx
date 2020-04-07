/*
 * Utils.cpp
 *
 *  Created on: 14.09.2012
 *      Author: fechter
 */

#include "../CPPUtils/Utils.h"

const short Utils::fourNeighborHood[18] = {1,0,0,
			0,1,0,
			0,-1,0,
			-1,0,0,
			0,0,1,
			0,0,-1};

Utils::Utils()
{
}

Utils::~Utils()
{
}

Utils Utils::getInstance()
{
	static Utils _utils;
	return _utils;
}

double Utils::stringToDouble(string s)
{
	istringstream strstr(s);
	double d;
	strstr >> d;
	return d;
}

float Utils::stringToFloat(string s)
{
	istringstream strstr(s);
	float f;
	strstr >> f;
	return f;
}

int Utils::stringToInt(string s)
{
	istringstream strstr(s);
	int i;
	strstr >> i;
	return i;
}

int Utils::getIntLength(int i)
{
	unsigned int length = 0;
	i = ::abs(i);
	for (unsigned char c = 1; c < 10; c++)
	{
		if (i < pow(10.0, c))
		{
			length += c;
			break;
		}
	}
	return length;
}

string Utils::intToString(int i)
{
	std::stringstream strstr;
	strstr << i;
	return strstr.str();
}

string Utils::doubleToString(double d)
{
	std::stringstream strstr;
	strstr << d;
	return strstr.str();
}

int Utils::roundDoubleToInt(double d)
{
	if (d > 0)
	{
		return (int)(d + 0.5);
	}
	else
	{
		return (int)(d - 0.5);
	}
}

string Utils::getVoidPoitnerValAsString(void* voidPointer,
		const type_info& typeInfo)
{
	if (typeInfo == typeid(int))
	{
		int value = *(int*)voidPointer;
		return Utils::intToString(value);
	}
	else if (typeInfo == typeid(double))
	{
		double value = *(double*)voidPointer;
		return Utils::doubleToString(value);
	}
	else
	{
		int value = *(int*)voidPointer;
		return Utils::intToString(value);
	}
}

void* Utils::getPointer(const type_info& typeInfo)
{
	if (typeInfo == typeid(int))
	{
		return new int(0);
	}
	else if (typeInfo == typeid(double))
	{
		return new double(0.0);
	}
	else
	{
		return new int(0);
	}
}

int Utils::double2IntFloor(double input)
{
    return input; //TODO
}

int Utils::double2IntCeil(double input)
{
    return ceil(input); //TODO
}

int Utils::double2Int(double input)
{
    return input<0?input-.5:input+.5; //TODO
}

short Utils::double2short(double input)
{
	double roundVal = input<0?input-.5:input+.5;
	if (roundVal > SHRT_MAX)
	{
		return SHRT_MAX;
	}
	else if (roundVal < SHRT_MIN)
	{
		return SHRT_MIN;
	}
    return (short) roundVal;
}


double Utils::charToDouble(char* c)
{
	std::istringstream strstr(c);
	double d;
	strstr >> d;
	return d;
}

int Utils::charToInt(char* c)
{
	std::istringstream strstr(c);
	int d;
	strstr >> d;
	return d;
}

double Utils::unsignedCharToDouble(unsigned char c)
{
	double d = c;
	return d;
}

int Utils::unsignedCharToInt(unsigned char c)
{
	int i = c;
	return i;
}

string Utils::longToString(long i)
{
	std::stringstream strstr;
	strstr << i;
	return strstr.str();
}

string Utils::getExePath()
{
	 char cCurrentPath[FILENAME_MAX];
	 if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	 {
		 return "";
	 }
	 return string( cCurrentPath );
}

char Utils::getSeperator()
{
#ifdef _WIN32
    return '\\';
#else
    return '/';
#endif
}
