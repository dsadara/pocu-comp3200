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
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	private:
		std::queue<std::stack<T>> mQueue;
		unsigned int mMaxStackSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
		mQueue.push(std::stack<T>());
	}

	template<typename T>
	QueueStack<T>::QueueStack(QueueStack<T>& other)
		: mMaxStackSize(other.mMaxStackSize)
	{
		int queueSize = static_cast<int>(other.mQueue.size());
		std::queue<std::stack<T>> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			tmpQueue.push(other.mQueue.front());
			mQueue.push(other.mQueue.front());
			other.mQueue.pop();
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			other.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}
	}

	template<typename T>
	QueueStack<T>& QueueStack<T>::operator=(QueueStack<T>& rhs)
	{
		if (this == &rhs)
		{
			return *this;
		}

		// mQueue, mTmpStack 비우기 
		int thisQueueSize = static_cast<int>(mQueue.size());
		for (int i = 0; i < thisQueueSize; i++)
		{
			mQueue.pop();
		}

		mMaxStackSize = rhs.mMaxStackSize;
		int rhsQueueSize = static_cast<int>(rhs.mQueue.size());
		std::queue<std::stack<T>> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < rhsQueueSize; i++)
		{
			tmpQueue.push(rhs.mQueue.front());
			mQueue.push(rhs.mQueue.front());
			rhs.mQueue.pop();
		}

		// 큐 다시 주워담기
		for (int i = 0; i < rhsQueueSize; i++)
		{
			rhs.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		return *this;
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mMaxStackSize == 0)
		{
			return;
		}

		mQueue.back().push(number);
		if (mQueue.back().size() == mMaxStackSize)
		{
			mQueue.push(std::stack<T>());
		}

	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T result = mQueue.front().top();
		mQueue.front().pop();
		if (mQueue.front().size() == 0)
		{
			mQueue.pop();
		}
		return result;
	}

	template<typename T>
	T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();
		int mQueueSize = mQueue.size();
		std::queue<std::stack<T>> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			// 스택 pop 하며 max값 찾기
			// 스택 도로 집어넣기
			tmpQueue.push(mQueue.front());

			// 스택 안 max 찾기
			int tmpSize = mQueue.front().size();
			for (int i = 0; i < tmpSize; i++)
			{
				if (max < mQueue.front().top())
				{
					max = mQueue.front().top();
				}
				mQueue.front().pop();
			}
			mQueue.pop();
		}
		// 스택 주워 담기 
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		int mQueueSize = mQueue.size();
		std::queue<std::stack<T>> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			// 스택 pop 하며 min값 찾기
			// 스택 도로 집어넣기
			tmpQueue.push(mQueue.front());

			// 스택 안 min 찾기
			int tmpSize = mQueue.front().size();
			for (int i = 0; i < tmpSize; i++)
			{
				if (min > mQueue.front().top())
				{
					min = mQueue.front().top();
				}
				mQueue.front().pop();
			}
			mQueue.pop();
		}
		// 스택 주워 담기 
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
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
		T sum = static_cast<T>(0);
		int mQueueSize = mQueue.size();
		std::queue<std::stack<T>> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			tmpQueue.push(mQueue.front());
			int frontStackSize = mQueue.front().size();
			for (int i = 0; i < frontStackSize; i++)
			{
				sum += mQueue.front().top();
				mQueue.front().pop();
			}
			mQueue.pop();
		}
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		return sum;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount()
	{
		unsigned int count = 0u;
		int mQueueSize = mQueue.size();
		std::queue<std::stack<T>> tmpQueue;

		for (int i = 0; i < mQueueSize; i++)
		{
			count += mQueue.front().size();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
		}
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		return count;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		if (mQueue.back().size() == 0)
		{
			return mQueue.size() - 1;
		}
		return mQueue.size();
	}

}

