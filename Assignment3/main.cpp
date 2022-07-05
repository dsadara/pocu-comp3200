#include "SmartStack.h"
#include "SmartQueue.h"
#include "QueueStack.h"
#include <cassert>
#include <cmath>

using namespace assignment3;

void SpecTestCase();
void StudTestCase();
void TestSmartStack();
void TestSmartQueue();
void TestQueueStack();
void TestMinMaxWhenEmpty();

int main()
{
	SpecTestCase();
	TestSmartStack();
	TestSmartQueue();
	TestQueueStack();
	TestMinMaxWhenEmpty();


	// ============SmartStack==================

	// push same element test

	SmartStack<int> s4;

	s4.Push(1);
	assert(s4.Peek() == 1);
	assert(s4.GetMax() == 1);
	assert(s4.GetMin() == 1);

	s4.Push(9);
	assert(s4.Peek() == 9);
	assert(s4.GetMax() == 9);
	assert(s4.GetMin() == 1);

	s4.Push(9);
	assert(s4.Peek() == 9);
	assert(s4.GetMax() == 9);
	assert(s4.GetMin() == 1);

	s4.Push(9);
	assert(s4.Peek() == 9);
	assert(s4.GetMax() == 9);
	assert(s4.GetMin() == 1);

	s4.Pop();
	assert(s4.Peek() == 9);
	assert(s4.GetMax() == 9);
	assert(s4.GetMin() == 1);

	s4.Pop();
	assert(s4.Peek() == 9);
	assert(s4.GetMax() == 9);
	assert(s4.GetMin() == 1);

	s4.Pop();
	assert(s4.Peek() == 1);
	assert(s4.GetMax() == 1);
	assert(s4.GetMin() == 1);

	s4.Pop();
	assert(s4.GetMax() == std::numeric_limits<int>::min());
	assert(s4.GetMin() == std::numeric_limits<int>::max());
	assert(s4.GetSum() == 0.0);
	assert(s4.GetVariance() == 0.0);

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

	// test SmartStack Copy Constructor, Assignment Operator

	sPtr->Push(6);
	sPtr->Push(4);
	sPtr->Push(2);
	sPtr->Push(6);

	SmartStack<int> s2(*sPtr);
	SmartStack<int> s2_1;
	s2_1 = *sPtr;

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());


	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());

	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());

	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	assert(s2_1.Peek() == sPtr->Peek());

	s2.Pop();
	sPtr->Pop();
	s2_1.Pop();

	assert(s2.GetMax() == sPtr->GetMax());
	assert(s2.GetMin() == sPtr->GetMin());
	//assert(s2.Peek() == sPtr->Peek());
	assert(s2_1.GetMax() == sPtr->GetMax());
	assert(s2_1.GetMin() == sPtr->GetMin());
	//assert(s2_1.Peek() == sPtr->Peek());

	delete sPtr;

	// test GetSum(). GetCount(), GetAverage()

	SmartStack<int> s3;
	s3.Push(6);
	s3.Push(5);
	s3.Push(-2);

	assert(s3.GetCount() == 3u);
	assert(s3.GetSum() == 9);
	assert(s3.GetAverage() == 3.0);

	//s3.Pop();

	//assert(s3.GetCount() == 2u);
	//assert(s3.GetSum() == 11);
	//assert(s3.GetAverage() == (11.0/2.0));

	//s3.Pop();

	//assert(s3.GetCount() == 1u);
	//assert(s3.GetSum() == 6);
	//assert(s3.GetAverage() == (6.0/1.0));

	//s3.Pop();

	//assert(s3.GetCount() == 0u);
	//assert(s3.GetSum() == 0);
	//assert(s3.GetAverage() == 0.0);

	// test GetVariance(), GetStandardDeviation()

	double diff = s3.GetVariance() - 12.667;
	assert(fabs(diff) < 0.01);
	assert(fabs(s3.GetStandardDeviation() - 3.559) < 0.01);

	// ============SmartQueue=================

	SmartQueue<int> q;

	// Enqueue()
	// Peek()

	q.Enqueue(6);

	assert(q.Peek() == 6);

	q.Enqueue(5);

	assert(q.Peek() == 6);

	q.Enqueue(-2);

	assert(q.Peek() == 6);

	// GetMax() GetMin()

	assert(q.GetMax() == 6);
	assert(q.GetMin() == -2);

	// GetAverage() GetSum() 

	assert(q.GetAverage() == 3.0);
	assert(q.GetSum() == 9);

	// GetVariance() GetStandardDeviation() GetCount()

	assert(std::abs(q.GetVariance() - 12.667) < 0.001);
	assert(std::abs(q.GetStandardDeviation() - 3.559) < 0.001);
	assert(q.GetCount() == 3);

	// constructor, copy constructor, assignment operator

	SmartQueue<int> p(q);
	SmartQueue<int> r;

	r = q;

	assert(p.GetCount() == q.GetCount());
	assert(r.GetCount() == q.GetCount());
	assert(p.Peek() == q.Peek());
	assert(r.Peek() == q.Peek());

	// Dequeue()

	assert(q.Dequeue() == 6);
	assert(q.Dequeue() == 5);
	assert(q.Dequeue() == -2);

	// ============QueueStack=================

	// Enqueue()  Peek()

	QueueStack<int> qs(3);
	qs.Enqueue(1); // [ [ 1 ] ]
	assert(qs.Peek() == 1);
	assert(qs.GetStackCount() == 1);
	qs.Enqueue(2); // [ [ 1, 2 ] ]
	assert(qs.Peek() == 2);
	assert(qs.GetStackCount() == 1);
	qs.Enqueue(3); // [ [ 1, 2, 3 ] ]
	assert(qs.Peek() == 3);
	assert(qs.GetStackCount() == 1);
	qs.Enqueue(4); // [ [ 1, 2, 3 ], [ 4 ] ]
	assert(qs.Peek() == 3);
	assert(qs.GetStackCount() == 2);
	qs.Enqueue(5); // [ [ 1, 2, 3 ], [ 4, 5 ] ]
	assert(qs.Peek() == 3);
	assert(qs.GetStackCount() == 2);

	// GetMax() GetMin()
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == 1);

	// GetCount() GetSum() GetAverage()

	assert(3.000 == qs.GetAverage());
	assert(15 == qs.GetSum());
	assert(5 == qs.GetCount());


	// Copy Constructor
	QueueStack<int> qs2(qs);
	assert(qs2.Peek() == qs.Peek());
	assert(qs2.GetStackCount() == qs.GetStackCount());

	// assignment operator
	QueueStack<int> qs3 = qs;
	assert(qs3.Peek() == qs.Peek());
	assert(qs3.GetStackCount() == qs.GetStackCount());

	assert(qs3.Peek() == qs2.Peek());
	assert(qs3.GetStackCount() == qs2.GetStackCount());

	qs3.Dequeue();

	assert(qs3.Peek() != qs.Peek());

	qs2.Dequeue();

	assert(qs3.Peek() != qs.Peek());

	assert(qs2.Peek() == qs3.Peek());


	// Dequeue()

	qs.Dequeue();
	assert(qs.Peek() == 2);
	assert(qs.GetStackCount() == 2);

	qs.Dequeue();
	assert(qs.Peek() == 1);
	assert(qs.GetStackCount() == 2);

	qs.Dequeue();
	assert(qs.Peek() == 5);
	assert(qs.GetStackCount() == 1);

	qs.Dequeue();
	assert(qs.Peek() == 4);
	assert(qs.GetStackCount() == 1);

	qs.Dequeue();

	return 0;
}

