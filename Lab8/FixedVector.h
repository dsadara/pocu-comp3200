#pragma once

namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		bool Add(T& t);
		bool Remove(T t);
		const T& Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(T t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(T& t)
	{
		if (mSize > N - 1)
		{
			return false;
		}
		mArray[mSize++] = t;
		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(T t)
	{
		int i = GetIndex(t);
		if (i == -1)
		{
			return false;
		}
		for (int j = i; j < static_cast<int>(mSize) - 1; j++)
		{
			mArray[j] = mArray[j + 1];
		}
		mSize--;
		return true;
	}

	template<typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArray[index];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(T t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mArray[i] == t)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize()
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}

}