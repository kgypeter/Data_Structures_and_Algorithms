#pragma once
#include "SortedMultiMap.h"

class MultiMap;

class SMMIterator
{
    friend class MultiMap;

private:
    const SortedMultiMap& col;
    KeyNode* current_key;
    ValueNode* current_value;




public:
    SMMIterator(const SortedMultiMap& c);
    TElem getCurrent();
    bool valid() const;
    void next();
    void first();
};

