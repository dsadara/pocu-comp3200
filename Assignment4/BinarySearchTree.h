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
				// currNode 오른쪽에 새 노드 삽입
				tmpNode = currNode.Right.get();
				currNode.Right = make_shared<TreeNode<T>>(currNode, data);
				currNode.Right.Right = tmpNode;		// 이렇게 하면 되나 모르겠다.. 

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