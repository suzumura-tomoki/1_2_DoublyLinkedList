#pragma once
#include<string>

namespace DoublyLinkedList//bi-directional list�Ƃ�����
{
	struct Element {
		DoublyLinkedList::Element* pPrevious = nullptr;
		DoublyLinkedList::Element* pNext = nullptr;
		std::string score;
		//std::string name;
	};
};