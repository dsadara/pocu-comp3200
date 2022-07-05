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
		std::stack<T> mTmpStack;
		unsigned int mMaxStackSize;
	};

	template<typename T>
	QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize)
	{
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
			std::stack<T> frontStack = other.mQueue.front();
			other.mQueue.pop();
			tmpQueue.push(frontStack);
			mQueue.push(frontStack);
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			other.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack도 복사
		if (other.mTmpStack.size() != 0)
		{
			mTmpStack = other.mTmpStack;	// 얕은복사? 깊은복사?
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
		int mTmpStackSize = static_cast<int>(mTmpStack.size());
		for (int i = 0; i < mTmpStackSize; i++)
		{
			mTmpStack.pop();
		}

		mMaxStackSize = rhs.mMaxStackSize;
		int queueSize = static_cast<int>(rhs.mQueue.size());
		std::queue<std::stack<T>> tmpQueue;
		// 큐 순회하며 스택 복사
		for (int i = 0; i < queueSize; i++)
		{
			std::stack<T> frontStack = rhs.mQueue.front();
			rhs.mQueue.pop();
			tmpQueue.push(frontStack);
			mQueue.push(frontStack);
		}

		// 큐 다시 주워담기
		for (int i = 0; i < queueSize; i++)
		{
			rhs.mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack도 복사
		if (rhs.mTmpStack.size() != 0)
		{
			mTmpStack = rhs.mTmpStack;
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

		mTmpStack.push(number);
		if (mTmpStack.size() == mMaxStackSize)
		{
			mQueue.push(mTmpStack);
			for (unsigned int i = 0; i < mMaxStackSize; i++)
			{
				mTmpStack.pop();
			}
		}
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		if (mQueue.size() == 0)
		{
			return mTmpStack.top();
		}
		return mQueue.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T result;
		if (mQueue.size() == 0)
		{
			result = mTmpStack.top();
			mTmpStack.pop();
			return result;
		}
		std::stack<T>& frontStack = mQueue.front();
		result = frontStack.top();
		frontStack.pop();
		if (frontStack.size() == 0)
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

		std::stack<T> tmp;
		for (int i = 0; i < mQueueSize; i++)
		{
			// 스택 pop 하며 max값 찾기
			// 스택 도로 집어넣기
			tmp = mQueue.front();
			tmpQueue.push(mQueue.front());
			mQueue.pop();

			// 스택 안 max 찾기
			int tmpSize = tmp.size();
			for (int i = 0; i < tmpSize; i++)
			{
				if (max < tmp.top())
				{
					max = tmp.top();
				}
				tmp.pop();
			}
		}
		// 스택 주워 담기 
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack의 max 비교
		int mTmpStackSize = mTmpStack.size();
		T* mTmpStackArray = new T[mTmpStackSize];
		for (int i = 0; i < mTmpStackSize; i++)
		{
			mTmpStackArray[i] = mTmpStack.top();
			if (max < mTmpStack.top())
			{
				max = mTmpStack.top();
			}
			mTmpStack.pop();
		}
		for (int i = mTmpStackSize - 1; i >= 0; i--)
		{
			mTmpStack.push(mTmpStackArray[i]);
		}

		return max;
	}

	template<typename T>
	T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();
		int mQueueSize = mQueue.size();
		std::queue<std::stack<T>> tmpQueue;

		std::stack<T> tmp;
		for (int i = 0; i < mQueueSize; i++)
		{
			// 스택 pop 하며 min값 찾기
			// 스택 도로 집어넣기
			tmp = mQueue.front();
			tmpQueue.push(mQueue.front());
			mQueue.pop();

			// 스택 안 min 찾기
			int tmpSize = tmp.size();
			for (int i = 0; i < tmpSize; i++)
			{
				if (min > tmp.top())
				{
					min = tmp.top();
				}
				tmp.pop();
			}
		}
		// 스택 주워 담기 
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		// mTmpStack의 min 비교
		int mTmpStackSize = mTmpStack.size();
		T* mTmpStackArray = new T[mTmpStackSize];
		for (int i = 0; i < mTmpStackSize; i++)
		{
			mTmpStackArray[i] = mTmpStack.top();
			if (min > mTmpStack.top())
			{
				min = mTmpStack.top();
			}
			mTmpStack.pop();
		}
		for (int i = mTmpStackSize - 1; i >= 0; i--)
		{
			mTmpStack.push(mTmpStackArray[i]);
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
			std::stack<T> frontStack = mQueue.front();
			tmpQueue.push(mQueue.front());
			mQueue.pop();
			int frontStackSize = frontStack.size();
			for (int i = 0; i < frontStackSize; i++)
			{
				sum += frontStack.top();
				frontStack.pop();
			}
		}
		for (int i = 0; i < mQueueSize; i++)
		{
			mQueue.push(tmpQueue.front());
			tmpQueue.pop();
		}

		int mTmpStackSize = mTmpStack.size();
		T* mTmpStackArray = new T[mTmpStackSize];
		for (int i = 0; i < mTmpStackSize; i++)
		{
			sum += mTmpStack.top();
			mTmpStackArray[i] = mTmpStack.top();
			mTmpStack.pop();
		}
		for (int i = mTmpStackSize - 1; i >= 0; --i)
		{
			mTmpStack.push(mTmpStackArray[i]);
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

		count += mTmpStack.size();

		return count;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount()
	{
		if (mTmpStack.size() == 0)
			return mQueue.size();

		return mQueue.size() + 1;
	}

}

