#include <cassert>

#include "Lab7.h"

using namespace lab7;

void SpecTestCase();

int main()
{
	// ConvertVectorsToMap

	std::vector<int> v1;
	std::vector<char> v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');

	std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
	{
		std::map<int, char>::const_iterator it = m.begin();

		assert(it->first == v1[0]);
		assert(it->second == v2[0]);
		it++;
		assert(it->first == v1[1]);
		assert(it->second == v2[1]);
		it++;
		assert(it->first == v1[2]);
		assert(it->second == v2[2]);
	}

	std::vector<char> v3;
	std::vector<int> v4;

	v3.push_back('a');
	v3.push_back('b');
	v3.push_back('c');
	v3.push_back('a');

	v4.push_back(1);
	v4.push_back(2);
	v4.push_back(3);
	v4.push_back(4);

	std::map<char, int> m2 = ConvertVectorsToMap(v3, v4);
	{
		std::map<char, int>::const_iterator it2 = m2.begin();

		assert(m2.size() == 3);

		assert(it2->first == v3[0]);
		assert(it2->second == v4[0]);

		it2++;

		assert(it2->first == v3[1]);
		assert(it2->second == v4[1]);

		it2++;

		assert(it2->first == v3[2]);
		assert(it2->second == v4[2]);
	}

	std::vector<char> v5;
	std::vector<int> v6;

	v5.push_back('a');
	v5.push_back('b');
	v5.push_back('c');
	v5.push_back('d');

	v6.push_back(1);
	v6.push_back(2);
	v6.push_back(3);

	std::map<char, int> m3 = ConvertVectorsToMap(v5, v6);
	{
		std::map<char, int>::const_iterator it3 = m3.begin();
		assert(m3.size() == 3);
		
		assert(it3->first == v5[0]);
		assert(it3->second == v6[0]);

		it3++;

		assert(it3->first == v5[1]);
		assert(it3->second == v6[1]);

		it3++;

		assert(it3->first == v5[2]);
		assert(it3->second == v6[2]);
	}

	// GetKeys, GetValue
	std::vector<char> v7 = GetKeys(m3);
	{
		assert(v7.size() == 3);

		assert(v7[0] == v5[0]);
		assert(v7[1] == v5[1]);
		assert(v7[2] == v5[2]);
	}

	std::vector<int> v8 = GetValues(m3);
	{
		assert(v8.size() == 3);

		assert(v8[0] == v6[0]);
		assert(v8[1] == v6[1]);
		assert(v8[2] == v6[2]);
	}

	// Reverse

	std::vector<int> v9 = Reverse(v4);
	{
		assert(v9.size() == 4);

		assert(v9[0] == v4[3]);
		assert(v9[1] == v4[2]);
		assert(v9[2] == v4[1]);
		assert(v9[3] == v4[0]);
	}

	// vector operator+
	// Vector1: 1 2 3 / Vector2: 3 2 4
	std::vector<int> v10;
	
	v10.push_back(1);
	v10.push_back(2);
	v10.push_back(3);

	std::vector<int> v11;

	v11.push_back(3);
	v11.push_back(2);
	v11.push_back(4);

	std::vector<int> r1 = v10 + v11;

	{
		assert(r1.size() == 4);
		assert(r1[0] == 1);
		assert(r1[1] == 2);
		assert(r1[2] == 3);
		assert(r1[3] == 4);
	}

	std::vector<int> v12;

	v12.push_back(1);
	v12.push_back(2);
	v12.push_back(3);

	std::vector<int> v13;

	v13.push_back(4);
	v13.push_back(5);
	v13.push_back(6);

	std::vector<int> r2 = v12 + v13;

	{
		assert(r2.size() == 6);
		assert(r2[0] == 1);
		assert(r2[1] == 2);
		assert(r2[2] == 3);
		assert(r2[3] == 4);
		assert(r2[4] == 5);
		assert(r2[5] == 6);
	}

	// map operator+

	std::map<char, int> m4;
	m4.insert(std::pair<char, int>('a', 1));
	m4.insert(std::pair<char, int>('b', 2));
	m4.insert(std::pair<char, int>('c', 3));

	std::map<char, int> m5;
	m4.insert(std::pair<char, int>('a', 4));
	m4.insert(std::pair<char, int>('b', 5));
	m4.insert(std::pair<char, int>('f', 6));

	std::map<char, int> r3 = m4 + m5;
	{
		assert(r3.size() == 4);
		std::map<char, int>::const_iterator it = r3.begin();

		assert(it->first == 'a');
		it++;
		assert(it->first == 'b');
		it++;
		assert(it->first == 'c');
		it++;
		assert(it->first == 'f');
	}

	// vector operator<<

	// map operator<<
	
	SpecTestCase();
}

void SpecTestCase()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	std::vector<char> v2;
	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');

	std::vector<int> v3;
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);

	std::map<char, int> m1;
	m1['a'] = 1;
	m1['b'] = 2;
	m1['c'] = 3;

	std::map<char, int> m2;
	m2['d'] = 4;
	m2['e'] = 5;
	m2['f'] = 6;

	std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
	{
		std::map<int, char>::const_iterator it = m.begin();

		assert(it->first == 1);
		assert(it->second == 'a');
		it++;
		assert(it->first == 2);
		assert(it->second == 'b');
		it++;
		assert(it->first == 3);
		assert(it->second == 'c');
	}

	std::vector<char> keys = lab7::GetKeys(m1);
	{
		std::vector<char>::const_iterator it = keys.begin();

		assert(*it == 'a');
		it++;
		assert(*it == 'b');
		it++;
		assert(*it == 'c');
	}

	std::vector<int> values = lab7::GetValues(m1);
	{
		std::vector<int>::const_iterator it = values.begin();

		assert(*it == 1);
		it++;
		assert(*it == 2);
		it++;
		assert(*it == 3);
	}

	std::vector<int> reversedV1 = lab7::Reverse(v1);
	{
		assert(reversedV1[0] == v1[2]);
		assert(reversedV1[1] == v1[1]);
		assert(reversedV1[2] == v1[0]);
	}

	std::vector<int> combinedVector = v1 + v3;
	{
		assert(combinedVector.size() == 6);
		assert(combinedVector[0] == 1);
		assert(combinedVector[1] == 2);
		assert(combinedVector[2] == 3);
		assert(combinedVector[3] == 4);
		assert(combinedVector[4] == 5);
		assert(combinedVector[5] == 6);
	}

	std::map<char, int> combinedMap = m1 + m2;
	{
		std::map<char, int>::const_iterator it = combinedMap.begin();

		assert(combinedMap.size() == 6);

		assert(it->first == 'a');
		assert(it->second == 1);
		it++;
		assert(it->first == 'b');
		assert(it->second == 2);
		it++;
		assert(it->first == 'c');
		assert(it->second == 3);
		it++;
		assert(it->first == 'd');
		assert(it->second == 4);
		it++;
		assert(it->first == 'e');
		assert(it->second == 5);
		it++;
		assert(it->first == 'f');
		assert(it->second == 6);
	}

	std::cout << v1 << std::endl;
	std::cout << m1 << std::endl;

	return;
}