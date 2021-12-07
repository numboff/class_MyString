#ifndef STRING_CLASS_MYSTRING_H_
#define STRING_CLASS_MYSTRING_H_

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class MyString{
	int leng;
	int capa;
	char* string;
public:
	static const int NOT_AN_IDENTIFIER = -1;

	MyString();
	MyString(const char* char_element);
	MyString(const std::string string_element);
	MyString(const char* char_element, const int count);
	MyString(const int count, const char char_element);
	MyString(const MyString& mystring_element);
	MyString(MyString&& mystring_element);
	~MyString();

	MyString operator+ (const MyString& mystring_elem) const;
	MyString operator+ (const char* char_elem) const;//
	MyString operator+ (const std::string string_elem) const;//
	MyString& operator += (const std::string string_element);
	MyString& operator += (const char* char_element);
	MyString& operator += (const MyString& mystring_element);
	MyString& operator = (const char* char_element);
	MyString& operator = (const char char_element);
	MyString& operator = (const std::string string_element);
	MyString& operator = (const MyString& mystring_elem);
	char& operator[](int index);

	char* c_str() const;
	char* data() const;
	int size() const;
	int length() const;
	bool empty() const;
	int capacity() const;
	void shrink_to_fit();
	void clear();

	MyString& insert(int index, char char_elem);
	MyString& insert(int index, int count, char char_elem);
	MyString& insert(int index, std::string string_elem);
	MyString& insert(int index, std::string string_elem, int count);

	MyString& erase(int index, int count);

	MyString& append(int count, char char_elem);
	MyString& append(char* char_elem);
	MyString& append(char* char_elem, int index, int count);
	MyString& append(std::string string_elem);
	MyString& append(std::string string_elem, int index, int count);

	MyString& replace(int index, int count, char* char_elem);
	MyString& replace(int index, int count, std::string string_elem);

	char* substr(int index) const;
	char* substr(int index, int count) const;

	bool equals(const char* str);

	long long int find(const char* char_elem) const;
	long long int find(const char* char_elem, int index) const;
	long long int find(std::string string_elem) const;
	long long int find(std::string string_elem, int index) const;

	friend bool operator<(const MyString &mystring_elem1, const MyString &mystring_elem2);
	friend bool operator>(const MyString &mystring_elem1, const MyString &mystring_elem2);
	friend bool operator<=(const MyString &mystring_elem1, const MyString &mystring_elem2);
	friend bool operator>=(const MyString &mystring_elem1, const MyString &mystring_elem2);
	friend bool operator!=(const MyString &mystring_elem1, const MyString &mystring_elem2);
	friend bool operator==(const MyString &mystring_elem1, const MyString &mystring_elem2);
	friend std::ostream& operator<< (std::ostream &out, const MyString &mystring_elem);
	friend std::istream& operator>> (std::istream &out, MyString &mystring_elem);

private:
	void AddFunc(const int length, const int add_length, const char* str, const char* add_str);
};

#endif