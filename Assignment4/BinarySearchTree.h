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

		// ������ ��ġ�� �̵�
 		while (currNode != nullptr)
		{
			if (*data > *currNode->Data)
			{
				parentNode = currNode;
				currNode = currNode->Right;
			}
			else if (*data == *currNode->Data)
			{
				// currNode ���ʿ� �� ��� ����
				auto tmpNode = currNode->Left;
				currNode->Left = currNode;	// �̷��� �ص� ���� ī��Ʈ�� 1�� �پ���? 
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
				// no child (��Ʈ ���� ���̽� ��� �� �ص� �ɵ� psuedo node�� �����ϱ�)
				if (currNode->Right.use_count() == 0 && currNode->Left.use_count() == 0)
				{
					auto parent = currNode->Parent.lock();
					if (parent->Left == currNode)
					{
						parent->Left = nullptr;	// shared_ptr ����
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

					parent->Right = tmpNode;	// �̷��� �˾Ƽ� shared_ptr ����??
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

		// ���� �ڽ� �湮
		TraverseRecursive(node->Left, result);

		// ���� ��� �湮
		result.push_back(*node->Data);

		// ������ �ڽ� �湮 
		TraverseRecursive(node->Right, result);
		
	}
}