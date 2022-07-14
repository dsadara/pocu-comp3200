#pragma once
#include <queue>
#include <memory>

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
		std::queue<std::unique_ptr<T>> mObjectPool;
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
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjectPool.size() == 0)
		{
			return new T();
		}

		T* rPtr = std::move(mObjectPool.front()).release(); // 어차피 반환값 대입만 할꺼니까 rvalue로 꺼내는게 좋을듯
		mObjectPool.pop();
		return rPtr;
	}

	template <typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (mObjectPool.size() == mMaxPoolSize)
		{
			delete object;
			return;
		}
		mObjectPool.push(std::unique_ptr<T>(object));	// 임시개체로 변경
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