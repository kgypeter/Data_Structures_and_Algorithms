#pragma once
//DO NOT INCLUDE SMMITERATOR

#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;

struct ValueNode {
    ValueNode* previous;
    ValueNode* next;
    TValue value;
};

struct KeyNode {
    KeyNode* previous;
    KeyNode* next;
    TKey value;
    ValueNode* head;
};


#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class SMMIterator;

typedef bool(*Relation)(TKey, TKey);

class SortedMultiMap
{
    friend class SMMIterator;

private:
    KeyNode * head;
    KeyNode* FindKey(TKey c);
    int nr_values;
    Relation r;

    //TODO - Representation

public:
    //constructor
    SortedMultiMap(Relation r);


    /// functia supl.
//    bool relation_s1(TKey cheie1, TKey cheie2) {
//        if (cheie1 == cheie2) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//    bool relation_s2(TKey cheie1, TKey cheie2) {
//        if (cheie1 == cheie2) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//
//    SortedMultiMap Interclasare();
    /// sfarsit- functia supl.


    //adds a key value pair to the sorted multimap
    void add(TKey c, TValue v);

    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (if it was in the sorted multimap) and false otherwise
    bool remove(TKey c, TValue v);

    //returns the vector of values associated to a key. If the key is not in the SortedMultiMap, the vector is empty
    vector<TValue> search(TKey c) const;

    //returns the number of pairs from the sorted multimap
    int size() const;

    //checks whether the sorted multimap is empty
    bool isEmpty() const;

    //returns an iterator for the sorted multimap
    SMMIterator iterator() const;

    //descturctor
    ~SortedMultiMap();


};
