#pragma once
#include<string>

namespace DoublyLinkedList//bi-directional list�Ƃ�����
{
	struct Element {
		DoublyLinkedList::Element* pPrevious;
		DoublyLinkedList::Element* pNext;
		std::string score;
		//std::string name;
	};
};