#include "DoublyLinkedList.h"
#include<assert.h>
DoublyLinkedList::DoublyLinkedList()
{
	dummy.pPrevious = nullptr;
	dummy.pNext = nullptr;
	dummy.resultData.name = "dummy";
	dummy.resultData.score = "dummy";
	//Node* pTop = &dummy;
}

DoublyLinkedList::~DoublyLinkedList()
{
	DoublyLinkedList::Node* pCurrent = pTop;
	DoublyLinkedList::Node* pDeleteNode;

	while (true)
	{
		if (pCurrent == &dummy)
			break;

		pDeleteNode = pCurrent;
		pCurrent = pCurrent->pNext;

		delete pDeleteNode;

	}
}

unsigned int DoublyLinkedList::GetSize()const
{
	return size;
}

bool DoublyLinkedList::Insert(ConstIterator& iterator, const ResultData& data)
{
	if (this != iterator.pList)
		return false;

	if (iterator.pNode == nullptr)
		return false;

	//�V�����v�f�𐶐�
	Node* pNewNode = new Node;
	pNewNode->resultData = data;
	pNewNode->pNext = iterator.pNode;//�ǉ�����ʒu�ɂ������v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;
	if (pNewNode->pPrevious != nullptr)
		pNewNode->pPrevious->pNext = pNewNode;

	//�擪�ɒǉ������ꍇ�ɐ擪�|�C���^���X�V
	if (iterator.pNode == pTop)
		pTop = pNewNode;

	iterator--;//�ǉ������v�f�ֈړ�
	size++;

	return true;
}

bool DoublyLinkedList::Insert(Iterator& iterator, const ResultData& data)
{
	if (this != iterator.pList)
		return false;

	if (iterator.pNode == nullptr)
		return false;

	//�V�����v�f�𐶐�
	Node* pNewNode = new Node;
	pNewNode->resultData = data;
	pNewNode->pNext = iterator.pNode;//�ǉ�����ʒu�ɂ������v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;
	if (pNewNode->pPrevious != nullptr)
		pNewNode->pPrevious->pNext = pNewNode;

	//�擪�ɒǉ������ꍇ�ɐ擪�|�C���^���X�V
	if (iterator.pNode == pTop)
		pTop = pNewNode;

	iterator--;//�ǉ������v�f�ֈړ�
	size++;

	return true;
}

bool DoublyLinkedList::Delete(ConstIterator& iterator)
{
	// �C�e���[�^�������̃��X�g�̃C�e���[�^�����f����
	if (this != iterator.pList)
		return false;

	//�s���ȃC�e���[�^�����f����
	if (iterator.pNode == nullptr)
		return false;

	//�_�~�[�m�[�h�����f����
	if (iterator.pNode == &iterator.pList->dummy)
		return false;

	//�O�̗v�f���폜�Ώۂ̎��̗v�f���w���悤�ɕύX
	if (iterator.pNode->pPrevious != nullptr)
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;

	//���̗v�f���폜�Ώۂ̑O�̗v�f���w���悤�ɕύX
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator.pNode = iterator.pNode->pNext;//���̃m�[�h�ֈړ�

	//�폜�Ώۂ��擪��������擪�|�C���^���X�V
	if (pDeleteNode == pTop)
		pTop = iterator.pNode;

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

//DoublyLinkedList::Node* DoublyLinkedList::GetNode()
//{
//	return pTop;
//}

DoublyLinkedList::ConstIterator::ConstIterator()
{
	//�������Ȃ�
}

DoublyLinkedList::ConstIterator::ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode)
{
	pList = const_cast<DoublyLinkedList*>(_pList);
	pNode = const_cast<Node*>(_pNode);
}

DoublyLinkedList::ConstIterator::~ConstIterator()
{
	//�������Ȃ�
}

DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator++()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	pNode = pNode->pNext;

	return *this;
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator++(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	ConstIterator cit = *this;
	pNode = pNode->pNext;
	return cit;
}

