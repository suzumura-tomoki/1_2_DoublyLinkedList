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

	//�V�����v�f�𐶐�
	Node* pNewNode = new Node;
	pNewNode->resultData = data;
	pNewNode->pNext = iterator.pNode;//�ǉ�����ʒu�ɂ������v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;

	if (pNewNode->pPrevious != nullptr)
	{
		//�O�̗v�f������ꍇ
		pNewNode->pPrevious->pNext = pNewNode;
	}

	//�擪�ɒǉ������ꍇ�ɐ擪�|�C���^���X�V
	if (iterator.pNode == pTop)
	{
		pTop = pNewNode;
	}

	iterator--;//�ǉ������v�f�ֈړ�
	size++;

	return true;
}

bool DoublyLinkedList::Delete(ConstIterator& iterator)
{
	// �C�e���[�^�������̃��X�g�̃C�e���[�^�����f����
	if (this != iterator.pList)
	{
		return false;
	}

	//�s���ȃC�e���[�^�����f����
	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//�_�~�[�m�[�h�����f����
	if (iterator.pNode == &iterator.pList->dummy)
	{
		return false;
	}

	//�O�̗v�f���폜�Ώۂ̎��̗v�f���w���悤�ɕύX
	if (iterator.pNode->pPrevious != nullptr)
	{
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;
	}

	//���̗v�f���폜�Ώۂ̑O�̗v�f���w���悤�ɕύX
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator.pNode = iterator.pNode->pNext;//���̃m�[�h�ֈړ�

	//�폜�Ώۂ��擪��������擪�|�C���^���X�V
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

//DoublyLinkedList::Node* DoublyLinkedList::GetNode()
//{
//	return pTop;
//}

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

	if (n >= 0) {
		ConstIterator cit = *this;

		//�����ɐi��
		for (int i = 0; i < n; i++) {

			//�������z���Ȃ��悤�ɒ�~����
			if (cit.pNode->pNext == nullptr)
			{
				return cit;
			}

			cit++;
		}

		return cit;

	}
	else {
		//��Βl���擾
		n = static_cast<int>(labs(n));

		//�擪�ɐi�߂��C�e���[�^��Ԃ�
		return (*this) - n;
	}
}

DoublyLinkedList::ConstIterator DoublyLinkedList::ConstIterator::operator-(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ


	if (n >= 0) {
		ConstIterator cit = *this;

		//�擪�ɐi��
		for (int i = 0; i < n; i++) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (cit.pNode->pPrevious == nullptr)
			{
				return cit;
			}

			cit--;
		}

		return cit;
	}
	else {
		//��Βl���擾
		n = static_cast<int>(labs(n));

		//�����ɐi�߂��C�e���[�^��Ԃ�
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
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return pNode->resultData;
}

const ResultData* DoublyLinkedList::ConstIterator::operator->()const
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return &pNode->resultData;
}

DoublyLinkedList::Iterator::Iterator()
{
	//�������Ȃ�
}

DoublyLinkedList::Iterator::Iterator(const DoublyLinkedList* _pList, const Node* _pNode) : ConstIterator(_pList, _pNode)
{
	//���N���XConstIterator�̃R���X�g���N�^�Ɉ�����n��
	//�����ł͉������Ȃ�
}

DoublyLinkedList::Iterator::~Iterator()
{
	//�������Ȃ�
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
	return const_cast<ResultData*>(ConstIterator::operator->());//�����ł̓|�C���^��->�͌Ă΂�Ă��Ȃ�
}
