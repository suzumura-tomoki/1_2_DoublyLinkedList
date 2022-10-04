#include<fstream>
#include"DoublyLinkedList.h"

int main() {

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("�t�@�C�����J���܂���ł���");
		getchar();
		return 1;
	}

	DoublyLinkedList list;
	DoublyLinkedList::Iterator iterator = list.GetBegin();
	//�X�R�A�ǂݍ���
	while (ifsScoreFile.eof() == false)
	{
		list.AddNode(iterator);
		//�t�@�C���̓ǂݎ��
		std::getline(ifsScoreFile, (*iterator).resultData.score, ' ');
		std::getline(ifsScoreFile, (*iterator).resultData.name, '\n');//'\n'�͏ȗ���

		iterator++;
	}

	ifsScoreFile.close();

	//�ǂݍ��񂾒l���o��
	for (iterator = list.GetBegin(); iterator != list.GetEnd(); iterator++) {
		printf((*iterator).resultData.score.c_str());
		printf((*iterator).resultData.name.c_str());
		printf("\n");
	}

	printf("\nENTER�L�[�������ƏI�����܂�");
	getchar();
	return 0;
}