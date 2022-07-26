#pragma once

#include <memory>
#include <iostream>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		~Storage();
		Storage(Storage& other);
		Storage(Storage&& other);
		Storage& operator=(Storage& rhs);
		Storage& operator=(Storage&& rhs);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
		void PrintStorage() const;
	private:
		T* mMem;
		unsigned int mLength;
		std::unique_ptr<T[]> mReturnPtr;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mMem(new T[length])
		, mLength(length)
		, mReturnPtr(mMem)
	{
		memset(mMem, 0, length * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mMem(new T[length])
		, mLength(length)
		, mReturnPtr(mMem)
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			mMem[i] = initialValue;
		}
	}

	template<typename T>
	Storage<T>::~Storage()
	{
		mReturnPtr.release();
		delete[] mMem;
	}

	template<typename T>
	Storage<T>::Storage(Storage& other)
		: mMem(new T[other.mLength])
		, mLength(other.mLength)
		, mReturnPtr(mMem)
	{
		memcpy(mMem, other.mMem, mLength * sizeof(T));
	}

	template<typename T>
	Storage<T>::Storage(Storage&& other)
		: mMem(other.mMem)
		, mLength(other.mLength)
		, mReturnPtr(mMem)
	{
		other.mMem = nullptr;
		other.mLength = 0;
		other.mReturnPtr.release();
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		if (mLength == rhs.mLength)
		{
			memcpy(mMem, rhs.mMem, mLength * sizeof(T));
			return *this;
		}
		mLength = rhs.mLength;
		delete[] mMem;
		mMem = new T[mLength];
		mReturnPtr.release();
		mReturnPtr.reset(mMem);
		memcpy(mMem, rhs.mMem, mLength * sizeof(T));
		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}
		delete[] mMem;
		mMem = rhs.mMem;
		mLength = rhs.mLength;
		mReturnPtr.release();
		mReturnPtr.reset(mMem);

		rhs.mMem = nullptr;
		rhs.mLength = 0;
		rhs.mReturnPtr.release();
		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mLength)
		{
			return false;
		}
		mMem[index] = data;
		return true;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		//mReturnPtr = std::make_unique<T[]>(1);
		//std::unique_ptr<T[]> temp = std::unique_ptr<T[]>(mMem);
		//mReturnPtr.reset(mMem);
		return std::move(mReturnPtr);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}

	template<typename T>
	void Storage<T>::PrintStorage() const
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			std::cout << mMem[i] << ", ";
		}
		std::cout << std::endl;
	}

}