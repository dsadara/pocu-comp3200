#pragma once
#include <queue>

namespace lab9
{
	template <typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		ObjectPool(const ObjectPool& other) = delete;
		ObjectPool& operator=(const ObjectPool& rhs) = delete;

		T* Get();
		void Return(T* object);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();
	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjectPool;
		int mCurrPoolIndex;
	};

	template <typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		, mCurrPoolIndex(0)
	{
	}

	template <typename T>
	ObjectPool<T>::~ObjectPool()
	{
		// queue는 range base for 쓸수 없음
		while (mObjectPool.size() != 0)
		{
			delete mObjectPool.front();
			mObjectPool.pop();
		}
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjectPool.size() == 0)
		{
			return new T();
		}

		T* returnValue = mObjectPool.front();
		mObjectPool.pop();

		return returnValue;
	}

	template <typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (mObjectPool.size() == mMaxPoolSize)
		{
			delete object;
			return;
		}

		mObjectPool.push(object);
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjectPool.size();
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
}