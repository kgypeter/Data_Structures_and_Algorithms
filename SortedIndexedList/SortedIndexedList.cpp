#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	//TODO - Implementation
    this->len = 0;
    this->root = nullptr;
    this->r = r;
}

int SortedIndexedList::size() const {
	//TODO - Implementation
    return len;
}

bool SortedIndexedList::isEmpty() const {
	//TODO - Implementation
    if(len == 0)
        return true;
	return false;
}

TComp SortedIndexedList::getElement(int i) const{
	//TODO - Implementation
    if(i<0 or i>len)
        throw exception();

    ListIterator iterator(*this);   // declaram un iterator pe lista in care suntem
    int index=0;

    while(index<i) {    // cautam elementul de pe pozitia i
        index++;
        iterator.next();
    }

	return iterator.getCurrent(); // returnnez valoarea elementului gasit
}


///////// remove functions

node* SortedIndexedList::minimum(node* rmNode){
    if(rmNode==nullptr)
        return nullptr;
    else{
        while(rmNode->left != nullptr) // cautam minimul in subarborele cu radacina rmNode
            rmNode = rmNode->left;
        return rmNode;
    }
}

node* SortedIndexedList::removeRec(node* rmNode, TComp e){
    if(rmNode == nullptr){
        return nullptr;
    }
    else if(rmNode->info == e){
        //Der Knoten, der gelöscht werden muss, hat kein Kind:
        //Setze das entsprechende Kind des Vaterknotens auf NIL
        if(rmNode->left == nullptr and rmNode->right == nullptr){
                return nullptr;
        }

            //Der Knoten, der gelöscht werden muss, hat ein Kind:
            //Ersetze den gelöschten Knoten mit seinem Kind (setze das Kind des Vaterknotens auf
            //seinem Kind)
        else if(rmNode->left == nullptr){
            return rmNode->right;
        }
        else if(rmNode->right == nullptr){
            return rmNode->left;
        }
            //Der Knoten, der gelöscht werden muss, hat zwei Kinder:
            //Finde den minimalen Wert aus dem rechten Teilbaum, ersetze den gelöschten Wert mit
            //diesem minimalen Wert und lösche den minimalen Wert
        else{
            node *min = minimum(rmNode->right);
            rmNode->info = min->info;
            rmNode->right = removeRec(rmNode->right, min->info);
            return rmNode;
        }
    }
    // parcurgem arborele pana la nodul cautat
    else if(r(e, rmNode->info)) {
        rmNode->left = removeRec(rmNode->left, e);
        return rmNode;
    }
    else {
        rmNode->right = removeRec(rmNode->right, e);
        return rmNode;
    }

}

TComp SortedIndexedList::remove(int i) {
	//TODO - Implementation
    if(i<0 or i>len)
        throw exception();
    ListIterator iterator(*this); // declaram un iterator pe lista in care suntem
    int index = 0;
    while(index < i){ // cautam elementul de la pozitia i
        iterator.next();
        index++;
    }
    // tinem minte valoarea pe care vrem sa o stergem in temp
    TComp temp = iterator.getCurrent();
    // actualizam pathul din arbore de la root pana la elementul sters
    this->root = removeRec(root, temp);
    len--;
	return temp;
}

////////////// end remove functions


int SortedIndexedList::search(TComp e) const {
	//TODO - Implementation
    ListIterator iterator(*this);
    for(int i=0;i<len;i++){
        if(iterator.getCurrent() == e)
            return i;
        iterator.next();
    }
	return -1;
}


///////////// add functions
node *SortedIndexedList::initNode(TComp e) { // creem un nod nou

    node* newNode = new node;
    newNode->info = e;
    newNode->left = nullptr;
    newNode->right = nullptr;
//    newNode->elem_left = 0;

    return newNode;
}

node* SortedIndexedList::addRec(node* newNode, TComp e) { // adaugam nodul la pozitia dorita

    if(newNode == nullptr)
        newNode = initNode(e);
    else if(r(e, newNode->info))
        newNode->left = addRec(newNode->left, e);
    else
        newNode->right = addRec(newNode->right, e);

    return newNode;
}//coplexity: O(n)

void SortedIndexedList::add(TComp e) {

    if( root == nullptr )
        root = initNode(e);
    else
        addRec(root, e);
    len++;
}
//////////////end add functions


ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//TODO - Implementation
    if(root!=nullptr) // daca arborele nu este goala
    {
        node **temp = new node *[len];   // fac un array temporar cu toate nodurile si sterg nod cu nod
        ListIterator iterator(*this);

        for (int i = 0; i < len; i++) { // pune,m elementele in arrayul temporar
            temp[i] = iterator.current_element;
            iterator.next();
        }

        for (int i = 0; i < len; i++)  // sterg elementele din arrayul temporar
            delete temp[i];

        delete[] temp;
    }  // sterg arrayul temporar
}
