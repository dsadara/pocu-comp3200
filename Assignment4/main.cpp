#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <limits>

using namespace assignment4;

void SpecTestCase();

int main()
{

	SpecTestCase();

	// 2.1 TreeNode 클래스 구현하기

	TreeNode<int> n(std::make_unique<int>(2));

	std::shared_ptr<TreeNode<int>> parent = std::make_shared<TreeNode<int>>(std::make_unique<int>(5));
	TreeNode<int> n2(parent, std::make_unique<int>(2));

	// 2.2 BinarySearchTree 클래스의 Insert() 메서드 구현하기

	BinarySearchTree<int> tree;
	tree.Insert(std::make_unique<int>(10));

	// 2.3 BinarySearchTree 클래스의 Search() 메서드 구현하기

	bool bSearched = tree.Search(10); // true
	assert(bSearched);
	bSearched = tree.Search(15); // false
	assert(!bSearched);

	// 2.4 BinarySearchTree 클래스의 Delete() 메서드 구현하기

	bool bDeleted = tree.Delete(10); // true;
	bDeleted = tree.Delete(15); // false;

	// 2.5 BinarySearchTree 클래스의 TraverseInOrder() 메서드 구현하기

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock()); // [ 4, 5, 10, 12, 15, 17, 19, 20 ]

	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);

	// 2.6 BinarySearchTree 클래스의 GetRootNode() 메서드 구현하기

	std::shared_ptr<TreeNode<int>> result = tree.GetRootNode().lock();
	
	assert(*result->Data == 10); // 10
	BinarySearchTree<int> tree2;
	result = tree2.GetRootNode().lock();
	assert(*result->Data == std::numeric_limits<int>::max());

	return 0;
}

void SpecTestCase()
{
	BinarySearchTree<int> tree;

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	/*std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 8);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);

	bool bSearched = tree.Search(15);
	assert(bSearched);

	bool bDeleted = tree.Delete(6);
	assert(!bDeleted);

	bDeleted = tree.Delete(100);
	assert(!bDeleted);

	bDeleted = tree.Delete(15);
	assert(bDeleted);

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 7);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 17);
	assert(v[5] == 19);
	assert(v[6] == 20);

	bSearched = tree.Search(15);
	assert(!bSearched);*/
}