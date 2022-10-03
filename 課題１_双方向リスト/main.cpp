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
		printf("ファイルを開けませんでした");
		getchar();
		return 1;
	}

	//スコア読み込み
	while (true)
	{
		//１行読み取り
		std::getline(ifsScoreFile, pCurrentElement->score);

		if (ifsScoreFile.eof())
			break;

		//新しい要素の確保
		pCurrentElement->pNext = new DoublyLinkedList::Element;//static_cast<DoublyLinkedList::Element*>(malloc(ELEMENT_SIZE));
		if (pCurrentElement->pNext == nullptr) {
			printf("メモリ確保に失敗");
			Uninit(&top);
			return 1;
		}
		pCurrentElement->pNext->pPrevious = pCurrentElement;
		pCurrentElement->pNext->pNext = nullptr;

		pCurrentElement = pCurrentElement->pNext;
	}

	ifsScoreFile.close();

	//読み込んだ値を出力
	pCurrentElement = &top;

	while (pCurrentElement != nullptr) {
		printf(pCurrentElement->score.c_str());
		printf("\n");

		pCurrentElement = pCurrentElement->pNext;
	}

	printf("\nENTERキーを押すと終了します");
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