DoublyLinkedList::ConstIterator& DoublyLinkedList::ConstIterator::operator--()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h
	pNode = pNode->pPrevious;
	return *this;
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator--(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h
	ConstIterator cit = *this;
	pNode = pNode->pPrevious;
	return cit;
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator+(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = pNode;

	if (n >= 0) {

		//�����ɐi��
		for (int i = 0; i < n; i++) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return ConstIterator(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator(pList, pMoved);
	}
	else {

		//�擪�ɐi��
		for (int i = 0; i > n; i--) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return ConstIterator(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator(pList, pMoved);
	}
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator-(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = pNode;

	if (n >= 0) {

		//�擪�ɐi��
		for (int i = 0; i < n; i++) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return ConstIterator(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator(pList, pMoved);
	}
	else {

		//�����ɐi��
		for (int i = 0; i > n; i--) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return ConstIterator(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator(pList, pMoved);
	}
}

const ResultData& DoublyLinkedList::ConstIterator::operator*()const
{
	return pNode->resultData;
}

const ResultData* DoublyLinkedList::ConstIterator::operator->()const
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return &pNode->resultData;
}

DoublyLinkedList::ConstIterator::ConstIterator(const ConstIterator& obj)
{
	this->pNode = obj.pNode;
	this->pList = obj.pList;
}

bool DoublyLinkedList::ConstIterator::operator==(const ConstIterator& it)const
{
	return this->pNode == it.pNode;
}

bool DoublyLinkedList::ConstIterator::operator!=(const ConstIterator& it)const
{

	return this->pNode != it.pNode;
}

bool DoublyLinkedList::ConstIterator::operator==(const Iterator& it) const
{
	return this->pNode == it.pNode;
}

bool DoublyLinkedList::ConstIterator::operator!=(const Iterator& it) const
{
	return this->pNode != it.pNode;
}

DoublyLinkedList::Iterator::Iterator()
{
	//�������Ȃ�
}

DoublyLinkedList::Iterator::Iterator(DoublyLinkedList* _pList, Node* _pNode) : ConstIterator(_pList, _pNode)
{
	//���N���XIterator�̃R���X�g���N�^���Ăяo��
	//�����ł͉������Ȃ�
}

DoublyLinkedList::Iterator::~Iterator()
{
	//�������Ȃ�
}

DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator++()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	pNode = pNode->pNext;
	return *this;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator++(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	Iterator it = *this;
	pNode = pNode->pNext;
	return it;
}

DoublyLinkedList::Iterator& DoublyLinkedList::Iterator::operator--()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h

	pNode = pNode->pPrevious;
	return *this;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator--(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h

	Iterator it = *this;
	pNode = pNode->pPrevious;
	return it;
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator+(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = pNode;

	if (n >= 0) {

		//�����ɐi��
		for (int i = 0; i < n; i++) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return Iterator(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator(pList, pMoved);
	}
	else {

		//�擪�ɐi��
		for (int i = 0; i > n; i--) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return Iterator(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator(pList, pMoved);
	}
}

DoublyLinkedList::Iterator DoublyLinkedList::Iterator::operator-(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = pNode;

	if (n >= 0) {

		//�擪�ɐi��
		for (int i = 0; i < n; i++) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return Iterator(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator(pList, pMoved);
	}
	else {

		//�����ɐi��
		for (int i = 0; i > n; i--) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return Iterator(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator(pList, pMoved);
	}

}

bool DoublyLinkedList::Iterator::operator==(Iterator& it) const
{
	return this->pNode == it.pNode;
}

bool DoublyLinkedList::Iterator::operator!=(Iterator& it) const
{
	return this->pNode != it.pNode;
}

bool DoublyLinkedList::Iterator::operator==(const ConstIterator& it) const
{
	return this->pNode == it.pNode;
}

bool DoublyLinkedList::Iterator::operator!=(const ConstIterator& it) const
{
	return this->pNode != it.pNode;
}

ResultData& DoublyLinkedList::Iterator::operator*()
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return pNode->resultData;
}

ResultData* DoublyLinkedList::Iterator::operator->()
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return &pNode->resultData;
}
