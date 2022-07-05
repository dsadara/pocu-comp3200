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
		double mSum;
		double mSquaredSum;
	};

	template <typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0.0)
		, mSquaredSum(0.0)
	{
	}

	template <typename T>
	SmartQueue<T>::SmartQueue(const SmartQueue<T>& other)
		: mQueue(other.mQueue)
		, mSum(other.mSum)
		, mSquaredSum(other.mSquaredSum)
	{
	}

	template <typename T>
	SmartQueue<T>& SmartQueue<T>::operator=(const SmartQueue<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mSum = rhs.mSum;
		mSquaredSum = rhs.mSquaredSum;
		mQueue = rhs.mQueue;

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
		mSum += static_cast<double>(number);
		mSquaredSum += static_cast<double>(number) * static_cast<double>(number);
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
		mSum -= static_cast<double>(returnValue);
		mSquaredSum -= static_cast<double>(returnValue) * static_cast<double>(returnValue);
		return returnValue;
	}

	template <typename T>
	T SmartQueue<T>::GetMax()
	{
		int queueSize = mQueue.size();
		T* qArray = new T[queueSize];
		T max = std::numeric_limits<T>::lowest();
		for (int i = 0; i < queueSize; i++)
		{
			T element = mQueue.front();
			if (max < element)
			{
				max = element;
			}
			qArray[i] = element;
			mQueue.pop();

		}
		// 큐 원소 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			mQueue.push(qArray[i]);
		}

		delete[] qArray;
		return max;
	}

	template <typename T>
	T SmartQueue<T>::GetMin()
	{
		int queueSize = mQueue.size();
		T* qArray = new T[queueSize];
		T min = std::numeric_limits<T>::max();
		for (int i = 0; i < queueSize; i++)
		{
			T element = mQueue.front();
			if (min > element)
			{
				min = element;
			}
			qArray[i] = element;
			mQueue.pop();

		}
		// 큐 원소 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			mQueue.push(qArray[i]);
		}

		delete[] qArray;
		return min;
	}

	template <typename T>
	double SmartQueue<T>::GetAverage()
	{
		return mSum / static_cast<double>(mQueue.size());
	}

	template <typename T>
	T SmartQueue<T>::GetSum()
	{
		return static_cast<T>(mSum);
	}

	template <typename T>
	double SmartQueue<T>::GetVariance()
	{
		double avgSquare = GetAverage();
		avgSquare *= avgSquare;
		double squareAvg = mSquaredSum / static_cast<double>(mQueue.size());
		return squareAvg - avgSquare;
	}

	template <typename T>
	double SmartQueue<T>::GetStandardDeviation()
	{
		return std::sqrt(GetVariance());
	}

	template <typename T>
	unsigned int SmartQueue<T>::GetCount()
	{
		return mQueue.size();
	}
}



