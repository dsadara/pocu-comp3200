#pragma once
#include <stack>
#include <limits>

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

	};

	template<typename T>
	SmartStack<T>::SmartStack()
		: mMaxEle(std::numeric_limits<T>::min())
		, mMinEle(std::numeric_limits<T>::max())
	{

	}

	template<typename T>
	SmartStack<T>::SmartStack(const SmartStack<T>& other)
	{

	}

	template<typename T>
	SmartStack<T>& SmartStack<T>::operator=(const SmartStack<T>& rhs)
	{
		return this;
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
			mMaxStack.push(static_cast<T>(2) * number - mMaxEle);
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
			mMinStack.push(static_cast<T>(2) * number - mMinEle);
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


		mMaxStack.pop();
		mMinStack.pop();

		T returnValue = mActualStack.top();
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
		return mMaxEle;
	}

	template<typename T>
	T SmartStack<T>::GetMin()
	{
		return mMinEle;
	}

	template<typename T>
	double GetAverage()
	{

		return 0.0f;
	}

	template<typename T>
	T GetSum()
	{

		return static_Cast<T>(0);
	}

	template<typename T>
	double GetVariance()
	{

		return 0.0f;
	}

	template<typename T>
	double GetStandardDeviation()
	{
		return 0.0f;
	}

	template<typename T>
	unsigned int GetCount()
	{
		return 0u;
	}
}


