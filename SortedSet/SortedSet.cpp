#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>

using namespace std;


SortedSet::SortedSet(Relation r) {
    //TODO - Implementation
    this->head = -1; //pozitia de inceput
    this->relation = r;
    this->cap = 5;
    this->arr_elem = new TElem[cap];
    this->arr_link = new TElem[cap];
    for (int i = 1; i < cap; i++) {
        arr_link[i] = NULL_TELEM;
        arr_elem[i] = NULL_TELEM;
    }
    this->firstempty = -1; //tine minte nexturile neocupate cu elemente
}


bool SortedSet::add(TComp elem) { //de inserat pe pozitii empty
    //TODO - Implementation
    if (search(elem)) //elementul este deja in lista
        return false;

    // inserare cu sir gol
    if (isEmpty()) {
        this->arr_elem[1] = elem;
        this->arr_link[1] = -1;
        this->head = 1;
        return true;
    }

    int count = size();
    if (count == cap - 1) {
        cap *= 2;
        TElem *new_arrayelem = new TElem[cap], *new_arraylink = new TElem[cap];
        for (int i = 1; i < cap; i++) {
            new_arraylink[i] = NULL_TELEM;
            new_arrayelem[i] = NULL_TELEM;
        }
        for (int i = 1; i <= count; i++) { //Best case/Worst case: lange
            new_arrayelem[i] = arr_elem[i];
            new_arraylink[i] = arr_link[i];
        }
        delete[] this->arr_link;
        delete[] this->arr_elem;
        this->arr_link = new_arraylink;
        this->arr_elem = new_arrayelem;
    }
    //inserare in empty uri
    //inserare la inceput
    if (!relation(arr_elem[head], elem)) {
        arr_elem[++count] = elem;
        arr_link[count] = head;
        head = count;
        return true;
    }
    //inserare in sir + final
    int current = head, prev = -1;
    while (arr_elem[current] != NULL_TELEM and current != -1 and relation(arr_elem[current], elem)) {
        prev = current;
        current = arr_link[current];
    }
    //daca e final
    if (current == -1) {
        arr_elem[++count] = elem;
        arr_link[count] = -1;
        arr_link[prev] = count;
        return true;
    }
        // in sir
    else {
        arr_elem[++count] = elem;
        arr_link[count] = current;
        arr_link[prev] = count;
        return true;
    }
}

bool SortedSet::remove(TComp elem) { //gata
    //TODO - Implementation
    //stergi si nextul nu numai elementul, dar tii minte pozitia de indexare
    //de unde l ai sters
    //78  11 6 59 19 44 13 76 80 4
    //9   7  2 8  6  4   5  1 -1 3
    //head = 10
    //remove(80)
    //current = -1
    //prev = 9
    //prevprev = 1
    int current = head, prev = -1, prevprev = -1;
    while (arr_elem[current] != elem and current != -1) {
        prevprev = prev;
        prev = current;
        current = arr_link[current];
    }
    if (current != -1 or arr_elem[prev] == elem) {
        if (current == head) {
            head = arr_link[head];
        } else {
            arr_link[prev] = arr_link[current];
        }
        arr_link[current] = NULL_TELEM;
        arr_elem[current] = NULL_TELEM;
        return true;
    }

//    stergere ultimul element
    if (arr_elem[prev] == elem) {
        arr_link[prevprev] = -1;
        arr_link[prev] = NULL_TELEM;
        arr_elem[prev] = NULL_TELEM;
        return true;
    }
    return false;
}

//78  11 6 59 19 44 13 76 80 4
//9   7  2 8  6  4   5  1 -1 3
//head = 10
//remove(80)
//current = -1
//prev = 9
//prevprev = 1
bool SortedSet::search(TComp elem) const { //gata
    //TODO - Implementation
    int current = head, prev = -1;
    while (current != -1 and arr_elem[current] != elem) {
        prev = current;
        current = arr_link[current];
    }

    //ultimul element din sir
    if (current == -1 and arr_elem[prev] == elem)
        return true;

    if (current != -1)
        return true;
    return false;
}
//78  11 6 59 19 44 13 76 80 4
//9   7  2 8  6  4   5  1 -1 3
//head = 10
//search(6)
//current = -1
//prev = 9


int SortedSet::size() const {
    //TODO - Implementation
    int length = 0;
    if (head != -1) {
        length = 1;
        int current = arr_link[head];
        while (current != -1) {
            length++;
            current = arr_link[current];
        }
    }
    return length;
}

//78 11 6 59 19 44
//-1  5 2  1  6  4
//head= 3
bool SortedSet::isEmpty() const {
    //TODO - Implementation
    if (this->head == -1) // numaratoarea incepe de la 1
        return true;
    return false;
}

SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    //TODO - Implementation
    delete[] arr_elem;
    delete[] arr_link;
}


