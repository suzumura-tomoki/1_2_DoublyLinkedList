#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	beginDummy.pPrevious = nullptr;
	beginDummy.pNext = &endDummy;
	endDummy.pPrevious = &beginDummy;
	endDummy.pNext = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
	//TODO イテレータを使う
	DoublyLinkedList::Node* pCurrent = beginDummy.pNext;
	DoublyLinkedList::Node* pWork;

	while (pCurrent != nullptr)
	{
		pWork = pCurrent;
		pCurrent = pCurrent->pNext;

		delete pWork;
	}
}

unsigned int DoublyLinkedList::GetSize()
{
	return size;
}

bool DoublyLinkedList::AddNode(Iterator iterator)
{
	//TODO DoublyLinkedList::AddNode(Iterator iterator)
}

bool DoublyLinkedList::AddNode(Iterator iterator, int addNum)
{
	//TODO DoublyLinkedList::AddNode(Iterator iterator, int addNum)
}

void DoublyLinkedList::DeleteNode(Iterator iterator)
{
	//TODO DoublyLinkedList::DeleteNode(Iterator iterator)
}

DoublyLinkedList::Iterator DoublyLinkedList::GetBegin()
{
	return Iterator(this, 0);
}

const DoublyLinkedList::Iterator DoublyLinkedList::GetConstBegin()
{
	return const Iterator(this, 0);
}

DoublyLinkedList::Iterator DoublyLinkedList::GetEnd()
{
	return Iterator(this, size);
}

const DoublyLinkedList::Iterator DoublyLinkedList::GetConstEnd()
{
	return const Iterator(this, size);
}

DoublyLinkedList::Node* DoublyLinkedList::GetNode(Iterator it)
{
	unsigned int num = it.GetNum();

	Node* pNode = this->beginDummy.pNext;

	for (int i = 0; i < num; i++) {
		pNode = pNode->pNext;
	}

	return pNode;
}

DoublyLinkedList::Iterator::Iterator()
{
	num = 0;
}

DoublyLinkedList::Iterator::Iterator(DoublyLinkedList* p, int n)
{
	pList = p;
	num = n;
}

void DoublyLinkedList::Iterator::operator--()
{
	//TODO Iterator::operator--()
}

void DoublyLinkedList::Iterator::operator++()
{
	//TODO Iterator::operator++()
}

DoublyLinkedList::Node& DoublyLinkedList::Iterator::operator*()
{
	Node* pNode = pList->GetNode(*this);
	return *pNode;
}

bool DoublyLinkedList::Iterator::operator==(Iterator it)
{
	//TODO Iterator::operator==()
	return false;
}

bool DoublyLinkedList::Iterator::operator!=(Iterator it)
{
	//TODO Iterator::operator!=()
	return false;
}

unsigned int DoublyLinkedList::Iterator::GetNum()
{
	return num;
}

const DoublyLinkedList::Node DoublyLinkedList::ConstIterator::operator*()
{
	//TODO ConstIterator::operator*()
	//取得した値を変更するので参照を返す
	return Node();
}

DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& obj)
{
	//TODO ConstIterator::コピーコンストラクタ
}
