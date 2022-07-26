#include "Storage.h"
#include <cassert>

using namespace lab11;

void SpecTestCase();

int main()
{
	SpecTestCase();

	Storage<int> s1(10, 5);
	s1.PrintStorage();

	// copy constructor
	Storage<int> s2(s1);
	s2.PrintStorage();

	// assign at greater length storage
	Storage<int> s3(11);
	s3 = s1;
	s3.PrintStorage();

	// assign at same length storage
	Storage<int> s4(10);
	s4 = s1;
	s4.PrintStorage();

	// assign same storage 
	s1 = s1;
	s1.PrintStorage();

	// move constructor
	Storage<int> storage1(10000);
	Storage<int> storageCopy1(std::move(storage1));
	storage1.PrintStorage();
	//storageCopy1.PrintStorage();
	// storage 개체의 크기(size) 값은 0이며 텅 빈 상태

	// move assign operator
	Storage<char> storage2(10000, 'f');
	Storage<char> storageCopy2(10000);
	storageCopy2 = std::move(storage2);
	storage2.PrintStorage();
	//storageCopy2.PrintStorage();
	// storage 개체의 크기 값은 0이며 텅 빈 상태

	// GetData()
	Storage<int> storage3(10000, 10);
	const std::unique_ptr<int[]>& data1 = storage3.GetData();
	data1[0];
	assert(data1[0] == 10);

	// GetSize()
	Storage<int> storage4(100000);
	assert(storage4.GetSize() == 100000); // 100000을 반환

	// Update()
	Storage<int> storage5(5); // [ 0, 0, 0, 0, 0]
	assert(storage5.Update(3, 2)); // [ 0, 0, 0, 2, 0 ], true 반환
	assert(storage5.Update(0, 1)); // [ 1, 0, 0, 2, 0 ], true 반환
	const std::unique_ptr<int[]>& data2 = storage5.GetData();
	assert(data2[3] == 2);
	assert(data2[0] == 1);


}

void SpecTestCase()
{
	const unsigned int SIZE = 10000;

	Storage<int> storage1(SIZE);
	const std::unique_ptr<int[]>& data1 = storage1.GetData();

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data1[i] == 0);
	}


	Storage<int> storage2(SIZE, 100);
	const std::unique_ptr<int[]>& data2 = storage2.GetData();

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data2[i] == 100);
	}

	// using move constructor
	Storage<int> storage3(SIZE, 50);
	const std::unique_ptr<int[]>& data3 = storage3.GetData();

	assert(storage3.GetSize() == SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data3[i] == 50);
	}

	Storage<int> storage3Copy(std::move(storage3));
	const std::unique_ptr<int[]>& data3Copy = storage3Copy.GetData();

	assert(storage3Copy.GetSize() == SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		assert(data3Copy[i] == 50);
	}

	assert(storage3.GetData() == nullptr);
	assert(storage3.GetSize() == 0);

	Storage<char> storage4(SIZE, 'f');
	const std::unique_ptr<char[]>& data4 = storage4.GetData();

	assert(storage4.GetSize() == SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data4[i] == 'f');
	}

	Storage<char> storage4Copy = std::move(storage4);
	const std::unique_ptr<char[]>& data4Copy = storage4Copy.GetData();

	assert(storage4Copy.GetSize() == SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data4Copy[i] == 'f');
	}

	assert(storage4.GetData() == nullptr);
	assert(storage4.GetSize() == 0);

	const unsigned int SIZE2 = 5000;

	Storage<int> storage5(SIZE2);
	const std::unique_ptr<int[]>& data5 = storage5.GetData();

	for (int i = 0; i < SIZE2; ++i)
	{
		storage5.Update(i, SIZE2 - i - 1);
		assert(data5[i] == SIZE2 - i - 1);
	}
}