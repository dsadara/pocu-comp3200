#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> root;
		int length;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: length(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		// insert Root
		if (root == nullptr)
		{
			root = std::make_shared<Node<T>>(std::move(data));
			length++;
			return;
		}

		std::shared_ptr<Node<T>> currNode = root;

		while (currNode->Next != nullptr)	// go to last node;
		{
			currNode = currNode->Next;
		}

		currNode->Next = std::make_shared<Node<T>>(std::move(data), currNode);
		length++;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (length - 1 < static_cast<int>(index))
		{
			Insert(std::move(data));
		}
		else if (index == 0)// if insert at 0 index
		{
			root->Next = root;
			root = std::make_shared<Node<T>>(std::move(data));
			length++;
		}

		auto currNode = root;

		for (int i = 0; i < static_cast<int>(index); i++)
		{
			currNode = currNode->Next;
		}

		auto prev = currNode->Previous.lock();
		auto newNode = std::make_shared<Node<T>>(std::move(data), prev);

		prev->Next = newNode;
		currNode->Previous = newNode;
		newNode->Next = currNode;
		length++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		// 아무것도 없으면 
		if (length == 0)
		{
			return false;
		}
		// 루트 노드만 존재할 때
		if (length == 1)
		{
			root = nullptr;
			return true;
		}
		// 루트 노드를 삭제하는 경우
		if (*root->Data == data)
		{
			auto nextNode = root->Next;
			nextNode->Previous.reset();
			/*root->Next = nullptr;
			root->Data.release();*/
			root = nextNode;
			length--;
			return true;
		}

		auto currNode = root;

		while (currNode != nullptr)
		{
			if (*currNode->Data == data)
			{
				// 마지막 노드를 삭제하는 경우
				if (currNode->Next == nullptr)
				{
					auto prevNode = currNode->Previous.lock();
					prevNode->Next = nullptr;
					currNode->Previous.reset();
					length--;
					return true;
				}
				// 중간 노드를 삭제하는 경우
				auto nextNode = currNode->Next;
				auto prevNode = currNode->Previous.lock();
				prevNode->Next = nextNode;
				nextNode->Previous = prevNode;
				// 이렇게 하면 currNode의 strong ref가 0 이되어 사라질까?
				length--;
				return true;
			}
			currNode = currNode->Next;
		}

		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		auto currNode = root;

		while (currNode != nullptr)
		{
			if (*currNode->Data == data)
			{
				return true;
			}
			currNode = currNode->Next;
		}
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (length - 1 < static_cast<int>(index))
		{
			return nullptr;
		}

		auto currNode = root;

		for (int i = 0; i < static_cast<int>(index); i++)
		{
			currNode = currNode->Next;
		}

		return currNode;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return length;
	}
}
