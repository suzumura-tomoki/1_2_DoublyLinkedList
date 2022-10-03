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
		printf("ファイルを開けませんでした");
		getchar();
		return 1;
	}

	//スコア読み込み
	while (ifsScoreFile.eof() == false)
	{
		//１行読み取り
		std::getline(ifsScoreFile, pCurrentElement->score);

		//新しい要素の確保
		pCurrentElement->pNext = new DoublyLinkedList::Element;
		if (pCurrentElement->pNext == nullptr) {
			printf("メモリ確保に失敗");
			Uninit(pTop);
			return 1;
		}
		pCurrentElement->pNext->pPrevious = pCurrentElement;
		pCurrentElement->pNext->pNext = nullptr;

		pCurrentElement = pCurrentElement->pNext;
	}

	ifsScoreFile.close();

	//読み込んだ値を出力
	pCurrentElement = pTop;

	while (pCurrentElement != nullptr) {
		printf(pCurrentElement->score.c_str());
		printf("\n");

		pCurrentElement = pCurrentElement->pNext;
	}

	printf("\nENTERキーを押すと終了します");
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