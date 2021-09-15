#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString()
{
	string = 0;
	leng = 0;
}

MyString::MyString(char* a1) : leng(strlen(a1)), string(new char[leng+1])
{
	strcpy(string, a1);
	string[leng] = '\0';
}

MyString::MyString(std::string a3) : leng(a3.size()), string(new char[leng + 1])
{
	strcpy(string, a3.c_str());
	string[leng] = '\0';
}

MyString::MyString(const char* a4, int leng1) : leng(leng1), string(new char[leng + 1])
{
	strcpy(string, a4);
	string[leng] = '\0';
}

MyString::MyString(int leng2, char a5) : leng(leng2), string(new char[leng + 1])
{
	for (int i = 0; i < leng; ++i)
	{
		string[i] = a5;
	}
	string[leng] = '\0';
}

MyString::MyString(MyString &a6) : leng(a6.leng), string(a6.string)
{

}

MyString& MyString::operator+ (const MyString& t1)
{
	MyString _temp;                         // временный объект
	delete[] _temp.string;                   // стираем строку, выделенную в конструкторе по умолчанию
	_temp.leng = t1.leng + leng;        // вычисляем длину будущей строки
	_temp.string = new char[_temp.leng + 1];  // выделяем место под новую строку + нулевой символ
	std::strcpy(_temp.string, string);
	std::strcpy(_temp.string + leng, t1.string); // собственно, сцепляем и сохраняем в новый объект
	_temp[leng] = '\0';

	return _temp;
}

MyString& MyString::operator+ (char* t1)
{
	MyString _temp;                         // временный объект
	delete[] _temp.string;                   // стираем строку, выделенную в конструкторе по умолчанию
	_temp.leng = leng + strlen(t1);        // вычисляем длину будущей строки
	_temp.string = new char[_temp.leng + 1];  // выделяем место под новую строку + нулевой символ
	std::strcpy(_temp.string, string);
	std::strcpy(_temp.string + leng, t1); // собственно, сцепляем и сохраняем в новый объект
	_temp[leng] = '\0';

	return _temp;
}

MyString& MyString::operator+ (std::string t)
{
	MyString _temp;                         // временный объект
	delete[] _temp.string;                   // стираем строку, выделенную в конструкторе по умолчанию
	_temp.leng = leng + t.size();        // вычисляем длину будущей строки
	_temp.string = new char[_temp.leng + 1];  // выделяем место под новую строку + нулевой символ

	std::strcpy(_temp.string, string);
	std::strcpy(_temp.string + leng, t.c_str()); // собственно, сцепляем и сохраняем в новый объект
	_temp[leng] = '\0';

	return _temp;
}

MyString& MyString::operator += (std::string t)
{
	AddFunc(leng, t.size(), string, (char*)t.c_str());
	return *this;
}

MyString& MyString::operator += (const MyString& t)
{
	AddFunc(leng, t.leng, string, t.string);
	return *this;
}

MyString& MyString::operator += (char* t)
{
	AddFunc(leng, strlen(t), string, t);
	return *this;
}

//MyString& MyString::operator = (const MyString& t)
//{
//	AssignFunc(t.leng, t.string);
//	return *this;
//}


MyString& MyString::operator = (char* t)
{
	AssignFunc(strlen(t), t);
	return *this;
}

MyString& MyString::operator = (std::string t)
{
	AssignFunc(t.size(), (char*)t.c_str());
	return *this;
}

char& MyString::operator[](int i)
{
	return string[i];
}

char* MyString::c_str()
{
	return string;
}

char* MyString::data()
{
	if (this->string)
	{
		return this->string;
	}
	else
	{
		return NULL;
	}
}

int MyString::size()
{
	return leng;
}
	
int MyString::length()
{
	return size();
}

int MyString::empty()
{
	if (leng == 0)
		return 1;
	else
		return 0;
}

int MyString::capacity()
{
	return sizeof(string);
}

void MyString::clear()
{
	delete[] string;
	leng = 0;
	string = 0;
}

void MyString::insert(int index, int count, char t)
{
	leng += count;
	char* tmp_str = new char[leng + 1];
	for (int i = 0; i < index; ++i)
	{
		tmp_str[i] = string[i];
	}
	for (int i = 0; i < index + count; ++i)
	{
		tmp_str[i] = t;
	}
	for (int i = 0; i < leng; ++i)
	{
		tmp_str[i] = string[i-count];
	}
}

MyString::~MyString()
{
	leng = 0;
	delete[] string;
	string = 0;
}

void MyString::AddFunc(int length, int add_length, char* str, char* add_str)
{
	int new_leng = length + add_length;
	char *newStr = new char[new_leng + 1];
	strcpy(newStr, str);
	strcat(newStr, add_str);
	delete[] string;
	string = newStr;
	leng = new_leng;
}

void MyString::AssignFunc(int t_leng, char* t)
{
	leng = t_leng;
	delete[] string;
	string = new char[leng + 1];
	strcpy(string, t);
	string[leng] = '\0';
}

std::ostream& operator<< (std::ostream &out, const MyString& t)
{
	out << t.string;
	return out;
}

std::istream & operator>>(std::istream & is, MyString & t)
{
	char temp[MyString::CINLIM];
	is.get(temp, MyString::CINLIM);
	if (is)
		t = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

bool operator<(const MyString &t1, const MyString &t2)
{
	return (std::strcmp(t1.string, t2.string) < 0);
}

bool operator>(const MyString &t1, const MyString &t2)
{
	return t2 < t1;
}

bool operator<=(const MyString &t1, const MyString &t2)
{
	return (std::strcmp(t1.string, t2.string) <= 0);
}

bool operator>=(const MyString &t1, const MyString &t2)
{
	return t2 <= t1;
}

bool operator!=(const MyString &t1, const MyString &t2)
{
	return (std::strcmp(t1.string, t2.string) != 0);
}

bool operator==(const MyString &t1, const MyString &t2)
{
	return (std::strcmp(t1.string, t2.string) == 0);
}
