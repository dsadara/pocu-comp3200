#pragma once
#include <stack>
#include <queue>
#include <limits>
#include "SmartStack.h"

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:	// copy const, assignment op, destructor
		QueueStack(unsigned int maxStackSize);
		QueueStack(QueueStack& other);
		QueueStack& operator=(QueueStack& rhs);
		virtual ~QueueStack();

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue<SmartStack<T>> mQueue;
		unsigned int mMaxStackSize;
		T mSum;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
		, mSum(static_cast<T>(0))
	{
		mQueue.push(SmartStack<T>());
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
		, mSum(other.mSum)
		, mQueue(other.mQueue)	// 이거 안 될 수도 있음
	{
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(QueueStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mQueue = rhs.mQueue;
		mMaxStackSize = rhs.mMaxStackSize;
		mSum = rhs.mSum;
		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		mQueue.back().Push(number);
		mSum += number;
		if (mQueue.back().GetCount() == mMaxStackSize)
		{
			mQueue.push(SmartStack<T>());
		}

	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().Peek();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T result = mQueue.front().Peek();
		mSum -= result;
		mQueue.front().Pop();
		if (mQueue.size() != 1 && mQueue.front().GetCount() == 0u)
		{
			mQueue.pop();
		}
		return result;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		unsigned int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>> tmpQueue;

		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			tmpQueue.push(mQueue.front());
			if (max < mQueue.front().GetMax())
			{
				max = mQueue.front().GetMax();
			}
			mQueue.pop();
		}
		// 스택 주워 담기
		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		unsigned int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>> tmpQueue;

		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			tmpQueue.push(mQueue.front());
			if (min > mQueue.front().GetMin())
			{
				min = mQueue.front().GetMin();
			}
			mQueue.pop();
		}
		// 스택 주워 담기
		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}
		return min;
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
		return static_cast<double>(GetSum()) / static_cast<double>(GetCount());

	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		if (mQueue.size() == 1)
		{
			return mQueue.front().GetCount();
		}
		if (mQueue.size() == 2)
		{
			return mQueue.front().GetCount() + mQueue.back().GetCount();
		}
		return  mMaxStackSize * (mQueue.size() - 2) + mQueue.front().GetCount() + mQueue.back().GetCount();
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		if (mQueue.back().GetCount() == 0u)
		{
			return mQueue.size() - 1;
		}
		return mQueue.size();
	}

}

