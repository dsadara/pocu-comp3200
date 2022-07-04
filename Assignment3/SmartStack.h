#pragma once
#include <stack>
#include <limits>
#include <cmath>
#include <type_traits>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		SmartStack(const SmartStack& other);
		SmartStack& operator=(const SmartStack& rhs);
		virtual ~SmartStack();

		void Push(T number);
		T Pop();
		T Peek();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		double GetVariance();
		double GetStandardDeviation();
		unsigned int GetCount();
	private:
		std::stack<T> mMaxStack;
		std::stack<T> mActualStack;
		std::stack<T> mMinStack;
		T mSum;
		T mSquaredSum;
		unsigned int mCount;

	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<T>(0))
		, mCount(0u)
	{
		mMaxStack.push(std::numeric_limits<T>::lowest());
		mMinStack.push(std::numeric_limits<T>::max());
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mMaxStack(other.mMaxStack)
		, mMinStack(other.mMinStack)
		, mActualStack(other.mActualStack)
		, mSum(other.mSum)
		, mSquaredSum(other.mSquaredSum)
		, mCount(other.mCount)
	{
	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mMaxStack = rhs.mMaxStack;
		mMinStack = rhs.mMinStack;
		mActualStack = rhs.mActualStack;
		mSum = rhs.mSum;
		mSquaredSum = rhs.mSquaredSum;
		mCount = rhs.mCount;

		return *this;
	}

	template<typename T>
	SmartStack<T>::~SmartStack()
	{
	}

	template<typename T>
	void SmartStack<T>::Push(T number)
	{
		mActualStack.push(number);
		if (number >= mMaxStack.top())
		{
			mMaxStack.push(number);
		}
		if (number <= mMinStack.top())
		{
			mMinStack.push(number);
		}
		mCount++;
		mSum += number;
		mSquaredSum += number * number;
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T returnValue = mActualStack.top();
		if (mMaxStack.top() == returnValue)
		{
			mMaxStack.pop();
		}
		if (mMinStack.top() == returnValue)
		{
			mMinStack.pop();
		}


		mSum -= returnValue;
		mSquaredSum -= returnValue * returnValue;
		mCount--;

		mActualStack.pop();

		return returnValue;
	}

	template<typename T>
	T SmartStack<T>::Peek()
	{
		return mActualStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax()
	{
		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mMinStack.top();
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		if (mCount == 0u)
		{
			return 0.0;
		}

		return static_cast<double>(mSum) / static_cast<double>(mCount);
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		double squareAvg = static_cast<double>(mSquaredSum) / static_cast<double>(mCount);
		double avgSquare = static_cast<double>(mSum) / static_cast<double>(mCount);
		avgSquare = avgSquare * avgSquare;
		return squareAvg - avgSquare;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		return std::sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mCount;
	}
}


