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
		ResultData data;

		//ファイルの読み取り
		char readCharacter;
		while (true)
		{
			ifsScoreFile.get(readCharacter);

			if (ifsScoreFile.eof())
				break;

			data.score += readCharacter;

			if (readCharacter == ' ')
				break;
			if (readCharacter == '　')
				break;
		}

		while (true)
		{
			ifsScoreFile.get(readCharacter);

			if (ifsScoreFile.eof())
				break;

			data.name += readCharacter;

			if (readCharacter == '\n')
				break;
		}
		//読み取り終わり

		//読み取ったデータの挿入
		list.Insert(iterator, data);

		iterator++;
	}

	ifsScoreFile.close();

	//読み込んだ値を出力
	const DoublyLinkedList::Iterator end = list.GetEnd();
	for (iterator = list.GetBegin(); iterator != end; iterator++) {
		printf(iterator->score.c_str());
		printf(iterator->name.c_str());
		printf("\n");
	}

	printf("\nENTERキーを押すと終了します");
	getchar();
	return 0;
}