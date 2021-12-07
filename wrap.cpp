#define BOOST_PYTHON_STATIC_LIB
#include <boost/python.hpp>
#include "MyString.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(string_class)
{
	class_<MyString>("MyString")
		.def(init<MyString>(args("other")))
		.def(init<char*>(args("char_element")))
		.def(init<std::initializer_list<char>&>(args("init_list")))
		.def(init<std::string&>(args("other")))
		.def(init<char*, int>(args("char_element", "count")))
		.def(init<int, char>(args("count", "char_element")))

		.def(self + self)
		.def("__add__", static_cast<MyString(MyString::*) (const char*)const>(&MyString::operator+), args("string"))

		.def(self += self)
		.def("__iadd__", static_cast<MyString&(MyString::*) (const char*)>(&MyString::operator+=), return_value_policy<return_by_value>(), args("string"))

		.def("__getitem__", &MyString::operator[])

		.def(self_ns::str(self_ns::self))

		.def(self > self)
		.def(self < self)
		.def(self >= self)
		.def(self <= self)
		.def(self == self)
		.def(self != self)

		.def("c_str", &MyString::c_str)
		.def("data", &MyString::data)
		.def("lenght", &MyString::length)
		.def("size", &MyString::size)
		.def("empty", &MyString::empty)
		.def("capacity", &MyString::capacity)
		.def("shrink_to_fit", &MyString::shrink_to_fit)
		.def("clear", &MyString::clear)

		.def("insert", static_cast<MyString&(MyString::*) (int, char)>(&MyString::insert), args("index", "char_elem"))
		.def("insert", static_cast<MyString&(MyString::*) (int, int, char)>(&MyString::insert), args("index", "count", "char_elem"))
		.def("insert", static_cast<MyString&(MyString::*) (int, std::string&)> (&MyString::insert), args("index", "string_elem"))
		.def("insert", static_cast<MyString&(MyString::*) (int, std::string&, int)> (&MyString::insert), args("index", "string_elem", "count"))

		.def("erase", &MyString::erase, args("index", "count"))
																																																																																																																																																																																																																																			
		.def("append", static_cast<MyString&(MyString::*) (int, char)>(&MyString::append), args("count", "char_elem"))
		.def("append", static_cast<MyString&(MyString::*) (char*)>(&MyString::append), args("char_elem"))
		.def("append", static_cast<MyString&(MyString::*) (char*, int, int)>(&MyString::append), args("str", "index", "count"))
		.def("append", static_cast<MyString&(MyString::*) (std::string)>(&MyString::append), args("string_elem"))
		.def("append", static_cast<MyString&(MyString::*) (std::string, int, int)>(&MyString::append), args("string_elem", "index", "count"))

		.def("replace", static_cast<MyString&(MyString::*) (const unsigned int, const unsigned int, const char*)>(&MyString::replace), args("index", "count", "str"))
		.def("replace", static_cast<MyString&(MyString::*) (const unsigned int, const unsigned int, const std::string&)>(&MyString::replace), args("index", "count", "other"))

		.def("substr", static_cast<MyString&(MyString::*) (int)>(&MyString::substr), args("index"))
		.def("substr", static_cast<MyString&(MyString::*) (int, int)>(&MyString::substr), args("index", "count"))

		.def("equals", static_cast<bool (MyString::*) (const char*)>(&MyString::equals), args("str"))

		.def("find", static_cast<long long int (MyString::*) (const char*) const>(&MyString::find), args("char_elem"))
		.def("find", static_cast<long long int (MyString::*) (const char*, int)const>(&MyString::find), args("char_elem", "index"))
		.def("find", static_cast<long long int (MyString::*) (std::string&) const>(&MyString::find), args("string_elem"))
		.def("find", static_cast<long long int (MyString::*) (std::string&, int) const>(&MyString::find), args("string_elem", "index"))

		;
}																				