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
	MyString(const MyString &a6);

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
	void shrink_to_fit();
	void clear();

	MyString& insert(int index, int count, char t);
	MyString& insert(int index, std::string t1);
	MyString& insert(int index, std::string t2, int count);

	MyString& erase(int index, int count);

	MyString& append(int count, char t);
	MyString& append(char* t1);
	MyString& append(char* t1, int index, int count);
	MyString& append(std::string t2);
	MyString& append(std::string t2, int index, int count);

	MyString& replace(int index, int count, char* t1);
	MyString& replace(int index, int count, std::string t2);

	char* substr(int index);
	char* substr(int index, int count);

	bool equals(const char* str);

	long long int find(const char* t);
	long long int find(const char* t, int index);
	long long int find(std::string t2);
	long long int find(std::string t2, int index);

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