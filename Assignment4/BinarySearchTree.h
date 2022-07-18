#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree();
		~BinarySearchTree();
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;
		bool SearchRecursive(const T& data, TreeNode<T>& node);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
	private:
		std::shared_ptr<TreeNode<T>> mBST;
	};
	
	template<typename T>
	BinarySearchTree<T>::BinarySearchTree()
		: mBST(new TreeNode<T>())
	{
	}

	template<typename T>
	BinarySearchTree<T>::~BinarySearchTree()
	{
	}

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		auto currNode = mBST;
		auto parentNode = mBST;
		if (!currNode->IsEmptyTree())
		{
			currNode = mBST->Left;
		}

		// 삽입할 위치로 이동
 		while (currNode != nullptr)
		{
			if (*data > *currNode->Data)
			{
				parentNode = currNode;
				currNode = currNode->Right;
			}
			else if (*data == *currNode->Data)
			{
				// currNode 왼쪽에 새 노드 삽입
				auto tmpNode = currNode->Left;
				currNode->Left = currNode;	// 이렇게 해도 참조 카운트가 1이 줄어들까? 
				currNode->Left->Left = tmpNode;
				//bInserted = true;
				return;
			}
			else // data < *currNode.Data
			{
				parentNode = currNode;
				currNode = currNode->Left;
			}
		}

		if (*data > *parentNode->Data)
		{
			parentNode->Right = std::make_shared<TreeNode<T>>(parentNode, std::move(data));
		}
		else  // data <= *currNode.Data
		{
			parentNode->Left = std::make_shared<TreeNode<T>>(parentNode, std::move(data));
		}

	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		if (mBST->IsEmptyTree())
		{
			return nullptr;
		}
		return mBST->Left;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		auto currNode = mBST;

		while (currNode != nullptr)
		{
			if (data > *currNode->Data)
			{
				currNode = currNode->Right;
			}
			else if (data == *currNode->Data)
			{
				return true;
			}
			else  // *data > currNode->Data
			{
				currNode = currNode->Left;
			}
		}
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		return v;
	}

	template<typename T>
	bool BinarySearchTree<T>::SearchRecursive(const T& data, TreeNode<T>& node)
	{
		// 현재 노드 방문
		if (*node.Data == data)
		{ 
			return true;
		}

		// 오른쪽 자식 방문
		SearchRecursive(data, node.Right);

		// 왼쪽 자식 방문 
		SearchRecursive(data, node.Right);
	}
}