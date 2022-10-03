#pragma once
#include<string>

namespace DoublyLinkedList//bi-directional list‚Æ‚à‚¢‚¤
{
	struct Element {
		DoublyLinkedList::Element* pPrevious;
		DoublyLinkedList::Element* pNext;
		std::string score;
		//std::string name;
	};
};