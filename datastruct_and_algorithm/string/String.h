/*
 *Filename:String.h
 *
 *Description:String class header file
 *
 *Author:rutk1t0r
 *
 *Date: 2016.10.04
 *
 *GPL
 *
 */

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class String
{
public:
	String(const char *str = NULL);
	String(const String & other);
	~String();
	String & operator=(const String & other);
private:
	char * m_pData;
};

#endif