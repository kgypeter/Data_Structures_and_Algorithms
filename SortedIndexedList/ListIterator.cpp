#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

node *ListIterator::getParentNode(node *nod, const SortedIndexedList &list) {
    node* current = list.root;

    if(current == nod){
        return nullptr;
    }
    else{
        while(current != nullptr and current->right!=nod and current->left!=nod){
            if(list.r(nod->info, current->info))
            {
                current = current->left;
            }
            else current = current->right;
        }
            return current;
    }

}

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	//TODO - Implementation
    this->current_element = list.root;  // arborele incepe de la root si cautam elementul cel mai din stanga (traversare in-order)
    if(current_element != nullptr)
    {
        while (current_element->left != nullptr) {
            current_element = current_element->left;
        }
    }
    this->capacity = 5;
    this->len = 1;
    this->stack = new node *[this->capacity]; // cream stackul
    this->stack[0] = current_element; // primul element este elementul curent
}

void ListIterator::first(){
	//TODO - Implementation
    this->current_element = list.root;
    if(current_element!=nullptr)
    {
        while (current_element->left != nullptr) { //// caut urmatorul element in functie de relatie in arbore
            current_element = current_element->left;
        }
        this->capacity = 5;
        this->len = 1;
        delete[] stack; // stergem stackul

        // incep din nou un stack
        this->stack = new node *[this->capacity]; // cream stackul
        this->stack[0] = current_element; // primul element este elementul curent
    }

}

void ListIterator::next(){
	//TODO - Implementation
    if(valid()){
        if(len == capacity){
            resize();
        }
        if(current_element->right != nullptr){ // caut urmatorul element in functie de relatie in arbore
            current_element = current_element->right;
            while(current_element->left!=nullptr){
                current_element = current_element->left;
            }
            this->stack[len] = current_element; // punem in stack nodul vizitat
            len++;
        }
        else{
            while(this->in_stack(this->current_element))    // continuam sa urcam in arbore pana ajungem la un nod nevizitat
                this->current_element = getParentNode(this->current_element, list);
            this->stack[len] = current_element;
            len++;
        }
    }
    else throw exception();
}

// functia suplimentara
void ListIterator::prev(){
    if(valid()){
        if(len == capacity){
            resize();
        }
        if(current_element == list.root) // ma uit daca sunt la radacina (nu are previous)
            throw exception();
        else{
            while(this->in_stack(this->current_element))    // continuam sa urccam in arbore pana ajungem la un nod nevizitat
                this->current_element = getParentNode(this->current_element, list);
            this->stack[len] = current_element;
            len++;
        }
    }
    else throw exception();
}
//end - functia suplimentara

bool ListIterator::valid() const{
	//TODO - Implementation
    if(current_element != nullptr)
        return true;
	return false;
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
    if(valid()){
        return this->current_element->info;
    }
    else throw exception();
}

bool ListIterator::in_stack(node *nod) {    // verificam daca nodul dat se afla in stack
    for(int i = 0; i<len;i++){
        if(nod == stack[i])
            return true;
    }
    return false;
}

void ListIterator::resize(){
    auto tempStack = new node*[this->capacity*2];
    for(int i=0;i<len;i++)
        tempStack[i] = this->stack[i];
    delete[] this->stack;
    this->stack = tempStack;
    capacity*=2;
}

ListIterator::~ListIterator(){
    delete[] stack;
}
