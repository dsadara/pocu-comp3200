#pragma once
#include <stack>
#include <queue>

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
			std::stack<T>* copiedStack = new std::stack<T>;
			std::stack<T> tmpStack;
			int stackSize = frontStack->size();

			// frontStack -> tmpStack
			for (int i = 0; i < stackSize; i++)
			{
				T number = frontStack->top();
				frontStack->pop();
				tmpStack.push(number);
			}

			// tmpStack -> copiedStack

			for (int i = 0; i < stackSize; i++)
			{
				T number = tmpStack.top();
				tmpStack.pop();
				copiedStack->push(number);
			}


			// 스택 다시 주워담기
			for (int i = 0; i < stackSize; i++)
			{
				frontStack->push(tmpStack.top());
				tmpStack.pop();
			}

			mQueue.push(copiedStack);
			tmpQueue.push(other.mQueue.front());
			other.mQueue.pop();
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
			std::stack<T> tmpOfMTmpStack;
			// 스택 복사
			for (int i = 0; i < tmpStackSize; i++)
			{
				T element = other.mTmpStack->top();
				mTmpStack->push(element);
				tmpOfMTmpStack.push(element);
				other.mTmpStack->pop();
			}

			// 스택 다시 주워담기
			for (int i = 0; i < tmpStackSize; i++)
			{
				T element = tmpOfMTmpStack.top();
				other.mTmpStack->push(element);
				tmpOfMTmpStack.pop();
			}

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
		
		// 기존 큐스택 지우기
		int queueSize = static_cast<int>(GetStackCount());
		for (int i = 0; i < queueSize; i++)
		{
			std::stack<T>* frontStack = mQueue.front();
			delete frontStack;
			mQueue.pop();
		}
		// mTmpStack 지우기
		int mTmpStackSize = rhs.mTmpStack->size();
		for (int i = 0; i < mTmpStackSize; i++)
		{
			mTmpStack->pop();
		}

		std::queue<std::stack<T>*> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			std::stack<T>* frontStack = rhs.mQueue.front();
			std::stack<T>* copiedStack = new std::stack<T>;
			std::stack<T> tmpStack = std::stack<T>;
			int stackSize = frontStack->size();

			// 스택 복사
			for (int i = 0; i < stackSize; i++)
			{
				T number = frontStack->top();
				frontStack->pop();
				copiedStack->push(number);
				tmpStack.push(number);
			}

			// 스택 다시 주워담기
			for (int i = 0; i < stackSize; i++)
			{
				frontStack->push(tmpStack.top());
				tmpStack.pop();
			}

			mQueue.push(copiedStack);
			tmpQueue.push(rhs.mQueue.front());
			rhs.mQueue.pop();
		}
		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			rhs.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack 복사
		if (rhs.mTmpStack->size())
		{
			return *this;
		}
		int rhsmTmpStackSize = rhs.mTmpStack->size();
		std::stack<T> tmpOfRhsMTmpOfStack;
		// 스택 복사
		for (int i = 0; i < rhsmTmpStackSize; i++)
		{
			T element = rhs.mTmpStack->top();
			mTmpStack->push(element);
			tmpOfRhsMTmpOfStack.push(element);
			rhs.mTmpStack->pop();
		}
		// 스택 주워담기
		for (int i = 0; i < rhsmTmpStackSize; i++)
		{
			T element = tmpOfRhsMTmpOfStack.top();
			rhs.mTmpStack->push(element);
			tmpOfRhsMTmpOfStack.pop();
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

