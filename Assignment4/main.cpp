#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <limits>
#include <iostream>
#include <random>

using namespace assignment4;

void SpecTestCase();
void Test_Insert_GetRoot();
void Test_Search();
void Test_Delete();
void Test_Traverse();
void Test_Delete_0hoo();
void Test_Delete_TwoChild();
void Print_Tree(BinarySearchTree<int>& tree);
void Test_Randomly();
void Test_ErrorCase();


int main()
{

	/*SpecTestCase();
	Test_Insert_GetRoot();
	Test_Search();
	Test_Delete();
	Test_Traverse();*/
	//Test_Delete_TwoChild();
	Test_Randomly();
	//Test_ErrorCase();

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
	//assert(*result->Data == std::numeric_limits<int>::max());
	assert(result.use_count() == 0);

	tree2.Insert(std::make_unique<int>(10));
	tree2.Insert(std::make_unique<int>(15));
	tree2.Insert(std::make_unique<int>(5));
	tree2.Insert(std::make_unique<int>(10));
	//tree2.Delete(10);

	std::vector<int> result2 = BinarySearchTree<int>::TraverseInOrder(tree2.GetRootNode().lock());
	for (int num : result2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	assert(tree2.Search(10));

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

	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

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
	assert(!bSearched);
}

void Test_Insert_GetRoot()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	tree.Insert(std::make_unique<int>(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));

	std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();
	assert(*test0->Data.get() == 10);
	assert(test0->Parent.lock().get() == nullptr);
	std::shared_ptr<TreeNode<int>> test1 = test0->Left;
	assert(*test1->Data.get() == 5);
	assert(*test1->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test2 = test1->Left;
	assert(*test2->Data.get() == 4);
	assert(*test2->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test3 = test1->Right;
	assert(*test3->Data.get() == 7);
	assert(*test3->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test4 = test0->Right;
	assert(*test4->Data.get() == 15);
	assert(*test4->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test5 = test4->Left;
	assert(*test5->Data.get() == 12);
	assert(*test5->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test6 = test4->Right;
	assert(*test6->Data.get() == 19);
	assert(*test6->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test7 = test6->Left;
	assert(*test7->Data.get() == 17);
	assert(*test7->Parent.lock()->Data.get() == 19);
	std::shared_ptr<TreeNode<int>> test8 = test6->Right;
	assert(*test8->Data.get() == 20);
	assert(*test8->Parent.lock()->Data.get() == 19);

	return;
}

void Test_Search()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	assert(!tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[0]));
	assert(tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	assert(tree.Search(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	assert(tree.Search(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	assert(tree.Search(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	assert(tree.Search(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	assert(tree.Search(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	assert(tree.Search(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	assert(tree.Search(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));
	assert(tree.Search(arr[8]));
	assert(!tree.Search(arr[9]));

	return;
}

void Test_Delete()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	//	End
	assert(!tree.Delete(9)); 	// 존재하지 않는 노드 삭제
	assert(tree.Delete(20));	// Right 노드 삭제
	assert(!tree.Search(20));	// 삭제 확인
	assert(tree.Delete(12));	// Left 노드 삭제
	assert(!tree.Search(12));	// 삭제 확인
	assert(!tree.Delete(11));	// 존재하지 않는 노드 삭제

	//	Middle
	assert(tree.Delete(19));	// Left만 있는 노드 삭제
	assert(!tree.Search(19));	// 삭제 확인
	assert(tree.Search(17));

	assert(tree.Delete(4));
	assert(tree.Delete(7));
	assert(tree.Delete(17));	// Left, Right 모두 없는 헤드 삭제
	assert(!tree.Search(17));	// 삭제 확인
	assert(!tree.Delete(17));	// 비어있는 상태에서 삭제

	assert(tree.Delete(15));	// Right만 있는 노드 삭제
	assert(!tree.Search(15));	// 삭제 확인
	assert(tree.Delete(5)); 	// Left, Right 모두 있는 노드 삭제
	assert(!tree.Search(5));
	assert(!tree.Delete(5));	// 존재하지 않는 노드 삭제

  //	Head
	assert(tree.Delete(10)); 	// Left, Right 모두 있는 헤드 삭제
	assert(!tree.Search(10));	// 삭제 확인

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	tree.Delete(arr[0]);
	tree.Delete(arr[1]);
	tree.Delete(arr[2]);
	tree.Delete(arr[3]);
	tree.Delete(arr[4]);
	tree.Delete(arr[5]);
	tree.Delete(arr[6]);
	tree.Delete(arr[7]);
	tree.Delete(arr[8]);

	return;
}

void Test_Traverse()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };
	int arr_chk[9] = { 4, 5, 7, 10, 12, 15, 17, 19, 20 };

	// 빈 트리
	std::vector<int> v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	tree.GetRootNode();
	assert(v1.size() == 0);
	assert(v1.empty());

	tree.Insert(std::make_unique<int>(arr[0]));
	// 헤드만 있는 트리
	std::vector<int> v2 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v2.size() == 1);
	assert(v2[0] == arr[0]);

	// empty 포인터
	std::vector<int> v3 = tree.TraverseInOrder(tree.GetRootNode().lock()->Left);
	assert(v3.size() == 0);
	assert(v3.empty());

	// 트리 입력
	for (size_t i = 1; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	// 헤드 노드 입력
	std::vector<int> v4 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v4.size() == 9);
	assert(v4[0] == arr_chk[0]);
	assert(v4[1] == arr_chk[1]);
	assert(v4[2] == arr_chk[2]);
	assert(v4[3] == arr_chk[3]);
	assert(v4[4] == arr_chk[4]);
	assert(v4[5] == arr_chk[5]);
	assert(v4[6] == arr_chk[6]);
	assert(v4[7] == arr_chk[7]);
	assert(v4[8] == arr_chk[8]);

	// 중간 노드 입력
	std::vector<int> v5 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Right);
	assert(v5.size() == 3);
	assert(v5[0] == arr_chk[6]);
	assert(v5[1] == arr_chk[7]);
	assert(v5[2] == arr_chk[8]);

	// 말단 노드 입력
	std::vector<int> v6 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Left);
	assert(v6.size() == 1);
	assert(v6[0] == arr_chk[4]);

	// 노드 삭제
	for (size_t i = 0; i < 8; i++)
	{
		tree.Delete(arr[i]);
	}

	// 7만 남기고 모두 삭제된 트리
	std::vector<int> v7 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v7.size() == 1);
	assert(v7[0] == arr[8]);

	// 노드가 모두 삭제된 트리
	tree.Delete(arr[8]);
	std::vector<int> v8 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v8.size() == 0);
	assert(v8.empty());

	return;
}

void Test_Delete_0hoo()
{
	bool bDelete = false;
	bool bSearch = false;
	BinarySearchTree<int> tree;
	std::vector<int> traverseResult;

	bDelete = tree.Delete(15);
	bSearch = tree.Search(15);
	traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(!bDelete);
	assert(!bSearch);
	assert(traverseResult.empty());

	tree.Insert(std::make_unique<int>(15));
	traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
	bDelete = tree.Delete(15);
	assert(bDelete);
	assert(traverseResult.size() == 1);
	assert(traverseResult[0] == 15);
	assert(tree.GetRootNode().lock());
}

void Test_Delete_TwoChild()
{
	int arr[3] = { 10, 5, 15 };
	int arr2[4] = { 10, 5, 4, 7 };
	int arr3[4] = { 10, 15, 12, 19 };
	int arr4[6] = { 5, 10, 15, 19, 17, 20 };
	int arr5[7] = { 10, 10, 15, 4, 7, 12, 19 };

	BinarySearchTree<int> tree1;
	BinarySearchTree<int> tree2;
	BinarySearchTree<int> tree3;
	BinarySearchTree<int> tree4;
	BinarySearchTree<int> tree5;

	std::cout << "Delete two child node1" << std::endl;

	for (int num : arr)
	{
		tree1.Insert(std::make_unique<int>(num));
	}
	Print_Tree(tree1);
	tree1.Delete(10);
	Print_Tree(tree1);



	std::cout << "Delete two child node2" << std::endl;

	for (int num : arr2)
	{
		tree2.Insert(std::make_unique<int>(num));
	}
	Print_Tree(tree2);
	tree2.Delete(5);
	Print_Tree(tree2);

	std::cout << "Delete two child node3" << std::endl;

	for (int num : arr3)
	{
		tree3.Insert(std::make_unique<int>(num));
	}
	Print_Tree(tree3);
	tree3.Delete(15);
	Print_Tree(tree3);

	std::cout << "Delete two child node4" << std::endl;

	for (int num : arr4)
	{
		tree4.Insert(std::make_unique<int>(num));
	}
	Print_Tree(tree4);
	tree4.Delete(19);
	Print_Tree(tree4);

	std::cout << "Delete two child node5" << std::endl;

	for (int num : arr5)
	{
		tree5.Insert(std::make_unique<int>(num));
	}
	Print_Tree(tree5);
	tree5.Delete(10);
	Print_Tree(tree5);
}

void Print_Tree(BinarySearchTree<int>& tree)
{
	std::vector<int> result2 = BinarySearchTree<int>::TraverseInOrder(tree.GetRootNode().lock());
	for (int num : result2)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

void Test_Randomly()
{
	std::vector<int> a;
	std::random_device	rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);

	for (int i = 0; i < 1000; i++)
	{
		int iterateNum = dis(gen) % 10;
		for (i = 0; i < iterateNum; i++)
		{
			a.push_back(dis(gen));
		}

		BinarySearchTree<int> tree;

		// insert
		for (int num : a)
		{
			tree.Insert(std::make_unique<int>(num));
		}
		Print_Tree(tree);

		// delete
		for (int num : a)
		{
			tree.Delete(num);
		}
		Print_Tree(tree);

		a.clear();

		// error case 25 26 34 57 58 76 77 94
		// 16 36 43 50 53 77 77 87 99
		// 8 19 28 61 62 76 81 94 96
		// 8 45 49 58 82 83
		// 1 6 21 27 51 52 67 78 80
	}
}

void Test_ErrorCase()
{
	int a[] = {25, 26, 34, 57, 58, 76, 77, 94};

	BinarySearchTree<int> tree;

	for (int num : a)
	{
		tree.Insert(std::make_unique<int>(num));
	}

	Print_Tree(tree);

	for (int num : a)
	{
		tree.Delete(num);
	}

	int b[] = { 16, 36, 43, 50, 53, 77, 77, 87, 99 };

	BinarySearchTree<int> tree2;

	for (int num : b)
	{
		tree2.Insert(std::make_unique<int>(num));
	}

	Print_Tree(tree2);

	for (int num : b)
	{
		tree2.Delete(num);
	}

	
}