#include<fstream>
#include"DoublyLinkedList.h"

void Uninit(DoublyLinkedList::Element* pTop);

int main() {
	DoublyLinkedList::Element* pTop = new DoublyLinkedList::Element;
	DoublyLinkedList::Element* pCurrentElement = pTop;
	const size_t ELEMENT_SIZE = sizeof(DoublyLinkedList::Element);

	pTop->pPrevious = nullptr;
	pTop->pNext = nullptr;

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("�t�@�C�����J���܂���ł���");
		getchar();
		return 1;
	}

	//�X�R�A�ǂݍ���
	while (ifsScoreFile.eof() == false)
	{
		//�P�s�ǂݎ��
		std::getline(ifsScoreFile, pCurrentElement->score);

		//�V�����v�f�̊m��
		pCurrentElement->pNext = new DoublyLinkedList::Element;
		if (pCurrentElement->pNext == nullptr) {
			printf("�������m�ۂɎ��s");
			Uninit(pTop);
			return 1;
		}
		pCurrentElement->pNext->pPrevious = pCurrentElement;
		pCurrentElement->pNext->pNext = nullptr;

		pCurrentElement = pCurrentElement->pNext;
	}

	ifsScoreFile.close();

	//�ǂݍ��񂾒l���o��
	pCurrentElement = pTop;

	while (pCurrentElement != nullptr) {
		printf(pCurrentElement->score.c_str());
		printf("\n");

		pCurrentElement = pCurrentElement->pNext;
	}

	printf("\nENTER�L�[�������ƏI�����܂�");
	getchar();
	Uninit(pTop);
	return 0;
}

void Uninit(DoublyLinkedList::Element* pTop) {
	DoublyLinkedList::Element* pCurrent = pTop;
	DoublyLinkedList::Element* pWork;

	while (pCurrent != nullptr)
	{
		pWork = pCurrent;
		pCurrent = pCurrent->pNext;

		delete pWork;
	}
}