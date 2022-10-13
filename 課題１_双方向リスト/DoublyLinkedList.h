#pragma once
#include<string>

/**
 * @brief ���уf�[�^���i�[����\����
 */
struct ResultData
{
public:
	std::string score;
	std::string name;
};

/**
 * @brief �o�������X�g�̃N���X\n
 *		  �ʖ�bi-directional list
 */
class DoublyLinkedList
{
public:

	/**
	 * @brief �o�������X�g�̃m�[�h\n
	 *		 �\����ResultData���i�[���Ă���
	 */
	struct Node {
		DoublyLinkedList::Node* pPrevious = nullptr;
		DoublyLinkedList::Node* pNext = nullptr;
		ResultData resultData;
	};

	/**
	 * @brief �o�������X�g�̃R���X�g�C�e���[�^\n
	 *		  �����Z�q�܂���->���Z�q�Ńf�[�^�ɃA�N�Z�X�ł��܂�
	 */
	class ConstIterator {
		friend DoublyLinkedList;
	public:
		/**
		 * @brief �R���X�g���N�^
		 */
		ConstIterator();
		/**
		 * @brief �R���X�g���N�^
		 * @param[in] const DoublyLinkedList* �Q�Ƃ��郊�X�g�m�[�h�ւ̃|�C���^
		 * @param[in] const Node* �R���X�g�C�e���[�^�������m�[�h�ւ̃|�C���^
		 */
		ConstIterator(const DoublyLinkedList* _pList, const Node* _pNode);

		/**
		 * @brief �R�s�[�R���X�g���N�^
		 * @param[in] const ConstIterator& �R�s�[���̃I�u�W�F�N�g
		 */
		ConstIterator(const ConstIterator& obj);

