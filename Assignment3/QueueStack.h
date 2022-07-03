#pragma once
#include <stack>
#include <queue>
#include <limits>

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
		void GetMax();
		void GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue<std::stack<T>*> mQueue;
		std::stack<T>* mTmpStack;
		unsigned int mMaxStackSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mTmpStack = new std::stack<T>;
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
	{
		mTmpStack = new std::stack<T>;
		int queueSize = static_cast<int>(other.mQueue.size());
		std::queue<std::stack<T>*> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			std::stack<T>* frontStack = other.mQueue.front();
			other.mQueue.pop();
			tmpQueue.push(frontStack);
			std::stack<T>* copiedStack = new std::stack<T>;
			int stackSize = frontStack->size();
			T* frontStackArray = new T[stackSize];

			// 동적 배열에 frontStack 대입
			for (int i = 0; i < stackSize; i++)
			{
				frontStackArray[i] = frontStack->top();
				frontStack->pop();
			}

			// copiedStack에 대입, frontStack 다시 주워담기
			for (int i = stackSize - 1; i >= 0; i--)
			{
				copiedStack->push(frontStackArray[i]);
				frontStack->push(frontStackArray[i]);
			}
			delete frontStackArray;

			mQueue.push(copiedStack);
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			other.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack도 복사
		if (other.mTmpStack->size() != 0)
		{
			int tmpStackSize = other.mTmpStack->size();
			T* tmpStackArray = new T[tmpStackSize];

			// 스택 복사
			for (int i = 0; i < tmpStackSize; i++)
			{
				tmpStackArray[i] = other.mTmpStack->top();
				other.mTmpStack->pop();
			}

			// 대입, 스택 다시 주워담기
			for (int i = tmpStackSize - 1; i >= 0; i--)
			{
				mTmpStack->push(tmpStackArray[i]);
				other.mTmpStack->push(tmpStackArray[i]);
			}

			delete tmpStackArray;
		}
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(QueueStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		mMaxStackSize = rhs.mMaxStackSize;
		
		int queueSize = static_cast<int>(rhs.mQueue.size());
		std::queue<std::stack<T>*> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			std::stack<T>* frontStack = rhs.mQueue.front();
			rhs.mQueue.pop();
			tmpQueue.push(frontStack);
			std::stack<T>* copiedStack = new std::stack<T>;
			int stackSize = frontStack->size();
			T* frontStackArray = new T[stackSize];

			// 동적 배열에 frontStack 대입
			for (int i = 0; i < stackSize; i++)
			{
				frontStackArray[i] = frontStack->top();
				frontStack->pop();
			}

			// copiedStack에 대입, frontStack 다시 주워담기
			for (int i = stackSize - 1; i >= 0; i--)
			{
				copiedStack->push(frontStackArray[i]);
				frontStack->push(frontStackArray[i]);
			}
			delete frontStackArray;

			mQueue.push(copiedStack);
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			rhs.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack도 복사
		if (rhs.mTmpStack->size() != 0)
		{
			int tmpStackSize = rhs.mTmpStack->size();
			T* tmpStackArray = new T[tmpStackSize];

			// 스택 복사
			for (int i = 0; i < tmpStackSize; i++)
			{
				tmpStackArray[i] = rhs.mTmpStack->top();
				rhs.mTmpStack->pop();
			}

			// 대입, 스택 다시 주워담기
			for (int i = tmpStackSize - 1; i >= 0; i--)
			{
				mTmpStack->push(tmpStackArray[i]);
				rhs.mTmpStack->push(tmpStackArray[i]);
			}

			delete tmpStackArray;
		}

		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
		int mQueueSize = static_cast<int>(mQueue.size());
		for (int i = 0; i < mQueueSize; i++)
		{
			std::stack<T>* frontStack = mQueue.front();
			delete frontStack;
			mQueue.pop();
		}
		delete mTmpStack;
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		mTmpStack->push(number);
		if (mTmpStack->size() == mMaxStackSize)
		{
			mQueue.push(mTmpStack);
			mTmpStack = new std::stack<T>;
		}
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		if (mQueue.size() == 0)
		{
			return mTmpStack->top();
		}
		return mQueue.front()->top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T result;
		if (mQueue.size() == 0)
		{
			result = mTmpStack->top();
			mTmpStack->pop();
			return result;
		}
		std::stack<T>* frontStack = mQueue.front();
		result = frontStack->top();
		frontStack->pop();
		if (frontStack->size() == 0)
		{
			delete mQueue.front();
			mQueue.pop();
		}
		return result;
	}

	template<typename T>
	void QueueStack<T>::GetMax()
	{
	
	}

	template<typename T>
	void QueueStack<T>::GetMin()
	{
	
	}

	template<typename T>
	double QueueStack<T>::GetAverage()
	{
	
	}

	template<typename T>
	T QueueStack<T>::GetSum()
	{

	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
	
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		if (mTmpStack->size() == 0)
			return mQueue.size();

		return mQueue.size() + 1;
	}

}

