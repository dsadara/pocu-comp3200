#include "MyString.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace assignment1;
using namespace std;

int main()
{
	MyString s("Hello");
	int length = s.GetLength(); // 길이는 5
	cout << length << endl;

	s.Append(" World"); // s는 "Hello World"가 됨

	cout << s.GetCString() << endl;

	MyString s1("Hello");
	MyString s2(" World");

	MyString s3 = s1 + s2; // s3는 "Hello World"가 되며, s1와 s2는 여전히 "Hello"와 " World"임

	cout << s3.GetCString() << endl;

	// indexof()

	assert(s1.IndexOf("ell") == 1);
	assert(s1.IndexOf("Hello") == 0);

	MyString s4("HelloHello");

	assert(s4.IndexOf("Hello") == 0);

	// put empty string at Indexof()

	char const * emptyString = nullptr;
	MyString s5(emptyString);

	MyString s6("");

	assert(s5.IndexOf("Hello") == -1);
	assert(s5.IndexOf(emptyString) == -1);
	assert(s1.IndexOf("") == 0);


	// lastIndexOf()

	assert(s4.LastIndexOf("Hello") == 5);
	int i = s1.LastIndexOf("ell"); // i는 1
	int j = s1.LastIndexOf("l"); // j는 3
	int z = s1.LastIndexOf("This"); // z는 -1
	assert(i == 1);
	assert(j == 3);
	assert(z = -1);

	// indexof() wiki testcase
	assignment1::MyString my1("pope pope");
	std::string t1("pope pope");

	const char* cString = my1.GetCString();
	assignment1::MyString copied(my1);

	// E0, E1
	assert(my1.IndexOf("p") == t1.find("p"));
	assert(my1.LastIndexOf("p") == t1.rfind("p"));

	assert(my1.IndexOf("pop") == t1.find("pop"));
	assert(my1.LastIndexOf("pop") == t1.rfind("pop"));

	assert(my1.IndexOf("popen") == t1.find("popen"));

	assert(my1.LastIndexOf("popen") == t1.rfind("popen"));

	assert(my1.IndexOf("pope pope love") == t1.find("pope pope love"));
	assert(my1.LastIndexOf("pope pope love") == t1.rfind("pope pope love"));

	assert(my1.IndexOf(" pope") == t1.find(" pope"));
	assert(my1.LastIndexOf("pope ") == t1.rfind("pope "));

	// E2, E3
	assert(my1.IndexOf("") == t1.find(""));
	cout << t1.rfind("") << endl;
	assert(my1.LastIndexOf("") == t1.rfind(""));

	// E4
	assert(my1 == copied);					// value
	assert(my1.GetCString() == cString);				// reference



}