void SpecTestCase()
{
	const double EPSILON = 0.0009765625;

	SmartStack<float> ss;

	ss.Push(3.4999f);
	ss.Push(1.2f);
	ss.Push(4.6555f);
	ss.Push(3.3299f);
	ss.Push(10.2f);
	ss.Push(1.1f);
	ss.Push(-5.9f);
	ss.Push(1.1f);
	ss.Push(-12.4f);
	ss.Push(9.2f);

	assert(ss.GetCount() == 10U);
	assert(ss.Peek() == 9.2f);
	assert(ss.GetMax() == 10.2f);
	assert(ss.GetMin() == -12.4f);
	assert(std::abs(ss.GetSum() - 15.985301f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 1.599) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 40.057) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 6.329) <= EPSILON);
	assert(ss.Peek() == 9.2f);

	float popped1 = ss.Pop();
	float popped2 = ss.Pop();

	assert(popped1 == 9.2f);
	assert(popped2 == -12.4f);
	assert(ss.GetCount() == 8U);
	assert(ss.Peek() == 1.1f);
	assert(ss.GetMax() == 10.2f);
	assert(std::abs(ss.GetMin() - (-5.9f)) <= EPSILON);
	//assert(ss.GetMin() == -5.9f);			WTF..
	assert(std::abs(ss.GetSum() - 19.1853008f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 2.398) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 17.714) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 4.209) <= EPSILON);

}
void StudTestCase()
{

}

