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
	//TODO �C�e���[�^���g��
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
	if (iterator.GetNum() > size)
		return false;

	Node* pNewNode = new Node;
	pNewNode->pNext = &(*iterator);//�ǉ��ʒu�̗v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;
	pNewNode->pPrevious->pNext = pNewNode;

	return true;
}

bool DoublyLinkedList::AddNode(Iterator iterator, int addNum)
{
	if (this != &iterator.GetList())
		return false;

	if (iterator.GetNum() > size)
		return false;

	for (int i = 0; i < addNum; i++) {
		Node* pNewNode = new Node;
		pNewNode->pNext = &(*iterator);//�ǉ��ʒu�̗v�f�����̗v�f�ɂ���
		pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

		//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
		pNewNode->pNext->pPrevious = pNewNode;
		pNewNode->pPrevious->pNext = pNewNode;

		iterator++;
	}
	return true;
}

bool DoublyLinkedList::DeleteNode(Iterator iterator)
{
	if (iterator.GetNum() >= size)
		return false;

	//�C�e���[�^�̎����v�f�ւ̃|�C���^���擾
	Node* pTargetNode = GetNode(iterator.GetNum());

	//�O�̗v�f���폜�Ώۂ̎��̗v�f���w���悤�ɕύX
	pTargetNode->pPrevious->pNext = pTargetNode->pNext;
	//���̗v�f���폜�Ώۂ̑O�̗v�f���w���悤�ɕύX
	pTargetNode->pNext->pPrevious = pTargetNode->pPrevious;

	delete pTargetNode;

	return true;
}

DoublyLinkedList::Iterator DoublyLinkedList::GetBegin()
{
	return Iterator(this, 0);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::GetConstBegin()
{
	return ConstIterator(this, 0);
}

DoublyLinkedList::Iterator DoublyLinkedList::GetEnd()
{
	return Iterator(this, size);
}

DoublyLinkedList::ConstIterator DoublyLinkedList::GetConstEnd()
{
	return ConstIterator(this, size);
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

DoublyLinkedList::Node* DoublyLinkedList::GetNode(unsigned int num)
{
	if (num >= size)
		return nullptr;

	Node* pNode = this->beginDummy.pNext;

	for (int i = 0; i < num; i++) {
		pNode = pNode->pNext;
	}

	return pNode;
}

DoublyLinkedList::Iterator::Iterator()
{
	//�������Ȃ��@�����ƃG���[���o��̂ŏ����Ă���
}

DoublyLinkedList::Iterator::Iterator(DoublyLinkedList* p, int n)
{
	pList = p;
	num = n;
}

void DoublyLinkedList::Iterator::operator--()
{
	num--;
}

void DoublyLinkedList::Iterator::operator++()
{
	num++;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator+(int n)
{
	return Iterator(pList, num + n);
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator-(int n)
{
	return Iterator(pList, num - n);
}

DoublyLinkedList::Node& DoublyLinkedList::Iterator::operator*()
{
	Node* pNode = pList->GetNode(this->GetNum());
	return *pNode;
}

DoublyLinkedList::Node* DoublyLinkedList::Iterator::operator->()
{
	Node* pNode = pList->GetNode(this->GetNum());
	return pNode;
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

DoublyLinkedList& DoublyLinkedList::Iterator::GetList()
{
	return *pList;
}


DoublyLinkedList::ConstIterator::ConstIterator(DoublyLinkedList* l, int n) : Iterator(l, n)
{
	//���N���XIterator�̃R���X�g���N�^���Ăяo��
	//�����ł͉������Ȃ�
}

const DoublyLinkedList::Node DoublyLinkedList::ConstIterator::operator*()
{
	//TODO ConstIterator::operator*()
	//�擾�����l��ύX����̂ŎQ�Ƃ�Ԃ�
	return Node();
}

//DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& obj)
//{
//	//TODO ConstIterator::�R�s�[�R���X�g���N�^
//}
