#include "MyString.h"

MyString::MyString() : leng(0), capa(0), string(nullptr)
{

}

MyString::MyString(const char* char_element) : MyString(char_element, strlen(char_element))
{

}

MyString::MyString(const std::string string_element) : leng(string_element.size()), capa(leng+1), string(new char[leng + 1])
{
	strcpy(string, string_element.c_str());
	string[leng] = '\0';
}

MyString::MyString(const char* char_element, const int count) : leng(count), capa(leng+1), string(new char[leng + 1])
{
	strcpy(string, char_element);
	string[leng] = '\0';
}

MyString::MyString(const int count, const char char_element) : leng(count), capa(leng+1), string(new char[leng + 1])
{
	for (int i = 0; i < leng; ++i)
	{
		string[i] = char_element;
	}
	string[leng] = '\0';
}

MyString::MyString(const MyString &mystring_element) : leng(mystring_element.leng), capa(leng+1)
{
	std::copy(mystring_element.string, mystring_element.string + mystring_element.leng, string);
}

MyString::MyString(MyString&& mystring_element) : leng(0), capa(leng + 1), string(nullptr)
{
	leng = mystring_element.leng;
	capa = mystring_element.capa;
	string = mystring_element.string;

	mystring_element.leng = 0;
	mystring_element.capa = leng + 1;
	mystring_element.string = nullptr;
}

MyString::~MyString()
{
	delete[] string;
}

MyString MyString::operator+ (const MyString& mystring_elem) const//
{
	MyString tmp;
	tmp.leng = this->leng + mystring_elem.leng;
	tmp.capa = tmp.leng + 1;
	tmp.string = new char[tmp.capa];
	strcpy(tmp.string, this->string);
	for (int i = 0; i < tmp.leng; i++)
		tmp.string[this->leng + i] = mystring_elem.string[i];
	tmp.string[tmp.leng] = '\0';
	return tmp;
}

MyString MyString::operator+ (const char* char_elem) const//
{
	MyString tmp(char_elem);
	return operator+(tmp);
} // переписать

MyString MyString::operator+ (const std::string string_elem) const//
{
	MyString tmp(string_elem);
	return operator+(tmp);
}

MyString& MyString::operator += (const std::string string_elem)
{
	MyString tmp(string_elem);
	return operator+=(tmp);
}

MyString& MyString::operator += (const MyString& mystring_elem)
{
	append(mystring_elem.string);
	return *this;
}

MyString& MyString::operator += (const char* char_elem)
{
	MyString tmp(char_elem);
	return operator+=(tmp);
}

MyString& MyString::operator = (const MyString& mystring_elem)
{
	if (mystring_elem.leng >= capa)
	{
		leng = mystring_elem.leng;
		capa = mystring_elem.capa;
		delete[] string;
		string = new char[leng + 1];
		strcpy(string, mystring_elem.string);
		string[leng] = '\0';
	}
	else
	{
		leng = mystring_elem.leng;
		strcpy(string, mystring_elem.string);
	}
	return *this;
}


MyString& MyString::operator = (const char* char_elem)
{
	MyString tmp(char_elem);
	return operator=(tmp);
}

MyString& MyString::operator = (const char char_elem)
{
	if (capa < 2)
	{
		if (string != nullptr)
			delete[] string;
		capa = 2;
		string = new char[capa];
	}
	leng = 1;
	string[0] = char_elem;
	string[1] = '\0';

	return *this;
}

MyString& MyString::operator = (std::string string_elem)
{
	MyString tmp(string_elem);
	return operator=(tmp);
}

char& MyString::operator[](int i)
{
	return string[i];
}

char* MyString::c_str() const
{
	return string;
}

char* MyString::data() const
{
	return this->c_str();
}

int MyString::size() const
{
	return leng;
}
	
int MyString::length() const
{
	return size();  
}

bool MyString::empty() const
{
	return (leng == 0 ? true : false);
}

int MyString::capacity() const
{
	return sizeof(string);
}

void MyString::shrink_to_fit()
{
	if (leng + 1 != capa)
	{
		char* buffer = new char[this->capa];
		strcpy(buffer, string);
		delete[] string;
		capa = leng + 1;	//buffer
		string = new char[capa];
		strcpy(string, buffer);
		delete[] buffer;
	}
}

void MyString::clear()
{
	delete[] string;
	leng = 0;
	string = 0;
}

