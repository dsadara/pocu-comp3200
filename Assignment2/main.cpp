#include "Person.h"

using namespace assignment2;

int main()
{
	Person p("Bob", 85);	// "Bob"�� ��� �ɱ�? ��� ���ڿ��̴ϱ� �Ű� �Ƚᵵ �Ǵ°ǰ�? 
	p.GetName(); // "Bob"
	p.GetWeight(); // 85

	Person* p = new Person("Bob", 85);
	Person* p2 = new Person("James", 75);
	Person* p3 = new Person("Tina", 50);

	delete a; // �� �ڵ�� p�� p2�� �Ҹ��ŵ�ϴ�. p3�� �Ҹ���� �ʽ��ϴ�.
}