void TestSmartStack()
{
	const double EPSILON = 0.0009765625;

	// test constructor
	SmartStack<float> ss;
	assert(ss.GetCount() == 0u);
	assert(ss.GetSum() == 0.f);
	assert(ss.GetMax() == -std::numeric_limits<float>::max());
	assert(ss.GetMin() == std::numeric_limits<float>::max());

	// test Push()
	ss.Push(0.f);
	assert(ss.GetCount() == 1u);
	assert(ss.Peek() == 0.f);
	assert(ss.GetMax() == 0.f);
	assert(ss.GetMin() == 0.f);

	ss.Push(1.443f);
	assert(ss.GetCount() == 2u);
	assert(ss.Peek() == 1.443f);
	assert(ss.GetMax() == 1.443f);
	assert(ss.GetMin() == 0.f);
	assert(std::abs(ss.GetSum() - 1.443f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 0.7215) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 0.52056225) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 0.7215) <= EPSILON);

	ss.Push(123.456f);
	assert(ss.GetCount() == 3u);
	assert(ss.Peek() == 123.456f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == 0.f);

	ss.Push(-11.5f);
	assert(ss.GetCount() == 4u);
	assert(ss.Peek() == -11.5f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == -11.5f);

	ss.Push(0.998f);
	assert(ss.GetCount() == 5u);
	assert(ss.Peek() == 0.998f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == -11.5f);

	ss.Push(-4.243f);
	assert(ss.GetCount() == 6u);
	assert(ss.Peek() == -4.243f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == -11.5f);
	assert(std::abs(ss.GetSum() - 110.154f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 18.359) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 2228.733) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 47.209459) <= EPSILON);

	// test copy constructor
	SmartStack<float> ss2(ss);
	assert(ss2.GetCount() == 6u);
	assert(ss2.Peek() == -4.243f);
	assert(ss2.GetMax() == 123.456f);
	assert(ss2.GetMin() == -11.5f);
	assert(std::abs(ss2.GetSum() - 110.154f) <= EPSILON);
	assert(std::abs(ss2.GetAverage() - 18.359) <= EPSILON);
	assert(std::abs(ss2.GetVariance() - 2228.733) <= EPSILON);
	assert(std::abs(ss2.GetStandardDeviation() - 47.209459) <= EPSILON);

	// test Pop()
	assert(ss.Pop() == -4.243f);
	assert(ss.GetCount() == 5u);
	assert(ss.Peek() == 0.998f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == -11.5f);

	assert(ss.Pop() == 0.998f);
	assert(ss.GetCount() == 4u);
	assert(ss.Peek() == -11.5f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == -11.5f);

	assert(ss.Pop() == -11.5f);
	assert(ss.GetCount() == 3u);
	assert(ss.Peek() == 123.456f);
	assert(ss.GetMax() == 123.456f);
	assert(ss.GetMin() == 0.f);

	assert(ss.Pop() == 123.456f);
	assert(ss.GetCount() == 2u);
	assert(ss.Peek() == 1.443f);
	double result = ss.GetMax() - 1.443f;
	assert(result < EPSILON);
	assert(ss.GetMax() == 1.443f);
	assert(ss.GetMin() == 0.f);
	/*
	assert(std::abs(ss.GetMax() - 1.443f) <= EPSILON);
	assert(std::abs(ss.GetMin() - 0.f) <= EPSILON);*/
	assert(std::abs(ss.GetSum() - 1.443f) <= EPSILON);
	assert(std::abs(ss.GetAverage() - 0.7215) <= EPSILON);
	assert(std::abs(ss.GetVariance() - 0.52056225) <= EPSILON);
	assert(std::abs(ss.GetStandardDeviation() - 0.7215) <= EPSILON);

	assert(ss.Pop() == 1.443f);
	assert(ss.GetCount() == 1u);
	assert(ss.Peek() == 0.f);
	assert(std::abs(ss.GetMax() - 0.f) <= EPSILON);
	assert(std::abs(ss.GetMin() - 0.f) <= EPSILON);

	assert(ss.Pop() == 0.f);
	assert(ss.GetCount() == 0u);
	assert(std::abs(ss.GetSum() - 0.f) <= EPSILON);
	assert(ss.GetMax() == -std::numeric_limits<float>::max());
	assert(ss.GetMin() == std::numeric_limits<float>::max());

	// test assignment operator
	assert(ss2.GetCount() != 0u);
	assert(ss2.GetSum() != 0.f);
	assert(ss2.GetMax() != -std::numeric_limits<float>::max());
	assert(ss2.GetMin() != std::numeric_limits<float>::max());

	ss2 = ss;

	assert(ss2.GetCount() == 0u);
	assert(std::abs(ss2.GetSum() - 0.f) <= EPSILON);
	assert(ss2.GetMax() == -std::numeric_limits<float>::max());
	assert(ss2.GetMin() == std::numeric_limits<float>::max());
};