MyString& MyString::insert(int index, char char_elem)
{
	if (capa < leng + 2)
	{
		delete[] string;
		string = new char[capa + 1];
		capa += 1;
	}
	leng += 1;
	char* tmp_str = new char[leng + 1];
	for (int i = 0; i < index; ++i)
	{
		tmp_str[i] = string[i];
	}
	tmp_str[index] = char_elem;
	for (int i = index + 1; i < leng; ++i)
	{
		tmp_str[i] = string[i - 1];
	}
	strcpy(string, tmp_str);
	return *this;
}

MyString& MyString::insert(int index, int count, char char_elem)
{
	for (int i = 0; i < count; i++)
	{
		insert(index, char_elem);
	}

	return *this;
}

MyString& MyString::insert(int index, std::string string_elem)
{
	for (int i = 0; i < string_elem.size(); i++)
	{
		insert(index, string_elem[i]);
	}

	return *this;
}

MyString& MyString::insert(int index, std::string string_elem, int count)
{
	for (int i = 0; i < count; i++)
	{
		insert(index, string_elem[i]);
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

MyString& MyString::append(int count, char char_elem)
{
	int index = leng;
	for (int i = 0; i < count; i++)
	{
		insert(index + i, 1, char_elem);
	}

	return *this;
}

MyString& MyString::append(char* char_elem)
{

	int length = strlen(char_elem);
	for (int i = 0; i < length; i++)
	{
		append(1, char_elem[i]);
	}

	return *this;
}

MyString& MyString::append(char* char_elem, int index, int count)
{

	char* tmp = new char[count + 1];
	for (int i = index; i < int(index + count); i++)
	{
		tmp[i - index] = char_elem[i];
	}
	tmp[count] = '\0';
	append(tmp);

	return *this;
}

MyString& MyString::append (std::string string_elem)
{
	append((char*)string_elem.c_str());

	return *this;
}

MyString& MyString::append(std::string string_elem, int index, int count)
{

	string_elem = string_elem.substr(index, count);
	append(string_elem);

	return *this;
}

MyString& MyString::replace(int index, int count, char* char_elem)
{
	erase(index, count);
	insert(index, char_elem);

	return *this;
}

MyString& MyString::replace(int index, int count, std::string string_elem)
{
	replace(index, count, (char*)string_elem.c_str());

	return *this;
}

char* MyString::substr(int index) const
{
	MyString tmp(string);
	tmp.erase(0, index);

	return tmp.c_str();
}

char* MyString::substr(int index, int count) const
{
	MyString tmp(string);
	tmp.erase(0, index);
	tmp.erase(index + count, tmp.leng);

	return tmp.c_str();
}

bool MyString::equals(const char* char_elem)
{
	for (int i = 0; i < leng; i++)
	{
		if (string[i] != char_elem[i])
			return false;
	}
	return true;
}

long long int MyString::find(const char* char_elem) const
{
	int find_string_size = strlen(char_elem);

	for (int i = 0; i < leng - find_string_size + 1; i++)
	{
		MyString tmp(this->substr(i, find_string_size));
		if (tmp.equals(char_elem))
			return i;
	}
	return -1;
}

long long int MyString::find(const char* char_elem, int index) const
{
	int find_string_size = strlen(char_elem);

	if (index > leng - find_string_size) return -1;

	for (int i = index; i < leng - find_string_size; i++)
	{
		MyString tmp(this->substr(i, find_string_size));
		if (tmp.equals(char_elem))
			return i;
	}
	return -1;
}

long long int MyString::find(std::string string_elem) const
{
	return find((char*)string_elem.c_str());
}

long long int MyString::find(std::string string_elem, int index) const
{
	return find((char*)string_elem.c_str(), index);
}

void MyString::AddFunc(const int length, const int add_length, const char* str,const char* add_str)
{
	int new_leng = length + add_length;
	char *newStr = new char[new_leng + 1];
	strcpy(newStr, str);
	strcat(newStr, add_str);
	delete[] string;
	string = newStr;
	leng = new_leng;
}

std::ostream& operator<<(std::ostream &out, const MyString& mystring_elem)
{
	if (mystring_elem.string != nullptr)
		return (out << mystring_elem.string);
	else
		return out << "";
}

std::istream & operator>>(std::istream & in, MyString& mystring_elem)
{
	const int length = 1000;
	char tmp[length];

	in.get(tmp, length);

	if (in)
		mystring_elem = tmp;
	while (in && in.get() != '\n')
		continue;

	mystring_elem.leng = strlen(tmp);
	mystring_elem.capa = mystring_elem.leng + 1;

	return in;
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
