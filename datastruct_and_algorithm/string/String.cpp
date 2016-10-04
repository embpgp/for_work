/*
 *Filename:String.cpp
 *
 *Description:String class source file
 *
 *Author:rutk1t0r
 *
 *Date: 2016.10.04
 *
 *GPL
 *
 */

#include "String.h"

String::String(const char *str)
{
	if(NULL == str)
	{
		m_pData = new char[1];
		*m_pData = '\0';
	}
	else
	{
		m_pData = new char[strlen(str) + 1];
		strcpy(m_pData, str);
	}
}

//拷贝构造函数,必须定义成引用类型,否则逻辑上和实现上都不可行
String::String(const String & other)
{
	m_pData = new char[strlen(other.m_pData) + 1];
	strcpy(m_pData, other.m_pData);
}


String::~String()
{
	delete []m_pData;
}

//重载赋值运算符,参考了剑指offer,考虑到了new新的对象的时候抛出异常的情况
String & String::operator=(const String & other)
{
	if(*this != other)
	{
		String strTemp(other);   //strTemp为零时对象,超出作用范围的时候将被析构掉
		char *pTemp = other.m_pData;  //此处为"狸猫换太子"
		m_pData = other.m_pData;
		other.m_pData = pTemp;
	}
	return *this;
}
