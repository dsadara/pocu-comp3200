#include "Lab6.h"
#include <iostream>
#include <cassert>

using namespace std;
using namespace lab6;

void SpecTestCase();

int main()
{
	SpecTestCase();
	// Sum()

	//std::vector<int> v;

	//cout << "Sum : " << lab6::Sum(v) << endl;

	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(6);
	//v.push_back(7);
	//v.push_back(8);

	//cout << "Sum : " <<  lab6::Sum(v) << endl;

	//// Max()

	//std::vector<int> v2;

	//cout << "Max : " << lab6::Max(v2) << endl;

	//v2.push_back(4);
	//v2.push_back(3);
	//v2.push_back(4);
	//v2.push_back(12);
	//v2.push_back(7);
	//v2.push_back(11);

	//cout << "Max : " << lab6::Max(v2) << endl; // 12

	//// Min()

	//std::vector<int> v3;

	//cout << "Min : " << lab6::Min(v3) << endl; // INT_MAX

	//v3.push_back(4);
	//v3.push_back(3);
	//v3.push_back(4);
	//v3.push_back(12);
	//v3.push_back(7);
	//v3.push_back(11);

	//cout << "Min : " << lab6::Min(v3) << endl; // 3

	//// Average()

	//std::vector<int> v4;

	//cout << "Average() : " << lab6::Average(v4) << endl; // 0.0f

	//v4.push_back(4);
	//v4.push_back(3);
	//v4.push_back(4);
	//v4.push_back(12);
	//v4.push_back(7);
	//v4.push_back(11);

	//cout << "Average() : " << lab6::Average(v4) << endl; // 6.83333349f

	//// lab6::NumberWithMaxOccurrence()

	//std::vector<int> v5;

	//cout << "MaxOccurence() : " << lab6::NumberWithMaxOccurrence(v5) << endl; // 0
	//v5.push_back(4);
	//v5.push_back(3);
	//v5.push_back(4);
	//v5.push_back(12);
	//v5.push_back(7);
	//v5.push_back(11);

	//cout << "MaxOccurence() : " << lab6::NumberWithMaxOccurrence(v5) << endl; // 4

	////  { 1, 1, 3, 3, 2, 6, -1 }

	//std::vector<int> v6;

	//cout << "MaxOccurence() : " << lab6::NumberWithMaxOccurrence(v6) << endl; // 0

	//v6.push_back(1);
	//v6.push_back(1);
	//v6.push_back(3);
	//v6.push_back(3);
	//v6.push_back(2);
	//v6.push_back(6);
	//v6.push_back(-1);

	//cout << "MaxOccurence() : " << lab6::NumberWithMaxOccurrence(v6) << endl; // 3

	//// lab6::SortDescending()

	//std::vector<int> v7;
	//lab6::SortDescending(v7);
	//v7.push_back(4);
	//v7.push_back(3);
	//v7.push_back(4);
	//v7.push_back(12);
	//v7.push_back(7);
	//v7.push_back(11);

	//lab6::SortDescending(v7); // v¿« ø‰º“: [ 12, 11, 7, 4, 4, 3 ]

}

void SpecTestCase()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	int sum = lab6::Sum(v);
	int max = lab6::Max(v);
	int min = lab6::Min(v);
	float average = lab6::Average(v);
	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v);
	lab6::SortDescending(v);

	assert(sum == 41);
	assert(max == 12);
	assert(min == 3);
	assert(average == 6.83333349f);
	assert(numWithMaxOccurence == 4);

	for (int i = 0; i < (int)v.size() - 1; ++i)
	{
		assert(v[i] >= v[i + 1]);
	}

}