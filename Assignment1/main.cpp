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

	/* IndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "IndexOf()" << endl;
	MyString s8("Hello");
	cout << s8.IndexOf("ell") << endl;   // 1
	cout << s8.IndexOf("l") << endl;     // 2
	cout << s8.IndexOf("This") << endl;  // -1
	cout << s8.IndexOf("") << endl;   // 0
	cout << s8.IndexOf("lo") << endl;   // 3

	MyString s52("");
	cout << s52.IndexOf("") << endl;   // 0
	cout << s52.IndexOf("A") << endl; // -1

	MyString s53("Hellello");
	MyString s54("Heloo");
	cout << s53.IndexOf("ell") << endl;   // 1
	cout << s54.IndexOf("ell") << endl;   // -1

	// interleave()
	MyString s55("Hello");
	s55.Interleave(" World"); // s1은 "H eWlolrold"	
	cout << s55.GetCString() << endl;

	// toUpper() toLower()
	MyString s56("HEllo 123K");
	s56.ToLower(); // s1: "hello 123k"
	cout << s56.GetCString() << endl;
	s56.ToUpper();
	cout << s56.GetCString() << endl;

	// reverse()
	MyString s57("Hello");
	s57.Reverse(); // s: "olleH"
	cout << s57.GetCString() << endl;

	MyString s58("abba");
	s58.Reverse();
	cout << s58.GetCString() << endl;

	MyString s59("");
	s59.Reverse();
	cout << s59.GetCString() << endl;

	// Append()
	MyString s60("");
	s60.Append("Hello!!!");
	cout << s60.GetCString() << endl;

	MyString s61("Hello");
	s61.Append("");
	cout << s61.GetCString() << endl;

	//operator+
	MyString s62("");
	MyString s63("Hello");
	MyString s64 = s62 + s63;
	cout << s64.GetCString() << endl;

	// removeAt()
	MyString s65("Hello");
	bool b1 = s65.RemoveAt(0); // s는 "ello", b1은 true
	cout << b1 << endl;
	bool b2 = s65.RemoveAt(2); // s는 "elo", b2은 true
	cout << b2 << endl;
	bool b3 = s65.RemoveAt(4); // s는 "elo", b3은 false
	cout << b3 << endl;

	// padLeft()

	MyString p1("Hello");

	p1.PadLeft(2); // s1: "Hello"
	p1.PadLeft(8); // s1: "   Hello"

	MyString p2("World");
	p2.PadLeft(3, '-'); // s2: "World"
	p2.PadLeft(7, '-'); // s2: "--World"

	// padRight()

	MyString p3("Hello");

	p3.PadRight(2); // p3: "Hello"
	p3.PadRight(8); // p3: "Hello   "

	MyString p4("World");
	p4.PadRight(3, '-'); // p4: "World"
	p4.PadRight(7, '-'); // p4: "World--"
}