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
		void pushMaxStack(T number);
		void pushMinStack(T number);
		std::stack<T> mMaxStack;
		std::stack<T> mActualStack;
		std::stack<T> mMinStack;
		T mMaxEle;
		T mMinEle;
		T mSum;
		T mSquaredSum;
		unsigned int mCount;

	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mMaxEle(std::numeric_limits<T>::lowest())
		, mMinEle(std::numeric_limits<T>::max())
		, mSum(static_cast<T>(0))
		, mSquaredSum(static_cast<T>(0))
		, mCount(0u)
	{
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mMaxEle(other.mMaxEle)
		, mMinEle(other.mMinEle)
		, mMaxStack(other.mMaxStack)
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

		mMaxEle = rhs.mMaxEle;
		mMinEle = rhs.mMinEle;
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
		pushMaxStack(number);
		pushMinStack(number);
		mCount++;
		mSum += number;
		mSquaredSum += number * number;
	}

	template<typename T>
	void SmartStack<T>::pushMaxStack(T number)
	{
		if (mMaxStack.empty())
		{
			mMaxStack.push(number);
			mMaxEle = number;
			return;
		}

		if (number <= mMaxEle)
		{
			mMaxStack.push(number);
		}
		else
		{
			mMaxStack.push(static_cast<T>(2.0) * number - mMaxEle);
			mMaxEle = number;
		}
	}

	template<typename T>
	void SmartStack<T>::pushMinStack(T number)
	{
		if (mMinStack.empty())
		{
			mMinStack.push(number);
			mMinEle = number;
			return;
		}

		if (number >= mMinEle)
		{
			mMinStack.push(number);
		}
		else
		{
			mMinStack.push(static_cast<T>(2.0) * number - mMinEle);
			mMinEle = number;
		}
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		if (mMaxStack.top() > mMaxEle)
		{
			mMaxEle = static_cast<T>(2) * mMaxEle - mMaxStack.top();
		}
		if (mMinStack.top() < mMinEle)
		{
			mMinEle = static_cast<T>(2) * mMinEle - mMinStack.top();
		}

		T returnValue = mActualStack.top();
		mSum -= returnValue;
		mSquaredSum -= returnValue * returnValue;
		mCount--;

		mActualStack.pop();
		mMaxStack.pop();
		mMinStack.pop();

		if (mActualStack.empty())
		{
			mMaxEle = std::numeric_limits<T>::lowest();
			mMinEle = std::numeric_limits<T>::max();
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
		return mMaxEle;
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mMinEle;
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


