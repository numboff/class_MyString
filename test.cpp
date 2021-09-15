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
	//a1 + "hello world";
	//std::cout << a1 << std::endl;
	a2 = (b + a);
	std::cout << a2 + a << std::endl;
}