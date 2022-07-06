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
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mQueue.push(SmartStack<T>());
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
	{
		mQueue = other.mQueue;
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
			T stackMax = mQueue.front().GetMax();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
			if (max < stackMax)
			{
				max = stackMax;
			}
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
			T stackMin = mQueue.front().GetMin();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
			if (min > stackMin)
			{
				min = stackMin;
			}
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
		T sum = static_cast<T>(0);
		unsigned int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>> tmpQueue;

		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			sum += mQueue.front().GetSum();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}
		// 스택 다시 담기
		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}
		return sum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		unsigned int count = 0u;
		unsigned int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>> tmpQueue;

		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			count += mQueue.front().GetCount();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}
		for (unsigned int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}
		return count;
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

