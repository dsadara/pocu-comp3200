#pragma once

#include <memory>
#include <limits>

namespace assignment4
{
	template<typename T>
	class TreeNode final
	{
	public:
		TreeNode(std::unique_ptr<T> data);
		TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data);
		TreeNode();
		bool IsEmptyTree();

		std::unique_ptr<T> Data;
		std::shared_ptr<TreeNode<T>> Left;
		std::shared_ptr<TreeNode<T>> Right;
		std::weak_ptr<TreeNode<T>> Parent;
	};

	template<typename T>
	TreeNode<T>::TreeNode(std::unique_ptr<T> data)
		: Data(std::move(data))
	{
	}

	template<typename T>
	TreeNode<T>::TreeNode()
		: Data(std::move(std::make_unique<T>(std::numeric_limits<T>::max())))
	{
	
	}
	template<typename T>
	TreeNode<T>::TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data)
		: Data(std::move(data))
		, Parent(parent)
	{
	}

	template<typename T>
	bool TreeNode<T>::IsEmptyTree()
	{
		return Left == nullptr ? true : false;
	}
}