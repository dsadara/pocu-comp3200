#pragma once

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();
		bool Add(bool t);
		bool Remove(bool t);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool t);
		size_t GetSize();
		size_t GetCapacity();
	private:
		size_t mSize;
		int mArray[(N + 32 - 1) / 32];
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
		, mArray{ 0 }
	{
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(bool t)
	{
		if (mSize > N - 1)
		{
			return false;
		}

		unsigned int mArrayIndex = mSize / 32u;
		unsigned int mSizeBitNumber = mSize - mArrayIndex * 32;
		if (t)
		{
			mArray[mArrayIndex] |= (1 << mSizeBitNumber);	// 비트 1로 세트 
		}
		else
		{
			mArray[mArrayIndex] &= ~(1 << mSizeBitNumber);
		}
		mSize++;
		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(bool t)
	{
		int tIndex = GetIndex(t);
		if (tIndex == -1)
		{
			return false;
		}
		for (int i = tIndex; i < static_cast<int>(mSize) - 1; i++)
		{
			unsigned int currMArrayIndex = static_cast<unsigned int>(i) / 32u;
			unsigned int currMSizeBitNumber = static_cast<unsigned int>(i) - currMArrayIndex * 32u;
			/*unsigned int nextMArrayIndex = static_cast<unsigned int>(i + 1) / 32u;
			unsigned int nextMSizeBitNumber = static_cast<unsigned int>(i + 1) - nextMArrayIndex * 32u;*/
			bool nextEle = Get(i + 1);
			if (nextEle)
			{
				mArray[currMArrayIndex] |= (1 << currMSizeBitNumber);
			}
			else
			{
				mArray[currMArrayIndex] &= ~(1 << currMSizeBitNumber);
			}
		}
		mSize--;
		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		if (index > mSize)
		{
			return false;
		}

		unsigned int mArrayIndex = index / 32u;
		unsigned int mSizeBitNumber = index - mArrayIndex * 32;

		return static_cast<bool>(mArray[mArrayIndex] & (1 << mSizeBitNumber));

	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return Get(index);
	}

	template<size_t N>
	int FixedVector<bool, N>::GetIndex(bool t)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			unsigned int mArrayIndex = i / 32u;
			unsigned int mSizeBitNumber = i - mArrayIndex * 32;

			bool result = static_cast<bool>(mArray[mArrayIndex] & (1 << mSizeBitNumber));
			if (t == result)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize()
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}
}