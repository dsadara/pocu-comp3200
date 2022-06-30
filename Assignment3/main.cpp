#include "SmartStack.h"
#include <cassert>

using namespace assignment3;

int main()
{
	// test Push(), Pop(), GetMin(), GetMax(), Peek()
	SmartStack<int> s;
	SmartStack<int>* sPtr = new SmartStack<int>();

	s.Push(6); // [ 6 ]
	assert(s.Peek() == 6);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 6);

	s.Push(5); // [ 6, 5 ]
	assert(s.Peek() == 5);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 5);

	s.Push(-2); // [ 6, 5, -2 ]
	assert(s.Peek() == -2);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == -2);

	s.Push(9);	// [ 6, 5 , -2, 9 ]
	assert(s.Peek() == 9);
	assert(s.GetMax() == 9);
	assert(s.GetMin() == -2);

	s.Pop();	// [ 6, 5 , -2 ]
	assert(s.Peek() == -2);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == -2);

	s.Pop();	// [ 6, 5 ]
	assert(s.Peek() == 5);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 5);

	s.Pop();	// [ 6 ]
	assert(s.Peek() == 6);
	assert(s.GetMax() == 6);
	assert(s.GetMin() == 6);



}