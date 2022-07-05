#pragma once
#include <queue>
#include <cmath>
#include "SmartStack.h"

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue(const SmartQueue& other);
		SmartQueue& operator=(const SmartQueue& rhs);
		virtual ~SmartQueue();

		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	private:
		std::queue<T> mQueue;
		SmartStack<T> mSmartStack;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
	{
	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: mQueue(other.mQueue)
		, mSmartStack(other.mSmartStack)
	{
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mQueue = rhs.mQueue;
		mSmartStack = rhs.mSmartStack;

		return *this;
	}

	template <typename T>
	SmartQueue<T>::~SmartQueue()
	{

	}

	template <typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mQueue.push(number);
		mSmartStack.Push(number);
	}

	template <typename T>
	T SmartQueue<T>::Peek()
	{
		return mQueue.front();
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		T returnValue = mQueue.front();
		mQueue.pop();

		// 스택은 맨 앞에 원소를 pop
		int smartStackSize = mSmartStack.GetCount();
		T* stackArray = new T[smartStackSize];
		for (int i = 0; i < smartStackSize; i++)
		{
			stackArray[i] = mSmartStack.Pop();
		}
		for (int i = smartStackSize - 2; i >= 0; i--)
		{
			mSmartStack.Push(stackArray[i]);
		}
		delete[] stackArray;
		return returnValue;
	}

	template <typename T>
	T SmartQueue<T>::GetMax()
	{
		return mSmartStack.GetMax();
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		return mSmartStack.GetMin();
	}

	template <typename T>
	double SmartQueue<T>::GetAverage()
	{
		return mSmartStack.GetAverage();
	}

	template <typename T>
	T SmartQueue<T>::GetSum()
	{
		return mSmartStack.GetSum();
	}

	template <typename T>
	double SmartQueue<T>::GetVariance()
	{
		return mSmartStack.GetVariance();
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return mSmartStack.GetStandardDeviation();
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mSmartStack.GetCount();
	}
}



