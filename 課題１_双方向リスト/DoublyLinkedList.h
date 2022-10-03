#pragma once
#include<string>

namespace DoublyLinkedList//bi-directional list‚Æ‚à‚¢‚¤
{
	struct Element {
		DoublyLinkedList::Element* pPrevious = nullptr;
		DoublyLinkedList::Element* pNext = nullptr;
		std::string score;
		//std::string name;
	};
};