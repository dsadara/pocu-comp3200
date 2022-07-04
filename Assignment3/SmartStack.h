#pragma once
#include <stack>
#include <limits>
#include <cmath>

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
		double mSum;
		double mSquaredSum;
		unsigned int mCount;

	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0.0)
		, mSquaredSum(0.0)
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
		mSum += static_cast<double>(number);
		mSquaredSum += static_cast<double>(number) * static_cast<double>(number);
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


		mSum -= static_cast<double>(returnValue);
		mSquaredSum -= static_cast<double>(returnValue) * static_cast<double>(returnValue);
		mCount--;

		mActualStack.pop();

		// 스택이 비어있을 때마다 0을 대입
		if (mCount == 0)
		{
			mSquaredSum == 0.0;
			mSum == 0.0;
		}

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

		return mSum / mCount;
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		if (mCount == 0u)
		{
			return 0.0;
		}

		double squareAvg = mSquaredSum / mCount;
		double avgSquare = mSum / mCount;
		avgSquare = avgSquare * avgSquare;
		return squareAvg - avgSquare;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		if (mCount == 0u)
		{
			return 0.0;
		}
		return std::sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mCount;
	}
}


