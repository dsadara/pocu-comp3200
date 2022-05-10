#include "MyString.h"
#include <iostream>
#include <cassert>
#include <string>

using namespace assignment1;
using namespace std;

int main()
{
	//MyString s("Hello");
	//int length = s.GetLength(); // 길이는 5
	//cout << length << endl;

	//s.Append(" World"); // s는 "Hello World"가 됨

	//cout << s.GetCString() << endl;

	//MyString s1("Hello");
	//MyString s2(" World");

	//MyString s3 = s1 + s2; // s3는 "Hello World"가 되며, s1와 s2는 여전히 "Hello"와 " World"임

	//cout << s3.GetCString() << endl;

	//// indexof()

	//assert(s1.IndexOf("ell") == 1);
	//assert(s1.IndexOf("Hello") == 0);

	//MyString s4("HelloHello");

	//assert(s4.IndexOf("Hello") == 0);

	//// put empty string at Indexof()

	//char const * emptyString = nullptr;
	//MyString s5(emptyString);

	//MyString s6("");

	//assert(s5.IndexOf("Hello") == -1);
	//assert(s5.IndexOf(emptyString) == -1);
	//assert(s1.IndexOf("") == 0);


	//// lastIndexOf()

	//assert(s4.LastIndexOf("Hello") == 5);
	//int i = s1.LastIndexOf("ell"); // i는 1
	//int j = s1.LastIndexOf("l"); // j는 3
	//int z = s1.LastIndexOf("This"); // z는 -1
	//assert(i == 1);
	//assert(j == 3);
	//assert(z = -1);

	//// indexof() wiki testcase
	//assignment1::MyString my1("pope pope");
	//std::string t1("pope pope");

	//const char* cString = my1.GetCString();
	//assignment1::MyString copied(my1);

	//// E0, E1
	//assert(my1.IndexOf("p") == t1.find("p"));
	//assert(my1.LastIndexOf("p") == t1.rfind("p"));

	//assert(my1.IndexOf("pop") == t1.find("pop"));
	//assert(my1.LastIndexOf("pop") == t1.rfind("pop"));

	//assert(my1.IndexOf("popen") == t1.find("popen"));

	//assert(my1.LastIndexOf("popen") == t1.rfind("popen"));

	//assert(my1.IndexOf("pope pope love") == t1.find("pope pope love"));
	//assert(my1.LastIndexOf("pope pope love") == t1.rfind("pope pope love"));

	//assert(my1.IndexOf(" pope") == t1.find(" pope"));
	//assert(my1.LastIndexOf("pope ") == t1.rfind("pope "));

	//// E2, E3
	//assert(my1.IndexOf("") == t1.find(""));
	//cout << t1.rfind("") << endl;
	//assert(my1.LastIndexOf("") == t1.rfind(""));

	//// E4
	//assert(my1 == copied);					// value
	//assert(my1.GetCString() == cString);				// reference

	///* IndexOf() Ex */
	//cout << "-----------------------" << endl;
	//cout << "IndexOf()" << endl;
	//MyString s8("Hello");
	//cout << s8.IndexOf("ell") << endl;   // 1
	//cout << s8.IndexOf("l") << endl;     // 2
	//cout << s8.IndexOf("This") << endl;  // -1
	//cout << s8.IndexOf("") << endl;   // 0
	//cout << s8.IndexOf("lo") << endl;   // 3

	//MyString s52("");
	//cout << s52.IndexOf("") << endl;   // 0
	//cout << s52.IndexOf("A") << endl; // -1

	//MyString s53("Hellello");
	//MyString s54("Heloo");
	//cout << s53.IndexOf("ell") << endl;   // 1
	//cout << s54.IndexOf("ell") << endl;   // -1

	//// interleave()
	//MyString s55("Hello");
	//s55.Interleave(" World"); // s1은 "H eWlolrold"	
	//cout << s55.GetCString() << endl;

	//// toUpper() toLower()
	//MyString s56("HEllo 123K");
	//s56.ToLower(); // s1: "hello 123k"
	//cout << s56.GetCString() << endl;
	//s56.ToUpper();
	//cout << s56.GetCString() << endl;

	//// reverse()
	//MyString s57("Hello");
	//s57.Reverse(); // s: "olleH"
	//cout << s57.GetCString() << endl;

	//MyString s58("abba");
	//s58.Reverse();
	//cout << s58.GetCString() << endl;

	//MyString s59("");
	//s59.Reverse();
	//cout << s59.GetCString() << endl;

	//// Append()
	//MyString s60("");
	//s60.Append("Hello!!!");
	//cout << s60.GetCString() << endl;

	//MyString s61("Hello");
	//s61.Append("");
	//cout << s61.GetCString() << endl;

	////operator+
	//MyString s62("");
	//MyString s63("Hello");
	//MyString s64 = s62 + s63;
	//cout << s64.GetCString() << endl;

	//// removeAt()
	//MyString s65("Hello");
	//bool b1 = s65.RemoveAt(0); // s는 "ello", b1은 true
	//cout << b1 << endl;
	//bool b2 = s65.RemoveAt(2); // s는 "elo", b2은 true
	//cout << b2 << endl;
	//bool b3 = s65.RemoveAt(4); // s는 "elo", b3은 false
	//cout << b3 << endl;

	//// padLeft()

	//MyString p1("Hello");

	//p1.PadLeft(2); // s1: "Hello"
	//p1.PadLeft(8); // s1: "   Hello"

	//MyString p5("Hello");

	//p5.PadLeft(0);
	//p5.PadLeft(5);
	//p5.PadLeft(6);

	//MyString p2("World");
	//p2.PadLeft(3, '-'); // s2: "World"
	//p2.PadLeft(7, '-'); // s2: "--World"

	//// padRight()

	//MyString p3("Hello");

	//p3.PadRight(2); // p3: "Hello"
	//p3.PadRight(8); // p3: "Hello   "

	//MyString p4("World");
	//p4.PadRight(3, '-'); // p4: "World"
	//p4.PadRight(7, '-'); // p4: "World--"

	MyString str(nullptr);
	str.Append("Hello");
	assert(strcmp(str.GetCString(), "Hello") == 0);
	std::cout << "nullptr 생성 이후 Append : " << str.GetCString() << std::endl;


	MyString constructorTest("Hello");
	std::cout << "문자열 생성 : " << constructorTest.GetCString() << std::endl;
	std::cout << "문자열 생성 길이 : " << constructorTest.GetLength() << std::endl;
	assert(strcmp(constructorTest.GetCString(), "Hello") == 0);
	assert(constructorTest.GetLength() == 5);


	std::cout << std::hex;
	MyString originalStr("Hello");
	MyString copyStr(originalStr);
	int originalStrAddress = reinterpret_cast<int>(originalStr.GetCString());
	int copyStrAddress = reinterpret_cast<int>(copyStr.GetCString());
	std::cout << "원본 : " << originalStr.GetCString() << ", 원본 주소 : " << originalStrAddress << std::endl;
	std::cout << "복사본 : " << copyStr.GetCString() << ", 복사본 주소 : " << copyStrAddress << std::endl;
	assert(originalStrAddress != copyStrAddress);
	assert(strcmp(originalStr.GetCString(), "Hello") == 0);
	assert(strcmp(copyStr.GetCString(), "Hello") == 0);


	MyString appendTestFunctional("Hello");
	appendTestFunctional.Append(" World");
	std::cout << "문자열 이어 붙히기 함수형 내부값 변경 : " << appendTestFunctional.GetCString() << std::endl;
	assert(strcmp(appendTestFunctional.GetCString(), "Hello World") == 0);


	MyString appendTestOperator1("Hello");
	MyString appendTestOperator2(" World");
	MyString appendTestOperator3 = appendTestOperator1 + appendTestOperator2;
	std::cout << "문자열 이어 붙히기 연산자 반환 : " << appendTestOperator3.GetCString() << std::endl;
	assert(strcmp(appendTestOperator3.GetCString(), "Hello World") == 0);


	MyString indexOfTest("Hello");
	assert(indexOfTest.IndexOf("el") == 1);
	assert(indexOfTest.IndexOf("ll") == 2);
	assert(indexOfTest.IndexOf("l") == 2);
	assert(indexOfTest.IndexOf("asd") == -1);
	assert(indexOfTest.IndexOf("") == 0);
	assert(indexOfTest.IndexOf(nullptr) == -1);
	assert(indexOfTest.IndexOf("lo") == 3);

	assert(indexOfTest.LastIndexOf("l") == 3);
	assert(indexOfTest.LastIndexOf("asd") == -1);
	assert(indexOfTest.LastIndexOf("") == indexOfTest.GetLength());
	assert(indexOfTest.LastIndexOf(nullptr) == -1);
	assert(indexOfTest.LastIndexOf("He") == 0);

	MyString emptyIndexOfTest("");
	assert(emptyIndexOfTest.IndexOf("a") == -1);
	assert(emptyIndexOfTest.IndexOf("") == 0);
	assert(emptyIndexOfTest.LastIndexOf("") == emptyIndexOfTest.GetLength());


	////https://stackoverflow.com/questions/63834597/interleaving-two-arrays

	//int previousInterLeaveTestStrAddress = reinterpret_cast<int>(
	//interLeaveTest.GetCString());
	//interLeaveTest.Interleave("");
	//int currentInterLeaveTestStrAddress = reinterpret_cast<int>(interLeaveTest.GetCString());
	//assert(previousInterLeaveTestStrAddress == currentInterLeaveTestStrAddress);

	/* Interleave() Ex */
	cout << "-----------------------" << endl;
	cout << "Interleave()" << endl;
	MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetCString() << endl;  //H eWlolrold

	MyString s72("A");
	s72.Interleave("BCDEF");
	cout << s72.GetCString() << endl;  // ABCDEF

	MyString s73("bcdef");
	s73.Interleave("a");
	cout << s73.GetCString() << endl;  // bacdef

	MyString s74("Heelo");
	s74.Interleave("");
	cout << s74.GetCString() << endl;

	MyString s75("");
	s75.Interleave("Hello");
	cout << s75.GetCString() << endl;

	MyString s76(nullptr);
	s76.Interleave("Hello");
	cout << s76.GetCString() << endl;



	std::cout << std::boolalpha;
	MyString removeTest("Hello");
	bool b1 = removeTest.RemoveAt(0); // s는 "ello", b1은 true
	std::cout << "Hello의 첫글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b1 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ello") == 0);
	assert(b1 == true);

	bool b2 = removeTest.RemoveAt(3); // s는 "ell", b2은 true
	std::cout << "ello의 네번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b2 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b2 == true);

	bool b3 = removeTest.RemoveAt(4); // s는 "ell", b3은 false
	std::cout << "ell의 다섯번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b3 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b3 == false);



	MyString padLeftTest1("Hello");
	int previousPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	padLeftTest1.PadLeft(2); // s1: "Hello"
	int currentPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	std::cout << padLeftTest1.GetCString() << std::endl;
	assert(previousPadLeftTest1StrAddress == currentPadLeftTest1StrAddress);
	assert(strcmp(padLeftTest1.GetCString(), "Hello") == 0);

	padLeftTest1.PadLeft(8); // s1: "   Hello"
	assert(strcmp(padLeftTest1.GetCString(), "   Hello") == 0);
	std::cout << padLeftTest1.GetCString() << std::endl;



	MyString padLeftTest2("Hello");
	int previousPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	padLeftTest2.PadLeft(3, '-'); // s1: "Hello"
	int currentPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(previousPadLeftTest2StrAddress == currentPadLeftTest2StrAddress);
	assert(strcmp(padLeftTest2.GetCString(), "Hello") == 0);

	padLeftTest2.PadLeft(7, '-'); // s1: "   Hello"
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(strcmp(padLeftTest2.GetCString(), "--Hello") == 0);



	MyString padRightTest1("Hello");
	int previousPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	padRightTest1.PadRight(2); // s1: "Hello"
	int currentPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	std::cout << padRightTest1.GetCString() << std::endl;
	assert(previousPadRightTest1StrAddress == currentPadRightTest1StrAddress);
	assert(strcmp(padRightTest1.GetCString(), "Hello") == 0);

	padRightTest1.PadRight(8); // s1: "   Hello"
	std::cout << padRightTest1.GetCString() << "I" << std::endl;
	assert(strcmp(padRightTest1.GetCString(), "Hello   ") == 0);



	MyString padRightTest2("Hello");
	int previousPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	padRightTest2.PadRight(3, '-'); // s1: "Hello"
	int currentPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(previousPadRightTest2StrAddress == currentPadRightTest2StrAddress);
	assert(strcmp(padRightTest2.GetCString(), "Hello") == 0);

	padRightTest2.PadRight(7, '-'); // s1: "   Hello"
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(strcmp(padRightTest2.GetCString(), "Hello--") == 0);



	MyString reverseTest("Hello");
	int previousReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	reverseTest.Reverse();
	int currentReverseTestStrAddress = reinterpret_cast<int>(reverseTest.GetCString());
	std::cout << "문자를 거꾸로 : " << reverseTest.GetCString() << std::endl;
	assert(strcmp(reverseTest.GetCString(), "olleH") == 0);



	MyString equelsOperatorTest1("Hello");
	MyString equelsOperatorTest2("Hello");
	MyString equelsOperatorTest3("World");
	assert((equelsOperatorTest1 == equelsOperatorTest2) == true);
	assert((equelsOperatorTest1 == equelsOperatorTest3) == false);



	MyString toLowerTest("HEllo 123K");
	toLowerTest.ToLower(); // s1: "hello 123k"
	assert(strcmp(toLowerTest.GetCString(), "hello 123k") == 0);
	std::cout << "전체 문자 소문자로 변경 : " << toLowerTest.GetCString() << std::endl;



	MyString toUpperTest("HEllo 123K");
	toUpperTest.ToUpper(); // s1: "HELLO 123K"
	assert(strcmp(toUpperTest.GetCString(), "HELLO 123K") == 0);
	std::cout << "전체 문자 대문자로 변경 : " << toUpperTest.GetCString() << std::endl;

	return 0;
}