		/**
		 * @brief �f�X�g���N�^
		 */
		virtual ~ConstIterator();

		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator& operator++();
		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��R���X�g�C�e���[�^
		 */
		ConstIterator operator++(int);

		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator& operator--();
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��R���X�g�C�e���[�^
		 */
		ConstIterator operator--(int);

		/**
		 * @brief ���������Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		 * @param[in] int �ړ���
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator operator+(int n);
		/**
		 * @brief �擪�����Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		 * @param[in] int �ړ���
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator operator-(int n);

		/**
		 * @brief �C�e���[�^�̎����m�[�h���������̂���r���܂�
		 * @param[in] ConstIterator& ��r�Ώ�
		 * @return bool �����m�[�h���w���Ă����true�A����ȊO�Ȃ�false
		 */
		bool operator==(const ConstIterator& it)const;

		/**
		 * @brief �C�e���[�^�̎����m�[�h���قȂ���̂���r���܂�
		 * @param[in] ConstIterator& ��r�Ώ�
		 * @return bool �قȂ�m�[�h���w���Ă����true�A����ȊO�Ȃ�false
		 */
		bool operator!=(const ConstIterator& it)const;

		/**
		 * @brief �R���X�g�C�e���[�^�������v�f�̃R���X�g�Q�Ƃ��擾���܂�
		 * @return const ResultData& �C�e���[�^�������v�f�̃R���X�g�Q��
		 */
		const ResultData& operator*()const;
		/**
		 * @brief �R���X�g�C�e���[�^�������R���X�g�v�f���擾���܂�\n
		 *		  �ÖٓI�ɖ߂�l�̎���->���Ă΂�܂�
		 * @return const ResultData* �R���X�g�C�e���[�^�������R���X�g�v�f�ւ̃|�C���^
		 */
		const ResultData* operator->()const;


	protected:
		/**
		 * @brief ���̃C�e���[�^�������m�[�h�ւ̃|�C���^
		 */
		Node* pNode = nullptr;
		/**
		 * @brief ���̃C�e���[�^���Q�Ƃ��Ă��郊�X�g�ւ̃|�C���^
		 */
		DoublyLinkedList* pList = nullptr;
	private:

	};


	/**
	* @brief �o�������X�g�̃C�e���[�^\n
	*		 �p���F�R���X�g�C�e���[�^
	*		 �����Z�q�܂���->���Z�q�Ńf�[�^�ɃA�N�Z�X�ł��܂�
	*/
	class Iterator :public ConstIterator {
	public:
		/**
		 * @brief �R���X�g���N�^
		 */
		Iterator();
		/**
		 * @brief �R���X�g���N�^
		 * @param[in] �Q�Ƃ��郊�X�g
		 * @param[in] �����m�[�h
		 */
		Iterator(const DoublyLinkedList* _pList, const Node* _pNode);

		/**
		 * @brief �R�s�[�R���X�g���N�^ default
		 * @param[in] �R�s�[���̃I�u�W�F�N�g
		 */
		Iterator(const Iterator& obj) = default;

		/**
		 * @brief �f�X�g���N�^
		 */
		virtual ~Iterator();

		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ������C�e���[�^
		 */
		Iterator& operator++();
		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��C�e���[�^
		 */
		Iterator operator++(int);
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ������C�e���[�^
		 */
		Iterator& operator--();
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��C�e���[�^
		 */
		Iterator operator--(int);

		/**
		 * @brief ���������Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		 * @param[in] int �ړ���
		 * @return �ړ������C�e���[�^
		 */
		Iterator operator+(int n);
		/**
		 * @brief �擪�����Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		 * @param[in] int �ړ���
		 * @return �ړ������C�e���[�^
		 */
		Iterator operator-(int n);

		/**
		 * @brief �C�e���[�^�������v�f�̎Q�Ƃ��擾���܂�
		 * @return ResultData& �C�e���[�^�������v�f�̎Q��
		 */
		ResultData& operator*();
		/**
		 * @brief �C�e���[�^�������v�f���擾���܂�\n
		 *		  �ÖٓI�ɖ߂�l�̎���->���Ă΂�܂�
		 * @return ResultData* �C�e���[�^�������v�f�ւ̃|�C���^
		 */
		ResultData* operator->();


	private:

	};

	/**
	 * @brief �R���X�g���N�^
	 */
	DoublyLinkedList();

	/**
	 * @brief �R�s�[�R���X�g���N�^ default
	 */
	DoublyLinkedList(const DoublyLinkedList& obj) = default;

	/**
	 * @brief �f�X�g���N�^\n 
	 * �m�ۂ����m�[�h��S�ĉ������
	 */
	virtual ~DoublyLinkedList();

	/**
	 * @brief �v�f�����擾���܂�
	 * @return unsigned int �v�f��
	 */
	unsigned int GetSize()const;

	/**
	 * @brief �C�e���[�^�������v�f�̑O�ɗv�f��}�����܂�\n
	 *		  �ǉ������v�f�ɃC�e���[�^���ړ������܂�
	 * @param[in,out] �}���ʒu�̃C�e���[�^�A�}�������v�f�Ɉړ����܂� 
	 * @param[in]	  �i�[����f�[�^ 
	 * @return bool true:�}���ɐ���\n
	 *				false:�}���Ɏ��s
	 */
	bool Insert(ConstIterator& iterator, const ResultData& data);

	/**
	 * @brief �C�e���[�^�������v�f���폜���܂�\n
	 *		  �폜�����v�f�̎��̗v�f�ɃC�e���[�^���ړ������܂�
	 * @param[in,out] �폜����v�f�̃C�e���[�^
	 * @return bool true:�폜�ɐ���\n
	 *				false:�폜�Ɏ��s
	 */
	bool Delete(ConstIterator& iterator);

	/**
	 * @brief �擪�̃C�e���[�^���擾
	 * @return �擪�̃C�e���[�^
	 */
	Iterator GetBegin();

	/**
	 * @brief �擪�̃R���X�g�C�e���[�^���擾
	 * @return �擪�̃R���X�g�C�e���[�^
	 */
	ConstIterator GetConstBegin()const;

	/**
	 * @brief �����̃C�e���[�^���擾
	 * @return �����̃C�e���[�^
	 */
	Iterator GetEnd();

	/**
	 * @brief �����̃R���X�g�C�e���[�^���擾
	 * @return �����̃R���X�g�C�e���[�^
	 */
	ConstIterator GetConstEnd()const;

private:

	/**
	 * @brief �����������_�~�[�v�f�@�f�[�^�͊i�[����Ȃ�
	 */
	Node dummy;

	/**
	 * @brief �擪�v�f�ւ̃|�C���^\n
	 *		  �z���Ȃ�
	 */
	Node* pTop;

	/**
	 * @brief �v�f��
	 */
	unsigned int size;
};