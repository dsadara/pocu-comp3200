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
		std::queue<SmartStack<T>*> mQueue;
		SmartStack<T>* mTmpStack;
		unsigned int mMaxStackSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mTmpStack = new SmartStack<T>;
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
	{
		mTmpStack = new SmartStack<T>;
		int queueSize = static_cast<int>(other.mQueue.size());
		std::queue<SmartStack<T>*> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			SmartStack<T>* frontStack = other.mQueue.front();
			other.mQueue.pop();
			tmpQueue.push(frontStack);
			SmartStack<T>* copiedStack = new SmartStack<T>;
			int stackSize = frontStack->GetCount();
			T* frontStackArray = new T[stackSize];

			// 동적 배열에 frontStack 대입
			for (int i = 0; i < stackSize; i++)
			{
				frontStackArray[i] = frontStack->Peek();
				frontStack->Pop();
			}

			// copiedStack에 대입, frontStack 다시 주워담기
			for (int i = stackSize - 1; i >= 0; i--)
			{
				copiedStack->Push(frontStackArray[i]);
				frontStack->Push(frontStackArray[i]);
			}
			delete[] frontStackArray;

			mQueue.push(copiedStack);
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			other.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack도 복사
		if (other.mTmpStack->GetCount() != 0)
		{
			int tmpStackSize = static_cast<int>(other.mTmpStack->GetCount());
			T* tmpStackArray = new T[tmpStackSize];

			// 스택 복사
			for (int i = 0; i < tmpStackSize; i++)
			{
				tmpStackArray[i] = other.mTmpStack->Peek();
				other.mTmpStack->Pop();
			}

			// 대입, 스택 다시 주워담기
			for (int i = tmpStackSize - 1; i >= 0; i--)
			{
				mTmpStack->Push(tmpStackArray[i]);
				other.mTmpStack->Push(tmpStackArray[i]);
			}

			delete[] tmpStackArray;
		}
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(QueueStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		int thisQueueSize = static_cast<int>(mQueue.size());
		for (int i = 0; i < thisQueueSize; i++)
		{
			SmartStack<T>* frontStack = mQueue.front();
			delete frontStack;
			mQueue.pop();
		}
		int mTmpStackSize = mTmpStack->GetCount();
		for (int i = 0; i < mTmpStackSize; i++)
		{
			mTmpStack->Pop();
		}

		mMaxStackSize = rhs.mMaxStackSize;

		int queueSize = static_cast<int>(rhs.mQueue.size());
		std::queue<SmartStack<T>*> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			SmartStack<T>* frontStack = rhs.mQueue.front();
			rhs.mQueue.pop();
			tmpQueue.push(frontStack);
			SmartStack<T>* copiedStack = new SmartStack<T>;
			int stackSize = frontStack->GetCount();
			T* frontStackArray = new T[stackSize];

			// 동적 배열에 frontStack 대입
			for (int i = 0; i < stackSize; i++)
			{
				frontStackArray[i] = frontStack->Peek();
				frontStack->Pop();
			}

			// copiedStack에 대입, frontStack 다시 주워담기
			for (int i = stackSize - 1; i >= 0; i--)
			{
				copiedStack->Push(frontStackArray[i]);
				frontStack->Push(frontStackArray[i]);
			}
			delete[] frontStackArray;

			mQueue.push(copiedStack);
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			rhs.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack도 복사
		if (rhs.mTmpStack->GetCount() != 0)
		{
			int tmpStackSize = rhs.mTmpStack->GetCount();
			T* tmpStackArray = new T[tmpStackSize];

			// 스택 복사
			for (int i = 0; i < tmpStackSize; i++)
			{
				tmpStackArray[i] = rhs.mTmpStack->Peek();
				rhs.mTmpStack->Pop();
			}

			// 대입, 스택 다시 주워담기
			for (int i = tmpStackSize - 1; i >= 0; i--)
			{
				mTmpStack->Push(tmpStackArray[i]);
				rhs.mTmpStack->Push(tmpStackArray[i]);
			}

			delete[] tmpStackArray;
		}

		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		int mQueueSize = static_cast<int>(mQueue.size());
		for (int i = 0; i < mQueueSize; i++)
		{
			SmartStack<T>* frontStack = mQueue.front();
			delete frontStack;
			mQueue.pop();
		}
		delete mTmpStack;
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		mTmpStack->Push(number);
		if (mTmpStack->GetCount() == mMaxStackSize)
		{
			mQueue.push(mTmpStack);
			mTmpStack = new SmartStack<T>;
		}
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		if (mQueue.size() == 0)
		{
			return mTmpStack->Peek();
		}
		return mQueue.front()->Peek();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T result;
		if (mQueue.size() == 0)
		{
			result = mTmpStack->Peek();
			mTmpStack->Pop();
			return result;
		}
		SmartStack<T>* frontStack = mQueue.front();
		result = frontStack->Peek();
		frontStack->Pop();
		if (frontStack->GetCount() == 0)
		{
			delete mQueue.front();
			mQueue.pop();
		}
		return result;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>*> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			T stackMax = mQueue.front()->GetMax();
			if (max < stackMax)
			{
				max = stackMax;
			}
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}
		// 스택 주워 담기 
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}


		if (max < mTmpStack->GetMax())
		{
			max = mTmpStack->GetMax();
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>*> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			T stackMin = mQueue.front()->GetMin();
			if (min > stackMin)
			{
				min = stackMin;
			}
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}
		// 스택 주워담기
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		if (min > mTmpStack->GetMin())
		{
			min = mTmpStack->GetMin();
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
		T sum = 0;
		int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>*> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			sum += mQueue.front()->GetSum();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}

		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		sum += mTmpStack->GetSum();

		return sum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		int count = 0;
		int mQueueSize = mQueue.size();
		std::queue<SmartStack<T>*> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			count += mQueue.front()->GetCount();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}

		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		count += mTmpStack->GetCount();

		return count;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		if (mTmpStack->GetCount() == 0)
			return mQueue.size();

		return mQueue.size() + 1;
	}

}

