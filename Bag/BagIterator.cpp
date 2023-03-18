#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

BagIterator::BagIterator(const Bag &c) : bag(c) {
    //TODO - Implementation

    index_arr = 0;
    index_freq = 0;
    tmp_freq = 1;   // cand iteram si ne intalnim cu un element prima data, freqventa este 1, nu 0
}
// complexity: all cases: Theta(1)

void BagIterator::first() {
    //TODO - Implementation
    index_arr = 0;
    index_freq = 0;
    tmp_freq = 1;   // frecventa elementelor este >= 1 pentru fiecare valoare din arr
}
// complexity: all cases: Theta(1)

void BagIterator::next() {
    //TODO - Implementation

    if (!valid()) {

        throw exception();
    }
    if (bag.freq[index_arr] == tmp_freq) {  // un element poate sa apara de mai multe ori. Astfel,
                                            // cand iterez la urmatorul element, acesta poate avea aceeasi valoare
                                            // (parcurg toate elementele cu aceeasi valoare). Ex. cazul: arr[i]=10, freq[i] > 1
        index_arr++;
        index_freq++;
        tmp_freq = 1;   // am parcurs toate elementele cu aceeasi valoare, deci resetez frecventa cand iterez la urmatorul element din arr

    } else tmp_freq++;

}
// complexity: all cases: Theta(1)

bool BagIterator::valid() const {
    //TODO - Implementation
    if (index_arr < bag.len)    // indexul trebuie sa fie < decat lungimea (primul index este 0)
        return true;

    return false;
}
// complexity: all cases: Theta(1)

TElem BagIterator::getCurrent() const {
    //TODO - Implementation
    if (this->valid())      // daca indexul este valid, returnez elementul de pe aceasta pozitie
        return bag.arr[index_arr];

    throw exception();
}
// complexity: all cases: Theta(1)



/// functia supl
//BagIterator::NewIterator(const Bag &c) : bag(c) {
//
//    index_arr = 0;
//    index_freq = 0;
//    tmp_freq = 1;
//    myiterator = 2;
//}
//
//bool BagIterator::_valid() const {
////valid
//    if (index_arr < bag.len-myiterator && index_arr >= 0)
//        return true;
//
//    return false;
//}
//
//void BagIterator::_first() {
////first
//    index_arr = myiterator;
//    index_freq = myiterator;
//    tmp_freq = 1;
//}
//
//void BagIterator::_next() {
////next
//    if (bag.freq[index_arr] == tmp_freq) {
//        if(valid()) {
//            index_arr+=myiterator;
//            index_freq+=myiterator;
//            tmp_freq = 1;
//        }
//    } else tmp_freq+=myiterator;
//}
