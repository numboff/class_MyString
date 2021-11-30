#include "MyString.h"
#include <iostream>
#include <stdio.h>

int main()
{
	std::string a = "abc", b = "cbd";
	MyString a1("a"), a2("b"), a3("c");

	std::cout << a1 << std::endl;

	a1+= a2;
	std::cout << a1 << std::endl;

	a1 = a1 + "hello world";
	std::cout << a1 << std::endl;

	a2 = (b + a);
	std::cout << a2 + a << std::endl;

	a2.insert(2, 5, 'l');
	std::cout << a2 << std::endl;

	a2.insert(1, "lllll");
	std::cout << a2 << std::endl;

	a2.insert(10, "lllll", 2);
	std::cout << a2 << std::endl;

	a2.insert(1, a);
	std::cout << a2 << std::endl;

	a2.insert(10, a, 3);
	std::cout << a2 << std::endl;

	std::cout << a2[13] << std::endl;

	a2.erase(1, 10);
	std::cout << a2 << std::endl;

	MyString a6;
	a6.clear();
	a6.append(3, '!');
	std::cout << a6 << std::endl;

	a1.append(3, '@');
	std::cout << a1 << std::endl;

	a2.clear();
	a2.append("Hello ");
	std::cout << a2 << std::endl;
	
	a2.append("world");
	std::cout << a2 << std::endl;

	a3.clear();
	a3.append("Hello world", 0, 6);
	std::cout << a3 << std::endl;
	
	a3.append("Hello world", 6, 5);
	std::cout << a3 << std::endl;

	MyString a4;
	std::string s1 = "Hello ", s2 = "world";
	a4.clear();
	a4.append(s1);
	std::cout << a4 << std::endl;
	
	a4.append(s2);
	std::cout << a4 << std::endl;

	MyString a5;
	std::string s3 = "Hello world";
	a5.clear();
	a5.append(s3, 0, 6);
	std::cout << a5 << std::endl;

	a5.append(s3, 6, 5);
	std::cout << a5 << std::endl;

	MyString a7("hello amazing world");
	a7.replace(6, 7, "wonderful");
	std::cout << a7 << std::endl;

	MyString a8("hello amazing world");
	std::string s10 = "wonderful";
	a8.replace(6, 7, s10);
	std::cout << a8 << std::endl;

	std::cout << a8.c_str() << std::endl;

	MyString a11("hello amazing world"), a12;
	a12 = a11.substr(6);
	std::cout << a12 << std::endl;

	MyString a13("hello amazing world"), a14;
	a14 = a13.substr(6, 7);
	std::cout << a14 << std::endl;

	std::cout << a13 << std::endl;

	int i;
	i = a13.find("amazing");
	std::cout << i << std::endl;

	return 0;
}