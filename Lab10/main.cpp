#include "Node.h"
#include "DoublyLinkedList.h"
#include <cassert>
#include <iostream>

using namespace lab10;

void SpecTestCase();
void WikiTestCase();

int main()
{
	SpecTestCase();
	WikiTestCase();

	std::unique_ptr<int> number1 = std::make_unique<int>(1);
	std::shared_ptr<Node<int>> node1 = std::make_shared<Node<int>>(std::move(number1));

	assert(*node1->Data == 1);

	std::unique_ptr<int> number2 = std::make_unique<int>(2);

	std::shared_ptr<Node<int>> node2 = std::make_shared<Node<int>>(std::move(number2), node1);
	node1->Next = node2;

	assert(*node2->Data == 2);
	assert(*node2->Previous.lock()->Data == 1);

	// Insert()

	DoublyLinkedList<int> list;
	list.Insert(std::make_unique<int>(1)); // 1
	list.Insert(std::make_unique<int>(2)); // 1 -> 2
	list.Insert(std::make_unique<int>(3)); // 1 -> 2 -> 3

	list.Insert(std::make_unique<int>(10), 1); // 1 -> 10 -> 2 -> 3

	// operator[]()

	DoublyLinkedList<int> list2;
	list2.Insert(std::make_unique<int>(1)); // 1
	list2.Insert(std::make_unique<int>(2)); // 1 -> 2
	list2.Insert(std::make_unique<int>(3)); // 1 -> 2 -> 3
	list2.Insert(std::make_unique<int>(4), 3);

	assert(*list2[1]->Data == 2); // 2를 저장하고 있는 노드를 가리키는 공유포인터 std::shared_ptr<Node<int>>를 반환
	assert(list2[5] == nullptr); // nullptr를 반환

	// search()

	DoublyLinkedList<int> list3;
	list3.Insert(std::make_unique<int>(1)); // 1
	list3.Insert(std::make_unique<int>(2)); // 1 -> 2
	list3.Insert(std::make_unique<int>(3)); // 1 -> 2 -> 3

	assert(list3.Search(2)); // true를 반환
	assert(!list3.Search(5)); // false를 반환

	// delete()

	DoublyLinkedList<int> list4;
	list4.Insert(std::make_unique<int>(1)); // 1
	list4.Insert(std::make_unique<int>(2)); // 1 -> 2
	list4.Insert(std::make_unique<int>(3)); // 1 -> 2 -> 3

	assert(list4.Delete(2)); // true를 반환, 1 -> 3
	assert(*list4[1]->Data == 3);
	assert(*list4[0]->Data == 1);

	assert(!list4.Delete(2)); // false를 반환, 1 -> 3
	assert(*list4[1]->Data == 3);

	assert(list4.Delete(1));
	assert(*list4[0]->Data == 3);

	assert(list4.Delete(3));
	assert(list4[0] == nullptr);

}

void SpecTestCase()
{
	DoublyLinkedList<int> list;

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 7);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 6);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	node = list[2];
	assert(*node->Data == 10);

}

void WikiTestCase()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	DoublyLinkedList<int> list;

	assert(list[0] == nullptr);
	assert(list[3] == nullptr);
	bool bEmptyDeleted = list.Delete(6);
	assert(!bEmptyDeleted);
	bool bEmptySearched = list.Search(7);
	assert(!bEmptySearched);

	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	list.PrintList();

	bool bSearched = list.Search(4);
	assert(bSearched);

	bSearched = list.Search(1);
	assert(bSearched);

	bSearched = list.Search(7);
	assert(bSearched);

	bSearched = list.Search(10);
	assert(!bSearched);

	unsigned int size = list.GetLength();
	assert(size == 7);

	bool bDeleted = list.Delete(3);
	assert(bDeleted);

	list.PrintList();

	bDeleted = list.Delete(3);
	assert(!bDeleted);

	size = list.GetLength();
	assert(size == 6);

	std::shared_ptr<Node<int>> node = list[2];
	assert(*node->Data == 4);

	list.Insert(std::make_unique<int>(10), 2);

	list.PrintList();

	node = list[2];
	assert(*node->Data == 10);

	bDeleted = list.Delete(1);
	assert(bDeleted);
	assert(*list[0]->Data == 2);

	list.PrintList();

	bDeleted = list.Delete(7);
	assert(bDeleted);

	list.PrintList();

	list.Insert(std::make_unique<int>(11), 0);
	list.PrintList();

	node = list[0];
	assert(*node->Data == 11);
	assert(list.GetLength() == 6);

	list.Insert(std::make_unique<int>(12), 6);
	list.PrintList();
	assert(list.GetLength() == 7);
	node = list[6];
	assert(*node->Data == 12);

	list.Insert(std::make_unique<int>(13), 9);
	list.PrintList();
	assert(list.GetLength() == 8);
	node = list[7];
	assert(*node->Data == 13);

	bDeleted = list.Delete(2);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(4);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(5);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(6);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(10);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(11);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(12);
	list.PrintList();
	assert(bDeleted);
	bDeleted = list.Delete(13);
	list.PrintList();
	assert(bDeleted);

	assert(list[0] == nullptr);


}
