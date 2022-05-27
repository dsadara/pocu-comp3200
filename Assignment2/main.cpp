#include "Person.h"

using namespace assignment2;

int main()
{
	Person p("Bob", 85);	// "Bob"은 어떻게 될까? 상수 문자열이니까 신경 안써도 되는건가? 
	p.GetName(); // "Bob"
	p.GetWeight(); // 85

	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 50);

	delete a; // 이 코드는 p와 p2도 소멸시킵니다. p3는 소멸되지 않습니다.
}