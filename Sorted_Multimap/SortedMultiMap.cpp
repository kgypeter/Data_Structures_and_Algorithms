#include "SortedMultiMap.h"
#include "SMMIterator.h"
#include <exception>
#include <iostream>

using namespace std;
// 31. ADT SortedMultiMap – repräsentiert mithilfe einer DLL mit eindeutigen Schlüsseln (key)
// und sortiert mithilfe einer Relation auf den Schlüsseln (key). Für jeden Schlüssel
// speichert man eine DLL von Werten (value).

SortedMultiMap::SortedMultiMap(Relation r) { // complexity: Theta(1)
    head = nullptr;
    nr_values = 0;
    this->r = r;

}

KeyNode *SortedMultiMap::FindKey(TKey c) { // complexity: worst: Theta(n), best: Theta(1), average: Theta(n) -> O(n)
    KeyNode *aux = head;
    while (aux != nullptr) {
        if (aux->value == c) {
            return aux;
        }
        aux = aux->next;
    }
    return nullptr;
}

void
SortedMultiMap::add(TKey c, TValue v) { // complexity: worst: Theta(n^2), best: Theta(1), average: Theta(n^2), ->O(n^2)

    // situatii particulare: adaugam la sfarsit, in mijloc sau la prima pozitie

    KeyNode *key = FindKey(c);
    if (key != nullptr) {
        ValueNode *aux = key->head;
        if (aux != nullptr) {
            while (aux->next != nullptr)
                aux = aux->next;
            ValueNode *added_value = new ValueNode;
            added_value->previous = aux;
            added_value->next = nullptr;
            added_value->value = v;
            aux->next = added_value;
        }
    } else if (head == nullptr) {
        ValueNode *added_value = new ValueNode;
        added_value->previous = nullptr;
        added_value->next = nullptr;
        added_value->value = v;
        KeyNode *added_key = new KeyNode;
        added_key->previous = nullptr;
        added_key->next = nullptr;
        added_key->value = c;
        added_key->head = added_value;
        head = added_key;
    } else {
        ValueNode *added_value = new ValueNode;
        added_value->previous = nullptr;
        added_value->next = nullptr;
        added_value->value = v;
        KeyNode *aux = head;
        if (r(c, aux->value)) {

            KeyNode *added_key = new KeyNode;
            added_key->previous = nullptr;
            added_key->value = c;
            added_key->next = head;
            added_key->head = added_value;
            head->previous = added_key;
            head = added_key;

        } else {
            while (aux->next != nullptr && r(aux->next->value, c)) {
                aux = aux->next;
            }

            KeyNode *added_key = new KeyNode;
            added_key->previous = aux;
            added_key->value = c;
            added_key->next = aux->next;
            added_key->head = added_value;
            aux->next = added_key;
        }

    }
    nr_values++;

}


bool
SortedMultiMap::remove(TKey c, TValue v) { // complexity: best: Theta(1), worst: Theta(n), average: Theta(n), -> O(n)
    KeyNode *aux_key = FindKey(c);
    if (aux_key == nullptr)     // cheia pointeaza catre null
        return false;
    ValueNode *head_value = aux_key->head;
    while (head_value != nullptr) {
        if (head_value->value == v) {
            if (head_value->next == nullptr && head_value->previous == nullptr) { aux_key->head = nullptr; }
            else if (head_value->previous == nullptr) {
                aux_key->head = head_value->next;
                aux_key->head->previous = nullptr;
            } else {
                if (head_value->previous != nullptr)
                    head_value->previous->next = head_value->next;
                if (head_value->next != nullptr)
                    head_value->next->previous = head_value->previous;
            }
            delete head_value;  // dealocarea valorii din head_value
            nr_values--;
            return true;
            break;

        }
        head_value = head_value->next;  // mut pointeru mai departe
    }

    return false;
}


vector<TValue>
SortedMultiMap::search(TKey c) const {   // complexity: worst: Theta(n^2), best: Theta(1), avg: Theta(n^2), -> O(n^2)
    KeyNode *aux;
    aux = head;
    vector<TValue> v;
    while (aux != nullptr) {    // pana cand nu ajung la sfarsit, nextul ultimului element pointeaza catre null

        if (aux->value == c) {
            ValueNode *aux2;
            aux2 = aux->head;
            while (aux2 != nullptr) {
                v.emplace_back(aux2->value);
                aux2 = aux2->next;
            }
        }
        aux = aux->next;
    }
    return v;
}


int SortedMultiMap::size() const { // complexity: Theta(1)

    return nr_values; // numarul elementelor
}

bool SortedMultiMap::isEmpty() const { // complexity: Theta(1)
    if (nr_values == 0) return true;    // o cheie nu are nicio valoare
    return false;
}

SMMIterator SortedMultiMap::iterator() const {  // complexity: Theta(1)
    return SMMIterator(*this);
}

// destructor
SortedMultiMap::~SortedMultiMap() { // complexity: worst: Theta(n), best: Theta(1), average: Theta(n), -> O(n)
    KeyNode *aux;

    while (head != nullptr) {
        aux = head;
        head = head->next;
        delete aux; // dealocarea memoriei in mod dinamic
    }
}
