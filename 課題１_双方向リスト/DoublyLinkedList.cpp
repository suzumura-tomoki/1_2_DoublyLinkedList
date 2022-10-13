#include "DoublyLinkedList.h"
#include<assert.h>
DoublyLinkedList::DoublyLinkedList()
{
	dummy.pPrevious = nullptr;
	dummy.pNext = nullptr;
	dummy.resultData.name = "dummy";
	dummy.resultData.score = "dummy";

	pTop = &dummy;
	size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{

	DoublyLinkedList::Iterator it = GetBegin();

	while (size > 0)
	{
		Delete(it);
	}
}

unsigned int DoublyLinkedList::GetSize()const
{
	return size;
}

bool DoublyLinkedList::Insert(ConstIterator& iterator, const ResultData& data)
{
	if (this != iterator.pList)
	{
		return false;
	}

	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//新しい要素を生成
	Node* pNewNode = new Node;
	pNewNode->resultData = data;
	pNewNode->pNext = iterator.pNode;//追加する位置にあった要素を次の要素にする
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//追加位置の前の要素を前の要素にする

	//前後の要素が新しい要素を参照するようにする
	pNewNode->pNext->pPrevious = pNewNode;

	if (pNewNode->pPrevious != nullptr)
	{
		//前の要素がある場合
		pNewNode->pPrevious->pNext = pNewNode;
	}

	//先頭に追加した場合に先頭ポインタを更新
	if (iterator.pNode == pTop)
	{
		pTop = pNewNode;
	}

	iterator--;//追加した要素へ移動
	size++;

	return true;
}

bool DoublyLinkedList::Delete(ConstIterator& iterator)
{
	// イテレータが自分のリストのイテレータか判断する
	if (this != iterator.pList)
	{
		return false;
	}

	//不正なイテレータか判断する
	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//ダミーノードか判断する
	if (iterator.pNode == &iterator.pList->dummy)
	{
		return false;
	}

	//前の要素が削除対象の次の要素を指すように変更
	if (iterator.pNode->pPrevious != nullptr)
	{
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;
	}

	//次の要素が削除対象の前の要素を指すように変更
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator++;//次のノードへ移動

	//削除対象が先頭だったら先頭ポインタを更新
	if (pDeleteNode == pTop)
	{
		pTop = iterator.pNode;
	}

	delete pDeleteNode;

	size--;

	return true;
}

DoublyLinkedList::Iterator DoublyLinkedList::GetBegin()
{
	return Iterator(this, pTop);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::GetConstBegin()const
{
	return ConstIterator(this, pTop);
}

DoublyLinkedList::Iterator DoublyLinkedList::GetEnd()
{
	return Iterator(this, &dummy);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::GetConstEnd()const
{
	return ConstIterator(this, &dummy);
}

DoublyLinkedList::ConstIterator::ConstIterator()
{
	pNode = nullptr;
	pList = nullptr;
}

DoublyLinkedList::ConstIterator::ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode)
{
	pList = const_cast<DoublyLinkedList*>(_pList);
	pNode = const_cast<Node*>(_pNode);
}

DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& obj)
{
	this->pNode = obj.pNode;
	this->pList = obj.pList;
}

DoublyLinkedList::ConstIterator::~ConstIterator()
{
	//何もしない
}

DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++()
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	pNode = pNode->pNext;

	return *this;
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	ConstIterator cit = *this;
	operator++();
	return cit;
}

DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--()
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード
	pNode = pNode->pPrevious;
	return *this;
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード
	ConstIterator cit = *this;
	operator--();
	return cit;
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator+(int n)const
{
	assert(this->pList != nullptr);//リストの参照がない場合

	if (n >= 0) {
		ConstIterator cit = *this;

		//末尾に進む
		for (int i = 0; i < n; i++) {

			//末尾を越えないように停止する
			if (cit.pNode->pNext == nullptr)
			{
				return cit;
			}

			cit++;
		}

		return cit;

	}
	else {
		//絶対値を取得
		n = static_cast<int>(labs(n));

		//先頭に進めたイテレータを返す
		return (*this) - n;
	}
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator-(int n)const
{
	assert(this->pList != nullptr);//リストの参照がない場合


	if (n >= 0) {
		ConstIterator cit = *this;

		//先頭に進む
		for (int i = 0; i < n; i++) {

			//先頭を越えないように停止する
			if (cit.pNode->pPrevious == nullptr)
			{
				return cit;
			}

			cit--;
		}

		return cit;
	}
	else {
		//絶対値を取得
		n = static_cast<int>(labs(n));

		//末尾に進めたイテレータを返す
		return (*this) + n;
	}
}

bool DoublyLinkedList::ConstIterator::operator==(const ConstIterator& it)const
{
	return this->pNode == it.pNode;
}

bool DoublyLinkedList::ConstIterator::operator!=(const ConstIterator& it)const
{
	return !(*this == it);
}

const ResultData& DoublyLinkedList::ConstIterator::operator*()const
{
	assert(pList != nullptr);//pListがnullptrでないこと
	assert(pNode != &pList->dummy);//pNodeがダミーでないこと

	return pNode->resultData;
}

const ResultData* DoublyLinkedList::ConstIterator::operator->()const
{
	assert(pList != nullptr);//pListがnullptrでないこと
	assert(pNode != &pList->dummy);//pNodeがダミーでないこと

	return &pNode->resultData;
}

DoublyLinkedList::Iterator::Iterator()
{
	//何もしない
}

DoublyLinkedList::Iterator::Iterator(const DoublyLinkedList* _pList, const Node* _pNode) : ConstIterator(_pList, _pNode)
{
	//基底クラスConstIteratorのコンストラクタに引数を渡す
	//ここでは何もしない
}

DoublyLinkedList::Iterator::~Iterator()
{
	//何もしない
}

DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++()
{
	ConstIterator::operator++();

	return *this;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator++(int)
{
	Iterator it = *this;

	operator++();

	return it;
}

DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--()
{
	ConstIterator::operator--();

	return *this;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator--(int)
{

	Iterator it = *this;

	operator--();

	return it;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator+(int n)
{
	ConstIterator cit = ConstIterator::operator+(n);
	
	return Iterator(cit.pList, cit.pNode);
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator-(int n)
{
	ConstIterator cit = ConstIterator::operator-(n);

	return Iterator(cit.pList, cit.pNode);
}

ResultData& DoublyLinkedList::Iterator::operator*()
{
	return const_cast<ResultData&>(ConstIterator::operator*());
}

ResultData* DoublyLinkedList::Iterator::operator->()
{
	return const_cast<ResultData*>(ConstIterator::operator->());//ここではポインタの->は呼ばれていない
}
