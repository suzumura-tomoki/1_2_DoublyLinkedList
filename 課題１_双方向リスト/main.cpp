#include<fstream>
#include"DoublyLinkedList.h"

void Uninit(DoublyLinkedList::Element* pTop);

int main() {
	DoublyLinkedList::Element top;
	DoublyLinkedList::Element* pCurrentElement = &top;
	const size_t ELEMENT_SIZE = sizeof(DoublyLinkedList::Element);

	top.pPrevious = nullptr;
	top.pNext = nullptr;

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("�t�@�C�����J���܂���ł���");
		getchar();
		return 1;
	}

	//�X�R�A�ǂݍ���
	while (true)
	{
		//�P�s�ǂݎ��
		std::getline(ifsScoreFile, pCurrentElement->score);

		if (ifsScoreFile.eof())
			break;

		//�V�����v�f�̊m��
		pCurrentElement->pNext = new DoublyLinkedList::Element;//static_cast<DoublyLinkedList::Element*>(malloc(ELEMENT_SIZE));
		if (pCurrentElement->pNext == nullptr) {
			printf("�������m�ۂɎ��s");
			Uninit(&top);
			return 1;
		}
		pCurrentElement->pNext->pPrevious = pCurrentElement;
		pCurrentElement->pNext->pNext = nullptr;

		pCurrentElement = pCurrentElement->pNext;
	}

	ifsScoreFile.close();

	//�ǂݍ��񂾒l���o��
	pCurrentElement = &top;

	while (pCurrentElement != nullptr) {
		printf(pCurrentElement->score.c_str());
		printf("\n");

		pCurrentElement = pCurrentElement->pNext;
	}

	printf("\nENTER�L�[�������ƏI�����܂�");
	getchar();
	Uninit(&top);
	return 0;
}

void Uninit(DoublyLinkedList::Element* pTop) {
	DoublyLinkedList::Element* pCurrent=pTop->pNext;
	DoublyLinkedList::Element* pWork;

	while (pCurrent != nullptr)
	{
		pWork = pCurrent;
		pCurrent = pCurrent->pNext;

		delete pWork;
	}
}