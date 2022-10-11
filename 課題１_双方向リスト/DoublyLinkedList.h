#pragma once
#include<string>

// @brief ���уf�[�^���i�[����\����
struct ResultData
{
public:
	std::string score;
	std::string name;
};

// @brief �o�������X�g�̃N���X
// @brief �ʖ�bi-directional list
class DoublyLinkedList
{
public:
	// @brief �o�������X�g�̃m�[�h
	// @brief �\����ResultData���i�[���Ă���
	struct Node {
		DoublyLinkedList::Node* pPrevious = nullptr;
		DoublyLinkedList::Node* pNext = nullptr;
		ResultData resultData;
	};

	// @brief �o�������X�g�̃C�e���[�^
	// @brief *���Z�q�ŃC�e���[�^�������f�[�^�ɃA�N�Z�X�ł��܂�
	class ConstIterator {
		friend DoublyLinkedList;
	public:
		//�R���X�g���N�^
		ConstIterator();
		ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode);

		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		ConstIterator operator++();
		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		ConstIterator operator++(int);
		// @brief �O�̗v�f�Ɉړ����܂�
		//        �O�̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		ConstIterator operator--();
		// @brief �O�̗v�f���܂�
		//        �O�̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		ConstIterator operator--(int);

		// @brief ���������Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		ConstIterator operator+(int n);
		// @brief �擪�����Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		ConstIterator operator-(int n);

		// @brief �C�e���[�^�������R���X�g�v�f�̎Q�Ƃ��擾���܂�
		const ResultData& operator*();
		// @brief �C�e���[�^�������R���X�g�v�f�̎Q�Ƃ��擾���܂�
		const ResultData* operator->();//���̂��|�C���^��Ԃ��Ȃ��Ƃ����Ȃ�
		// @brief �R�s�[�R���X�g���N�^
		ConstIterator(const ConstIterator& obj);
		
		// @brief �C�e���[�^���r���܂�
		bool operator==(ConstIterator it);
		bool operator!=(ConstIterator it);

		// @brief �C�e���[�^���Q�Ƃ��郊�X�g�̎Q�Ƃ��擾���܂�
		const DoublyLinkedList& GetList();

		//bool IsDummy();

	protected:
		Node* pNode = nullptr;
		DoublyLinkedList* pList = nullptr;
	private:
		
	};

	// @brief �o�������X�g�̃R���X�g�C�e���[�^
	// @brief *���Z�q�ŃC�e���[�^�������f�[�^�ɃA�N�Z�X�ł���
	class Iterator :public ConstIterator {
	public:
		Iterator();
		Iterator(DoublyLinkedList* _pList, Node* _pNode);
		
		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		Iterator operator++();
		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		Iterator operator++(int);
		// @brief �O�̗v�f�Ɉړ����܂�
		//        �O�̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		Iterator operator--();
		// @brief �O�̗v�f���܂�
		//        �O�̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		Iterator operator--(int);
		// @brief ���������Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		Iterator operator+(int n);
		// @brief �擪�����Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		Iterator operator-(int n);

		// @brief �C�e���[�^�������v�f���擾���܂�
		ResultData& operator*();
		// @brief �C�e���[�^�������R���X�g�v�f���擾���܂�
		ResultData* operator->();//���̂��|�C���^��Ԃ��Ȃ��Ƃ����Ȃ�

	private:
		
	};

	// @brief �R���X�g���N�^
	DoublyLinkedList();
	// @brief �f�X�g���N�^
	~DoublyLinkedList();

	// @brief �v�f�����擾���܂�
	unsigned int GetSize()const;

	// @brief �C�e���[�^�������ʒu�ɗv�f��ǉ����܂�
	// @param[in,out] �ǉ��ʒu�̃C�e���[�^
	bool AddNode(ConstIterator& iterator);
	// @brief �C�e���[�^�������ʒu�ɗv�f��ǉ����܂�
	// @param[in,out] �ǉ��ʒu�̃C�e���[�^
	bool AddNode(Iterator& iterator);

	// @brief �C�e���[�^�������ʒu�̗v�f���폜���܂�
	// @param[in,out] �폜�ʒu�̃C�e���[�^
	bool DeleteNode(ConstIterator& iterator);

	// @brief �擪�̃C�e���[�^���擾
	Iterator GetBegin();

	// @brief �擪�̃R���X�g�C�e���[�^���擾
	ConstIterator GetConstBegin()const;

	// @brief �����̃C�e���[�^���擾
	Iterator GetEnd();

	// @brief �����̃R���X�g�C�e���[�^���擾
	ConstIterator GetConstEnd()const;

	// @brief �擪�v�f�ւ̃|�C���^���擾
	//Node* GetNode();

private:
	
	// @brief �����������_�~�[�v�f�@�f�[�^�͊i�[����Ȃ�
	Node dummy;
	// @brief �擪�v�f�ւ̃|�C���^
	Node* pTop = &dummy;

	// @brief �v�f�̐�
	unsigned int size = 0;
};