void TestSmartQueue()
{
	const double EPSILON = 0.0009765625;

	// test constructor
	SmartQueue<int> sq;
	assert(sq.GetCount() == 0u);
	assert(sq.GetSum() == 0);
	assert(sq.GetMax() == std::numeric_limits<int>::min());
	assert(sq.GetMin() == std::numeric_limits<int>::max());

	// test Enqueue()
	sq.Enqueue(0);
	assert(sq.GetCount() == 1u);
	assert(sq.Peek() == 0);
	assert(sq.GetMax() == 0);
	assert(sq.GetMin() == 0);

	sq.Enqueue(-20);
	assert(sq.GetCount() == 2u);
	assert(sq.Peek() == 0);
	assert(sq.GetMax() == 0);
	assert(sq.GetMin() == -20);

	sq.Enqueue(3);
	assert(sq.GetCount() == 3u);
	assert(sq.Peek() == 0);
	assert(sq.GetMax() == 3);
	assert(sq.GetMin() == -20);
	assert(sq.GetSum() == -17);
	assert(std::abs(sq.GetAverage() - (-5.666666667)) <= EPSILON);
	assert(std::abs(sq.GetVariance() - 104.22222) <= EPSILON);
	assert(std::abs(sq.GetStandardDeviation() - 10.208929) <= EPSILON);

	sq.Enqueue(14);
	assert(sq.GetCount() == 4u);
	assert(sq.Peek() == 0);
	assert(sq.GetMax() == 14);
	assert(sq.GetMin() == -20);

	sq.Enqueue(11);
	assert(sq.GetCount() == 5u);
	assert(sq.Peek() == 0);
	assert(sq.GetMax() == 14);
	assert(sq.GetMin() == -20);
	assert(sq.GetSum() == 8);
	assert(std::abs(sq.GetAverage() - 1.6) <= EPSILON);
	assert(std::abs(sq.GetVariance() - 142.64) <= EPSILON);
	assert(std::abs(sq.GetStandardDeviation() - 11.943199) <= EPSILON);

	// test copy constructor
	SmartQueue<int> sq2(sq);
	assert(sq2.GetCount() == 5u);
	assert(sq2.Peek() == 0);
	assert(sq2.GetMax() == 14);
	assert(sq2.GetMin() == -20);
	assert(sq2.GetSum() == 8);
	assert(std::abs(sq2.GetAverage() - 1.6) <= EPSILON);
	assert(std::abs(sq2.GetVariance() - 142.64) <= EPSILON);
	assert(std::abs(sq2.GetStandardDeviation() - 11.943199) <= EPSILON);

	// test Dequeue()
	assert(sq.Dequeue() == 0);
	assert(sq.GetCount() == 4u);
	assert(sq.Peek() == -20);
	assert(sq.GetMax() == 14);
	assert(sq.GetMin() == -20);

	assert(sq.Dequeue() == -20);
	assert(sq.GetCount() == 3u);
	assert(sq.Peek() == 3);
	assert(sq.GetMax() == 14);
	assert(sq.GetMin() == 3);
	assert(sq.GetSum() == 28);
	assert(std::abs(sq.GetAverage() - 9.33333333) <= EPSILON);
	assert(std::abs(sq.GetVariance() - 21.555556) <= EPSILON);
	assert(std::abs(sq.GetStandardDeviation() - 4.6427961) <= EPSILON);

	assert(sq.Dequeue() == 3);
	assert(sq.GetCount() == 2u);
	assert(sq.Peek() == 14);
	assert(sq.GetMax() == 14);
	assert(sq.GetMin() == 11);

	assert(sq.Dequeue() == 14);
	assert(sq.GetCount() == 1u);
	assert(sq.Peek() == 11);
	assert(sq.GetMax() == 11);
	assert(sq.GetMin() == 11);

	assert(sq.Dequeue() == 11);
	assert(sq.GetCount() == 0u);
	assert(sq.GetSum() == 0);
	assert(sq.GetMax() == std::numeric_limits<int>::min());
	assert(sq.GetMin() == std::numeric_limits<int>::max());

	// test assignment operator
	assert(sq2.GetCount() != 0u);
	assert(sq2.GetSum() != 0);
	assert(sq2.GetMax() != std::numeric_limits<int>::min());
	assert(sq2.GetMin() != std::numeric_limits<int>::max());

	sq2 = sq;

	assert(sq2.GetCount() == 0u);
	assert(sq2.GetSum() == 0);
	assert(sq2.GetMax() == std::numeric_limits<int>::min());
	assert(sq2.GetMin() == std::numeric_limits<int>::max());
};

