#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		int kSize = keys.size();
		int vSize = values.size();
		int minSize = 0;

		if (kSize > vSize)
		{
			minSize = vSize;
		}
		else
		{
			minSize = kSize;
		}

		std::map<K, V> m;

		for (int i = 0; i < minSize; i++)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			v.push_back(it->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			v.push_back(it->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		for (int i = v.size() - 1; i >= 0; i--)
		{
			rv.push_back(v[i]);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;

		for (unsigned int i = 0; i < v1.size(); i++)
		{
			combined.push_back(v1[i]);
		}
		for (unsigned int j = 0; j < v2.size(); j++)
		{
			combined.push_back(v2[j]);
		}

		bool bErased = false;		// flag를 이용한 이중 continue

		for (auto it = combined.begin(); it != combined.end();)
		{
			for (auto it2 = combined.begin(); it2 != it; ++it2)
			{
				if (*it2 == *it)
				{
					it = combined.erase(it);
					bErased = true;
					break;
				}
			}
			if (bErased == true)
			{
				bErased = false;
				continue;
			}
			it++;
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (typename std::map<K, V>::const_iterator it = m1.begin(); it != m1.end(); ++it)
		{
			combined.insert(std::pair<K, V>(it->first, it->second));
		}

		for (typename std::map<K, V>::const_iterator it = m2.begin(); it != m2.end(); ++it)
		{
			combined.insert(std::pair<K, V>(it->first, it->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			if (i == 0)
			{
				os << v[i];
				continue;
			}
			os << ", " << v[i];
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator it = m.begin(); it != m.end(); ++it)
		{
			os << "{ " << it->first << ", " << it->second << " }" << std::endl;
		}
		return os;
	}
}