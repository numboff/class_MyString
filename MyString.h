#include <string>
#pragma once
class MyString{
	int leng;
	char* string;
public:
	MyString();
	MyString(char* a1);
	MyString(std::string a3);
	MyString(const char* a4, int leng1);
	MyString(int leng2, char a5);
	MyString(MyString &a6);

	MyString& operator+ (const MyString& t1);
	MyString& operator+ (char* t1);
	MyString& operator+ (std::string t1);
	MyString& operator += (std::string t);
	MyString& operator += (char* t);
	MyString& operator += (const MyString& t);
	MyString& operator = (char* t);
	MyString& operator = (std::string t);
	//MyString& operator = (const MyString& t);
	char& operator[](int i);

	char* c_str();
	char* data();
	int size();
	int length();
	int empty();
	int capacity();
	void clear();
	void insert(int index, int count, char t);

	friend bool operator<(const MyString &t1, const MyString &t2);
	friend bool operator>(const MyString &t1, const MyString &t2);
	friend bool operator<=(const MyString &t1, const MyString &t2);
	friend bool operator>=(const MyString &t1, const MyString &t2);
	friend bool operator!=(const MyString &t1, const MyString &t2);
	friend bool operator==(const MyString &t1, const MyString &t2);
	friend std::ostream& operator<< (std::ostream &out, const MyString &t);
	friend std::istream& operator>> (std::istream &out, MyString &t);

	~MyString();
private:
	void AddFunc(int length, int add_length, char* str, char* add_str);
	void AssignFunc(int t_leng, char* t);
	static const int CINLIM = 80;
};