void TestQueueStack()
{
	const double EPSILON = 0.0009765625;

	// test constructor
	QueueStack<int> qs(2u);
	assert(qs.GetCount() == 0u);
	assert(qs.GetStackCount() == 0u);
	assert(qs.GetSum() == 0);
	assert(qs.GetMax() == std::numeric_limits<int>::min());
	assert(qs.GetMin() == std::numeric_limits<int>::max());

	// test Enqueue()
	qs.Enqueue(0);
	assert(qs.Peek() == 0);
	assert(qs.GetMax() == 0);
	assert(qs.GetMin() == 0);
	assert(qs.GetSum() == 0);
	assert(qs.GetAverage() == 0);
	assert(qs.GetCount() == 1u);
	assert(qs.GetStackCount() == 1u);

	qs.Enqueue(4);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 4);
	assert(qs.GetMin() == 0);
	assert(qs.GetSum() == 4);
	assert(qs.GetAverage() == 2);
	assert(qs.GetCount() == 2u);
	qs.GetStackCount();
	assert(qs.GetStackCount() == 1u);

	qs.Enqueue(-3);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 4);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 1);
	assert(std::abs(qs.GetAverage() - 0.33333333) <= EPSILON);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(7);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 8);
	assert(qs.GetAverage() == 2);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(5);
	assert(qs.Peek() == 4);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 13);
	assert(qs.GetAverage() == 2.6);
	assert(qs.GetCount() == 5u);
	assert(qs.GetStackCount() == 3u);

	// test copy constructor
	QueueStack<int> qs2(qs);
	assert(qs2.Peek() == 4);
	assert(qs2.GetMax() == 7);
	assert(qs2.GetMin() == -3);
	assert(qs2.GetSum() == 13);
	assert(qs2.GetAverage() == 2.6);
	assert(qs2.GetCount() == 5u);
	assert(qs2.GetStackCount() == 3u);

	// test Dequeue()
	assert(qs.Dequeue() == 4);
	assert(qs.Peek() == 0);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 9);
	assert(qs.GetAverage() == 2.25);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 3u);

	assert(qs.Dequeue() == 0);
	assert(qs.Peek() == 7);
	assert(qs.GetMax() == 7);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 9);
	assert(qs.GetAverage() == 3);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	assert(qs.Dequeue() == 7);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == -3);
	assert(qs.GetSum() == 2);
	assert(qs.GetAverage() == 1);
	assert(qs.GetCount() == 2u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(-6);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == -6);
	assert(qs.GetSum() == -4);
	assert(std::abs(qs.GetAverage() - (-1.33333333)) <= EPSILON);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	qs.Enqueue(-8);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 5);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == -12);
	assert(qs.GetAverage() == -3);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 3u);

	qs.Enqueue(10);
	assert(qs.Peek() == -3);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == -2);
	assert(qs.GetAverage() == -0.4);
	assert(qs.GetCount() == 5u);
	assert(qs.GetStackCount() == 3u);

	assert(qs.Dequeue() == -3);
	assert(qs.Peek() == -6);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == 1);
	assert(qs.GetAverage() == 0.25);
	assert(qs.GetCount() == 4u);
	assert(qs.GetStackCount() == 2u);

	assert(qs.Dequeue() == -6);
	assert(qs.Peek() == 5);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == 7);
	assert(std::abs(qs.GetAverage() - 2.33333333) <= EPSILON);
	assert(qs.GetCount() == 3u);
	assert(qs.GetStackCount() == 2u);

	assert(qs.Dequeue() == 5);
	assert(qs.Peek() == 10);
	assert(qs.GetMax() == 10);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == 2);
	assert(qs.GetAverage() == 1);
	assert(qs.GetCount() == 2u);
	assert(qs.GetStackCount() == 1u);

	assert(qs.Dequeue() == 10);
	assert(qs.Peek() == -8);
	assert(qs.GetMax() == -8);
	assert(qs.GetMin() == -8);
	assert(qs.GetSum() == -8);
	assert(qs.GetAverage() == -8);
	assert(qs.GetCount() == 1u);
	assert(qs.GetStackCount() == 1u);

	assert(qs.Dequeue() == -8);
	assert(qs.GetMax() == std::numeric_limits<int>::min());
	assert(qs.GetMin() == std::numeric_limits<int>::max());
	assert(qs.GetSum() == 0);
	assert(qs.GetCount() == 0u);
	assert(qs.GetStackCount() == 0u);

	// test assignment operator
	assert(qs2.GetMax() != std::numeric_limits<int>::min());
	assert(qs2.GetMin() != std::numeric_limits<int>::max());
	assert(qs2.GetSum() != 0);
	assert(qs2.GetCount() != 0u);
	assert(qs2.GetStackCount() != 0u);

	qs2 = qs;

	assert(qs2.GetMax() == std::numeric_limits<int>::min());
	assert(qs2.GetMin() == std::numeric_limits<int>::max());
	assert(qs2.GetSum() == 0);
	assert(qs2.GetCount() == 0u);
	assert(qs2.GetStackCount() == 0u);

	// test max stack count 0
	QueueStack<int> qs3(0);
	qs = qs3;
	qs.Enqueue(1);
	qs.Enqueue(2);
	qs.Enqueue(3);

	assert(qs.GetMax() == std::numeric_limits<int>::min());
	assert(qs.GetMin() == std::numeric_limits<int>::max());
	assert(qs.GetSum() == 0);
	assert(qs.GetCount() == 0u);
	assert(qs.GetStackCount() == 0u);
};

