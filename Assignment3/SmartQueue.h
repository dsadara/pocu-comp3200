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
		//T mSum;
		//T mSquaredSum;
		//unsigned int mCount;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
		//: mSum(static_cast<T>(0))
		//, mSquaredSum(static_cast<T>(0))
		//, mCount(0u)
	{
	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: mQueue(other.mQueue)
		, mSmartStack(other.mSmartStack)
		/*, mSum(other.mSum)
		, mSquaredSum(other.mSquaredSum)
		, mCount(other.mCount)*/
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
		//mSum = rhs.mSum;
		//mSquaredSum = rhs.mSquaredSum;
		//mCount = rhs.mCount;
		

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
	/*	mSum += number;
		mSquaredSum += number * number;
		mCount++;*/
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
		mSmartStack.Pop();
		mQueue.pop();
		/*mSum -= returnValue;
		mSquaredSum -= returnValue * returnValue;
		mCount--;*/

		return returnValue;
	}

	template <typename T>
	T SmartQueue<T>::GetMax()
	{
		if (mSmartStack.GetCount() == 0)
		{
			return std::numeric_limits<T>::min();
		}

		//SmartStack<T> stack;
		//std::stack<T> stack2;

		//int count = static_cast<int>(mCount);	// 올바른 unsigned int to int casting 방법을 찾아보자 
		//for (int i = 0; i < count; i++)
		//{
		//	stack.Push(Dequeue());
		//}

		//T max = stack.GetMax();

		//for (int i = 0; i < count; i++)
		//{
		//	stack2.push(stack.Pop());
		//}

		//for (int i = 0; i < count; i++)
		//{
		//	Enqueue(stack2.pop());
		//}

		return mSmartStack.GetMax();
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		if (mSmartStack.GetCount()  == 0)
		{
			return std::numeric_limits<T>::max();
		}

		//SmartStack<T> stack;
		//std::stack<T> stack2;

		//int count = static_cast<int>(mCount);	// 올바른 unsigned int to int casting 방법을 찾아보자 
		//for (int i = 0; i < count; i++)
		//{
		//	stack.Push(Dequeue());
		//}

		//T min = stack.GetMin();

		//for (int i = 0; i < count; i++)
		//{
		//	stack2.push(stack.Pop());
		//}

		//for (int i = 0; i < count; i++)
		//{
		//	Enqueue(stack2.pop());
		//}

		return mSmartStack.GetMin();
	}

	template <typename T>
	double SmartQueue<T>::GetAverage()
	{
		//return static_cast<double>(mSum) / static_cast<double>(mCount);
		return mSmartStack.GetAverage();
	}

	template <typename T>
	T SmartQueue<T>::GetSum()
	{
		//return mSum;
		return mSmartStack.GetSum();
	}

	template <typename T>
	double SmartQueue<T>::GetVariance()
	{
		/*double squareAvg = static_cast<double>(mSquaredSum) / static_cast<double>(mCount);
		double avgSquare = static_cast<double>(mSum) / static_cast<double>(mCount);
		avgSquare = avgSquare * avgSquare;
		return squareAvg - avgSquare;*/

		return mSmartStack.GetVariance();
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		/*return std::sqrt(GetVariance());*/
		return mSmartStack.GetStandardDeviation();
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		//return mCount;
		return mSmartStack.GetCount();
	}
}



