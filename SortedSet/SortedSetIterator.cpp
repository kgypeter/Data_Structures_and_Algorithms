#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet &m) : multime(m) {
    //TODO - Implementation
    this->index = multime.head; //returneaza index
}

void SortedSetIterator::first() {
    //TODO - Implementation
    this->index = multime.head;
}


void SortedSetIterator::next() { // de refacut
    //TODO - Implementation
    //78 11 6 59 19 44
    //-1  5 2  1  6  4
    //head= 3
    if (this->index == -1)
        throw exception();
    this->index = multime.arr_link[this->index];
}

TElem SortedSetIterator::getCurrent() {
    //TODO - Implementation
    if (!valid())
        throw exception();
    return multime.arr_elem[this->index];
}

bool SortedSetIterator::valid() const {
    //TODO - Implementation
//    int len = multime.arr_ele.size();
    if (this->index > 0 and this->index <= multime.cap)
        return true;
    return false;
}