void TestMinMaxWhenEmpty()
{
	SmartStack<int> s1;
	assert(s1.GetMax() == std::numeric_limits<int>::min());
	assert(s1.GetMin() == std::numeric_limits<int>::max());

	SmartStack<unsigned int> s2;
	assert(s2.GetMax() == std::numeric_limits<unsigned int>::min());
	assert(s2.GetMin() == std::numeric_limits<unsigned int>::max());

	SmartStack<float> s3;
	assert(s3.GetMax() == -std::numeric_limits<float>::max());
	assert(s3.GetMin() == std::numeric_limits<float>::max());

	SmartStack<double> s4;
	assert(s4.GetMax() == -std::numeric_limits<double>::max());
	assert(s4.GetMin() == std::numeric_limits<double>::max());

	SmartQueue<int> q1;
	assert(q1.GetMax() == std::numeric_limits<int>::min());
	assert(q1.GetMin() == std::numeric_limits<int>::max());

	SmartQueue<unsigned int> q2;
	assert(q2.GetMax() == std::numeric_limits<unsigned int>::min());
	assert(q2.GetMin() == std::numeric_limits<unsigned int>::max());

	SmartQueue<float> q3;
	q3.GetMax();
	assert(q3.GetMax() == -std::numeric_limits<float>::max());
	assert(q3.GetMin() == std::numeric_limits<float>::max());

	SmartQueue<double> q4;
	assert(q4.GetMax() == -std::numeric_limits<double>::max());
	assert(q4.GetMin() == std::numeric_limits<double>::max());

	QueueStack<int> qs1(1);
	assert(qs1.GetMax() == std::numeric_limits<int>::min());
	assert(qs1.GetMin() == std::numeric_limits<int>::max());

	QueueStack<unsigned int> qs2(1);
	assert(qs2.GetMax() == std::numeric_limits<unsigned int>::min());
	assert(qs2.GetMin() == std::numeric_limits<unsigned int>::max());

	QueueStack<float> qs3(1);
	assert(qs3.GetMax() == -std::numeric_limits<float>::max());
	assert(qs3.GetMin() == std::numeric_limits<float>::max());

	QueueStack<double> qs4(1);
	assert(qs4.GetMax() == -std::numeric_limits<double>::max());
	assert(qs4.GetMin() == std::numeric_limits<double>::max());
};
