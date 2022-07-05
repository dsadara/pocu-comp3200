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
		T mSum;
		double mSquaredSum;
	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(static_cast<T>(0))
		, mSquaredSum(0.0)
	{
	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
		: mMaxStack(other.mMaxStack)
		, mMinStack(other.mMinStack)
		, mActualStack(other.mActualStack)
		, mSum(other.mSum)
		, mSquaredSum(other.mSquaredSum)
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
		if (mMaxStack.empty())
		{
			mMaxStack.push(number);
			if (mMinStack.empty())
			{
				mMinStack.push(number);
			}
			mSum += number;
			mSquaredSum += static_cast<double>(number) * static_cast<double>(number);
			return;
		}
		if (mMinStack.empty())
		{
			mMinStack.push(number);
			if (mMaxStack.empty())
			{
				mMaxStack.push(number);
			}
			mSum += number;
			mSquaredSum += static_cast<double>(number) * static_cast<double>(number);
			return;
		}

		if (number >= mMaxStack.top())
		{
			mMaxStack.push(number);
		}
		if (number <= mMinStack.top())
		{
			mMinStack.push(number);
		}
		mSum += number;
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


		mSum -= returnValue;
		mSquaredSum -= static_cast<double>(returnValue) * static_cast<double>(returnValue);

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
		if (mMaxStack.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		return mMaxStack.top();
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		if (mMinStack.empty())
		{
			return std::numeric_limits<T>::max();
		}
		return mMinStack.top();
	}

	template<typename T>
	double SmartStack<T>::GetAverage()
	{
		unsigned int count = mActualStack.size();
		if (count == 0u)
		{
			return 0.0;
		}

		return static_cast<T>(mSum) / static_cast<double>(count);
	}

	template<typename T>
	T SmartStack<T>::GetSum()
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance()
	{
		unsigned int count = mActualStack.size();
		if (count == 0u)
		{
			return 0.0;
		}

		double squareAvg = mSquaredSum / static_cast<double>(count);
		double avgSquare = static_cast<double>(mSum) / static_cast<double>(count);
		avgSquare = avgSquare * avgSquare;
		return squareAvg - avgSquare;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation()
	{
		if (mActualStack.size() == 0u)
		{
			return 0.0;
		}
		return std::sqrt(GetVariance());
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount()
	{
		return mActualStack.size();
	}
}


