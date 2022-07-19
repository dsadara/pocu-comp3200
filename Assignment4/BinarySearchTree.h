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

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void TraverseRecursive(const std::shared_ptr<TreeNode<T>> node, std::vector<T>& result);
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
			return mBST;
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
		auto currNode = mBST;
		while (currNode != nullptr)
		{
			if (*currNode->Data > data)
			{
				currNode = currNode->Left;
			}
			else if (*currNode->Data < data)
			{
				currNode = currNode->Right;
			}
			else  // *currNode.Data == data
			{
				// no child (루트 삭제 케이스 고려 안 해도 될듯 psuedo node가 있으니까)
				if (currNode->Right.use_count() == 0 && currNode->Left.use_count() == 0)
				{
					auto parent = currNode->Parent.lock();
					if (parent->Left == currNode)
					{
						parent->Left = nullptr;	// shared_ptr 해제
					}
					else
					{
						parent->Right = nullptr;
					}
					return true;
				}
				else if (currNode->Right.use_count() == 0)
				{
					// 1 Left child
					auto parent = currNode->Parent.lock();
					auto tmpNode = currNode->Left;

					parent->Right = tmpNode;	// 이러면 알아서 shared_ptr 해제??
					tmpNode->Parent = parent;
					return true;
				}
				else if (currNode->Left.use_count() == 0)
				{
					// 1 Right child
					auto parent = currNode->Parent.lock();
					auto tmpNode = currNode->Right;

					parent->Left = tmpNode;
					tmpNode->Parent = parent;
					return true;
				}
				// 2 child 
				
				// get inorder successor
				auto minValueNode = currNode->Right;
				while (minValueNode != nullptr && minValueNode->Left != nullptr)	// minValueNode == nullptr || minValueNode->Left == nullptr
				{
					minValueNode = minValueNode->Left;
				}

				// copy successor's data
				currNode->Data = std::move(minValueNode->Data);

				// delete successor 
				auto successorParent = minValueNode->Parent.lock();
				successorParent->Left = nullptr;

				return true;
			}
		}

		return false;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> result;

		TraverseRecursive(startNode, result);

		return result;
	}

	template<typename T>
	void BinarySearchTree<T>::TraverseRecursive(const std::shared_ptr<TreeNode<T>> node, std::vector<T>& result)
	{
		if (node == nullptr)
		{
			return;
		}

		// 왼쪽 자식 방문
		TraverseRecursive(node->Left, result);

		// 현재 노드 방문
		result.push_back(*node->Data);

		// 오른쪽 자식 방문 
		TraverseRecursive(node->Right, result);
		
	}
}