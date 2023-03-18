#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>

using namespace std;

/*
4. ADT Bag: sequentielle Repraesentierung mithilfe von Paaren der Form (Element,
Frequenz) in einem dynamischen Array (oder mit zwei dynamischen Arrays). Zum
Beispiel, das Bag [5, 10, -1, 2, 3, 10, 5, 5, -5] wird folgendermasen repraesentiert: [(5, 3),
(10, 2), (-1, 1), (2, 1), (3, 1), (-5,1)].
*/

Bag::Bag() {
    // TODO - Implementation
    this->capacity = 5; // capacitate
    this->len = 0;  // lungime
    arr = new int[capacity];    // contine elementele
    freq = new int[capacity];   // frecventa elementelor din arr

}

void Bag::add(TElem elem) {
    // TODO - Implementation

    if (len == capacity) { // avem nevoie de o capacitate mai mare
        int *tmp = new int[capacity];   // arr temporar
        int *tmp_f = new int[capacity]; // freq temporar
        for (int i = 0; i < len; i++) { // copiez valorile din arr si freq in arr- si freq-ul temporar (in mod dinamic)
            tmp[i] = arr[i];
            tmp_f[i] = freq[i];
        }
        delete[] arr;   // dealocarea memoriei
        delete[] freq;
        capacity *= 2;  // maresc capacitatea, deoarece lungimea este egala cu capacitatea

        arr = new int[capacity];    // realocarea memoriei cu capacitatea marita
        freq = new int[capacity];
        for (int i = 0; i < len; i++) { // copiem inapoi valorile din arr si freq temporar
            arr[i] = tmp[i];
            freq[i] = tmp_f[i];
        }
        delete[] tmp;   // dealocam memoria
        delete[] tmp_f;

    }

    // adaugarea elementului
    for (int i = 0; i < len; i++)
        if (arr[i] == elem) {
            freq[i]++; // elementul apare deja in arr, deci doar incrementez frecventa
            return;
        }

    // elementul inca nu a aparut in arr
    arr[len] = elem; // adaugam elementul la sfarsit
    freq[len] = 1;  // elementul nou apare doar o data
    len++;  // incrementez lungimea, intrucat am adaugat un element nou in arr
}
// complexity: best case: Theta(1), worst case: Theta(n^3), average case: Theta(n^3), general case: O(n^3)

bool Bag::remove(TElem elem) {
    // TODO - Implementation
    for (int i = 0; i < len; i++)
        if (arr[i] == elem) {
            freq[i]--; // elem erscheint in arr
            if (freq[i] ==
                0) { // frecventa elementului este 0, deci copiem ultimul element din arr si freq la acest index
                arr[i] = arr[len - 1];
                freq[i] = freq[len - 1];
                len--;  // decrementez lungimea dupa stergerea unui element
            }
            return true;    // elementul a fost gasit si sters
        }
    return false;   // elementul nu a fost gasit
}
// complexity: best case: Theta(1), worst case: Theta(n), Average case: Theta(n), general case: O(n)

bool Bag::search(TElem elem) const {
    // TODO - Implementation

    for (int i = 0; i < len; i++) { // cautare liniara a elementului
        if (arr[i] == elem)
            return true;
    }
    return false;
}
// complexity: best case: Theta(1), worst case: Theta(n), Average case: Theta(n), general case: O(n)

int Bag::nrOccurrences(TElem elem) const {
    // TODO - Implementation
    for (int i = 0; i < len; i++)
        if (arr[i] == elem)
            return freq[i]; // returnez freqventa elementului de pe pozitia in care l-am gasit

    return 0;
}
// complexity: best case: Theta(1), worst case: Theta(n), Average case: Theta(n), general case: O(n)

int Bag::size() const {
    // TODO - Implementation
    int s = 0;  // calculez suma elementelor din freq, ceea ce este lungimea arr-ului
    for (int i = 0; i < len; i++)
        s += freq[i];

    return s;
}
// complexity: best case: Theta(1), worst case: Theta(n), Average case: Theta(n), general case: O(n)

bool Bag::isEmpty() const {
    // TODO - Implementation
    return len == 0;
}
// complexity: all cases: Theta(1)

BagIterator Bag::iterator() const {
    return BagIterator(*this);
}

Bag::~Bag() {
    // TODO - Implementation
    delete[] arr;   // dealocarea memoriei
    delete[] freq;
}
// complexity: all cases: Theta(1)

