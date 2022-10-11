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
		ResultData data;

		//�t�@�C���̓ǂݎ��
		char readCharacter;
		while (true)
		{
			ifsScoreFile.get(readCharacter);

			if (ifsScoreFile.eof())
				break;

			data.score += readCharacter;

			if (readCharacter == ' ')
				break;
			if (readCharacter == '�@')
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
		//�ǂݎ��I���

		//�ǂݎ�����f�[�^�̑}��
		list.Insert(iterator, data);

		iterator++;
	}

	ifsScoreFile.close();

	//�ǂݍ��񂾒l���o��
	const DoublyLinkedList::Iterator end = list.GetEnd();
	for (iterator = list.GetBegin(); iterator != end; iterator++) {
		printf(iterator->score.c_str());
		printf(iterator->name.c_str());
		printf("\n");
	}

	printf("\nENTER�L�[�������ƏI�����܂�");
	getchar();
	return 0;
}