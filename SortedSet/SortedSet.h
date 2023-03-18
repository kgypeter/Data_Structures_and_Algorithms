#pragma once
//DO NOT INCLUDE SETITERATOR

//ADT SortedSet – mit Elementen vom Typ TComp repräsentiert mithilfe einer SLLA,
//sortiert mithilfe einer Relation auf den Elementen
//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;

typedef bool(*Relation)(TComp, TComp);

#define NULL_TELEM -11111
using namespace std;

class SortedSetIterator;

class SortedSet {
    friend class SortedSetIterator;

private:
    //TODO - Representation
    //arr_elems tine minte adresa unde se gasesc elementele unui vector
    //arr_links tine minte adresa unde se gaseste next-ul
    //head tine minte pozitia actuala
    //cap dimensiunea vectorului
    //firstEmpty   tine minte pozitia primului element cu next dar fara element in vector
    //relation daca e true isi vede de treaba, daca e false adauga un element intre pozitia anterioara si cea actuala
    //(se comporta ca o functie)
    TElem *arr_elem, *arr_link;
    int cap, head;
    int firstempty;
    Relation relation;

public:
    //constructor
    SortedSet(Relation r);

    bool relatie(TComp e1, TComp e2);

    //adds an element to the sorted set
    //if the element was added, the operation returns true, otherwise (if the element was already in the set)
    //it returns false
    bool add(TComp e);


    //removes an element from the sorted set
    //if the element was removed, it returns true, otherwise false
    bool remove(TComp e);

    //checks if an element is in the sorted set
    bool search(TElem elem) const;


    //returns the number of elements from the sorted set
    int size() const;

    //checks if the sorted set is empty
    bool isEmpty() const;

    //returns an iterator for the sorted set
    SortedSetIterator iterator() const;

    // destructor
    ~SortedSet();


};
