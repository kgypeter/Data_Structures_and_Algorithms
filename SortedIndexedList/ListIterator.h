#pragma once
#include "SortedIndexedList.h"


//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIndexedList;
private:
	const SortedIndexedList& list;
	ListIterator(const SortedIndexedList& list);

	//TODO - Representation
    node** stack; // punem elementele vizitate intr-un stack
    node* current_element;
    int len, capacity;

    void resize();
    bool in_stack(node* nod);
    static node* getParentNode(node* nod, const SortedIndexedList& list);

public:
	void first();
	void next();

    void prev();  // func supl - prev

	bool valid() const;
    TComp getCurrent() const;
    ~ListIterator();
};


