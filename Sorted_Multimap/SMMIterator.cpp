#include "SMMIterator.h"
#include "SortedMultiMap.h"


SMMIterator::SMMIterator(const SortedMultiMap &c) : col(c) {
    current_key = col.head;
    if (current_key != nullptr)
        current_value = col.head->head;
    else current_value = nullptr;
    while(current_key!= nullptr && current_value== nullptr )
    {
        current_key=current_key->next;
        if(current_key!= nullptr)
            current_value=current_key->head;
    }
}

TElem SMMIterator::getCurrent()  {
    if(!valid()) throw exception();
    while(current_key!= nullptr  && current_value==nullptr)
    {current_key=current_key->next;
        if(current_key!= nullptr)
        current_value=current_key->head;}
    return TElem(current_key->value, current_value->value);
}

bool SMMIterator::valid() const {
    if(current_key== nullptr) return false;
    if( current_key== nullptr || (current_key->next== nullptr && current_value== nullptr)) return false;
    if (current_value != nullptr || current_key!= nullptr) return true;
    return false;
}

void SMMIterator::next() {
    if(!valid()) throw exception();
    while(current_key!=nullptr && current_key->next!=nullptr && current_value==nullptr)
    {current_key=current_key->next;
        current_value=current_key->head;}

    if(current_value!= nullptr && current_value->next!= nullptr)
        current_value=current_value->next;
    else
    {
        current_key=current_key->next;
        if(current_key!= nullptr)
            current_value=current_key->head;
        else current_value=nullptr;
    }
    while(current_key!=nullptr && current_key->next!=nullptr && current_value==nullptr)
    {current_key=current_key->next;
        current_value=current_key->head;}


//    if (current_value->next == nullptr && current_key->next == nullptr) {
//        current_key = current_key->next;
//        current_value = current_value->next;
//    } else if (current_value== nullptr || current_value->next == nullptr ){
//        current_key = current_key->next;
//        current_value=current_key->head;}
//    else
//        current_value = current_value->next;

}

void SMMIterator::first() {

    current_key = col.head;
    if(current_key!=nullptr)
    current_value = col.head->head;
    else current_value= nullptr;
    while(current_key!= nullptr && current_value== nullptr )
    {
        current_key=current_key->next;
        if(current_key!= nullptr)
            current_value=current_key->head;
    }
}

