#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>

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

MyString::MyString(const MyString &a6) : leng(a6.leng), string(a6.string)
{

}

MyString& MyString::operator+ (const MyString& t1)
{
	return this->operator+(t1.string);
}

MyString& MyString::operator+ (char* t1)
{
	if (t1 == NULL) return *this;
	if (string == NULL)
	{
		leng = strlen(t1);
		string = new char[leng + 1];
		strcpy(string, t1);
	}
	else
	{
		leng += strlen(t1);
		string = (char*)realloc(string, (leng + 1) * sizeof(char));
		strcat(string, t1);
	}

	return *this;
}

MyString& MyString::operator+ (std::string t)
{
	return this->operator+((char*)t.c_str());
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

void MyString::shrink_to_fit() {
	leng = strlen(string);
	string = (char*)realloc(string, (leng + 1) * sizeof(char));
	string[leng] = '\0';
}

void MyString::clear()
{
	delete[] string;
	leng = 0;
	string = 0;
}

MyString& MyString::insert(int index, int count, char t)
{
	leng += count;
	char* tmp_str = new char[leng + 1];
	for (int i = 0; i < index; ++i)
	{
		tmp_str[i] = string[i];
	}
	for (int i = index; i < index + count; ++i)
	{
		tmp_str[i] = t;
	}
	for (int i = index + count; i < leng; ++i)
	{
		tmp_str[i] = string[i-count];
	}
	
	if (string)
		string = (char*)realloc(string, sizeof(char) * (leng+1));
	else string = new char[leng+1];
	string = tmp_str;
	string[leng] = '\0';

	return *this;
}

MyString& MyString::insert(int index, std::string t1)
{
	leng +=t1.length();
	char* tmp_str = new char[leng + 1];
	for (int i = 0; i < index; ++i)
	{
		tmp_str[i] = string[i];
	}
	for (int i = index; i < index + (int)(t1.length()); ++i)
	{
		tmp_str[i] = t1[i - index];
	}
	for (int i = index + t1.length(); i < leng; ++i)
	{
		tmp_str[i] = string[i - t1.length()];
	}

	if (string)
		string = (char*)realloc(string, sizeof(char) * (leng + 1));
	else string = new char[leng + 1];
	string = tmp_str;
	string[leng] = '\0';

	return *this;
}

MyString& MyString::insert(int index, std::string t2, int count)
{
	for (int i = 0; i < count; i++)
	{
		insert(index+i, 1, t2[i]);
	}
	return *this;
}

MyString& MyString::erase(int index, int count)
{
	char* tmp = new char[leng + 1];
	strcpy(tmp, string);

	//
	string = (char*)realloc(string, (leng - count + 1) * sizeof(char));
	for (int i = index + count; i < leng; i++)
	{
		string[i - count] = tmp[i];
	}
	leng = leng - count;
	string[leng] = '\0';

	return *this;
}

MyString& MyString::append(int count, char t)
{
	int index = leng;
	for (int i = 0; i < count; i++)
	{
		insert(index + i, 1, t);
	}

	return *this;
}

MyString& MyString::append(char* t1)
{

	int length = strlen(t1);
	for (int i = 0; i < length; i++)
	{
		append(1, t1[i]);
	}

	return *this;
}

MyString& MyString::append(char* t1, int index, int count)
{

	char* tmp = new char[count + 1];
	for (int i = index; i < int(index + count); i++)
	{
		tmp[i - index] = t1[i];
	}
	tmp[count] = '\0';
	append(tmp);

	return *this;
}

MyString& MyString::append (std::string t2)
{
	append((char*)t2.c_str());

	return *this;
}

MyString& MyString::append(std::string t1, int index, int count)
{

	t1 = t1.substr(index, count);
	append(t1);

	return *this;
}

MyString& MyString::replace(int index, int count, char* t2)
{
	erase(index, count);
	insert(index, t2);

	return *this;
}

MyString& MyString::replace(int index, int count, std::string t2)
{
	replace(index, count, (char*)t2.c_str());

	return *this;
}

char* MyString::substr(int index)
{
	MyString tmp(string);
	tmp.erase(0, index);

	return tmp.c_str();
}

char* MyString::substr(int index, int count)
{
	MyString tmp(string);
	tmp.erase(0, index);
	tmp.erase(index + count, tmp.leng);

	return tmp.c_str();
}

bool MyString::equals(const char* t)
{
	for (int i = 0; i < leng; i++)
	{
		if (string[i] != t[i])
			return false;
	}
	return true;
}

long long int MyString::find(const char* t)
{
	int find_string_size = strlen(t);

	for (int i = 0; i < leng - find_string_size + 1; i++)
	{
		MyString tmp(this->substr(i, find_string_size));
		if (tmp.equals(t))
			return i;
	}
	return -1;
}

long long int MyString::find(const char* t, int index)
{
	int find_string_size = strlen(t);

	if (index > leng - find_string_size) return -1;

	for (int i = index; i < leng - find_string_size; i++)
	{
		MyString tmp(this->substr(i, find_string_size));
		if (tmp.equals(t))
			return i;
	}
	return -1;
}

long long int MyString::find(std::string t2)
{
	return find((char*)t2.c_str());
}

long long int MyString::find(std::string t2, int index)
{
	return find((char*)t2.c_str(), index);
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

std::ostream& operator<<(std::ostream &out, const MyString& t)
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
