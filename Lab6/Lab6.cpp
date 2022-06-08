#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int size = v.size();
		if (size == 0)
		{
			return 0;
		}

		int result = 0;

		for (int i = 0; i < size; i++)
		{
			result += v[i];
		}

		return result;
	}

	int Min(const std::vector<int>& v)
	{
		int size = v.size();
		if (size == 0)
		{
			return INT_MAX;
		}
		int min = v[0];

		for (int i = 0; i < size; i++)
		{
			if (min > v[i])
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		int size = v.size();
		if (size == 0)
		{
			return INT_MIN;
		}
		int max = v[0];

		for (int i = 0; i < size; i++)
		{
			if (max < v[i])
			{
				max = v[i];
			}
		}
		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0.0f;
		}
		float sum = static_cast<float>(Sum(v));
		return sum / static_cast<float>(v.size());
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		int size = v.size();
		if (size == 0)
		{
			return 0;
		}

		std::map<int, int> m;

		// put all elements in map
		for (int i = 0; i < size; i++)
		{
			std::pair<std::map<int, int>::iterator, bool> p = m.insert(std::pair<int, int>(v[i], 1));
			// 해당 키가 이미 들어가 있으면 
			if (p.second == false)
			{
				m[v[i]]++;
			}
		}

		std::map<int, int>::iterator it = m.begin();
		int maxKey = it->first;
		int maxValue = it->second;
		// find max Occurence element
		for (; it != m.end(); ++it)
		{
			if (it->second > maxValue)
			{
				maxKey = it->first;
				maxValue = it->second;
			}
		}

		return maxKey;
	}

	void SortDescending(std::vector<int>& v)
	{
		int size = v.size();
		if (size == 0)
		{
			return;
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				if (v[j] < v[j + 1])
				{
					int tmp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = tmp;
				}
			}
		}

		//std::map<int, int, std::greater<int>> m;

		//// put all elements in map
		//for (int i = 0; i < size; i++)
		//{
		//	std::pair<std::map<int, int>::iterator, bool> p = m.insert(std::pair<int, int>(v[i], 1));
		//	// 해당 키가 이미 들어가 있으면 
		//	if (p.second == false)
		//	{
		//		m[v[i]]++;
		//	}
		//}

		//// vector 모든 값 제거
		//v.clear();

		//// map 순서대로 vector에 대입


		//for (std::map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		//{
		//	for (int i = 0; i < iter->second; i++)
		//	{
		//		v.push_back(iter->first);
		//	}
		//}
	}

}