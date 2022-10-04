#include<fstream>
#include"DoublyLinkedList.h"

int main() {

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("ファイルを開けませんでした");
		getchar();
		return 1;
	}

	DoublyLinkedList list;
	DoublyLinkedList::Iterator iterator = list.GetBegin();
	//スコア読み込み
	while (ifsScoreFile.eof() == false)
	{
		list.AddNode(iterator);
		//ファイルの読み取り
		std::getline(ifsScoreFile, (*iterator).resultData.score, ' ');
		std::getline(ifsScoreFile, (*iterator).resultData.name, '\n');//'\n'は省略可

		iterator++;
	}

	ifsScoreFile.close();

	//読み込んだ値を出力
	for (iterator = list.GetBegin(); iterator != list.GetEnd(); iterator++) {
		printf((*iterator).resultData.score.c_str());
		printf((*iterator).resultData.name.c_str());
		printf("\n");
	}

	printf("\nENTERキーを押すと終了します");
	getchar();
	return 0;
}