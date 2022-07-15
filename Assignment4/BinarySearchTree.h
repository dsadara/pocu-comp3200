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
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;
		bool BinarySearchTree<T>::SearchRecursive(const T& data, TreeNode<T>& node);

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
	private:
		TreeNode<T> mBST;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		TreeNode<T>* currNode = mBst;
		TreeNode<T>* tmpNode == nullptr;
 		while (currNode.Left == nullptr && currNode.Right == nullptr)
		{
			if (data > *currNode.Data)
			{
				currNode = currNode.Left.get();
			}
			else if (data == * currNode.Data)
			{
				// currNode �����ʿ� �� ��� ����
				tmpNode = currNode.Right.get();
				currNode.Right = make_shared<TreeNode<T>>(currNode, data);
				currNode.Right.Right = tmpNode;		// �̷��� �ϸ� �ǳ� �𸣰ڴ�.. 

			}
			else // data > *currNode.Data
			{
				currNode = currNode.Right.get();
			}

		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		std::shared_ptr<TreeNode<T>> n;
		return n;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		while ()

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
		// ���� ��� �湮
		if (*node.Data == data)
		{ 
			return true;
		}

		// ������ �ڽ� �湮
		SearchRecursive(data, node.Right);

		// ���� �ڽ� �湮 
		SearchRecursive(data, node.Right);
	}
}