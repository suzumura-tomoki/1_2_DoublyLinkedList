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
	class Iterator {
	public:
		//�R���X�g���N�^
		Iterator();
		Iterator(DoublyLinkedList* l, int n);

		// @brief ���̗v�f�ɃC�e���[�^���ړ����܂�
		void operator--();
		// @brief �O�̗v�f�ɃC�e���[�^���ړ����܂�
		void operator++();
		// @brief ���������Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		Iterator operator+(int n);
		// @brief �擪�����Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		Iterator operator-(int n);
		// @brief �C�e���[�^�������v�f���擾���܂�
		Node& operator*();
		// @brief �C�e���[�^�������v�f���擾���܂�
		Node* operator->();//���̂��|�C���^��Ԃ��Ȃ��Ƃ����Ȃ�
		// @brief �C�e���[�^���r���܂�
		bool operator==(Iterator it);
		bool operator!=(Iterator it);

		// @brief �C�e���[�^�������v�f�ԍ����擾���܂�
		unsigned int GetNum();
		// @brief �C�e���[�^���Q�Ƃ��郊�X�g���擾���܂�
		DoublyLinkedList& GetList();

	private:
		unsigned int num = 0;
		DoublyLinkedList* pList = nullptr;
	};

	// @brief �o�������X�g�̃R���X�g�C�e���[�^
	// @brief *���Z�q�ŃC�e���[�^�������f�[�^�ɃA�N�Z�X�ł���
	class ConstIterator :public Iterator {
	public:
		ConstIterator(DoublyLinkedList* l, int n);
		// @brief �C�e���[�^�������R���X�g�v�f���擾���܂�
		const Node operator*();
		// @brief �R�s�[�R���X�g���N�^
		//ConstIterator(const ConstIterator& obj);

	};

	// @brief �R���X�g���N�^
	DoublyLinkedList();
	// @brief �f�X�g���N�^
	~DoublyLinkedList();

	// @brief �v�f�����擾���܂�
	unsigned int GetSize();

	// @brief �C�e���[�^�������ʒu�ɗv�f��ǉ����܂�
	// @param[in] �ǉ��ʒu�̃C�e���[�^
	bool AddNode(Iterator iterator);
	// @brief �C�e���[�^�������ʒu�ɗv�f��ǉ����܂�
	// @param[in] �ǉ��ʒu�̃C�e���[�^
	// @param[in] �ǉ�����m�[�h�̐�
	bool AddNode(Iterator iterator, int addNum);

	// @brief �C�e���[�^�������ʒu�̗v�f���폜���܂�
	// @param[in] �폜�ʒu�̃C�e���[�^
	bool DeleteNode(Iterator iterator);

	// @brief �擪�̃C�e���[�^���擾
	Iterator GetBegin();

	// @brief �擪�̃R���X�g�C�e���[�^���擾
	ConstIterator GetConstBegin();

	// @brief �����̃C�e���[�^���擾
	Iterator GetEnd();

	// @brief �����̃R���X�g�C�e���[�^���擾
	ConstIterator GetConstEnd();

	// @brief �m�[�h�ւ̃|�C���^���擾
	Node* GetNode(Iterator it);
	// @brief �m�[�h�ւ̃|�C���^���擾 �n�_�_�~�[�̎��v�f���O�Ƃ��Ďw��ԍ��̗v�f�̃|�C���^��Ԃ�
	Node* GetNode(unsigned int num);

private:
	// @brief �擪�������_�~�[�v�f�@�f�[�^�͊i�[����Ȃ�
	Node beginDummy;
	// @brief �����������_�~�[�v�f�@�f�[�^�͊i�[����Ȃ�
	Node endDummy;
	// @brief �擪�|�C���^
	//Node* pBegin = nullptr;
	// @brief �����|�C���^
	//Node* pEnd = nullptr;

	// @brief �v�f�̐�
	unsigned int size = 0;
};