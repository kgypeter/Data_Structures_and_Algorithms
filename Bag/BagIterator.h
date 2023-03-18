#include "Bag.h"

class BagIterator
{
	//DO NOT CHANGE THIS PART
	friend class Bag;
	
private:
	const Bag& bag;				
	//TODO  - Representation		
	int index_arr;		// current position of element in arr
	int index_freq;		// current position of element in freq
    int tmp_freq = -1;

///functia supl
    //    int myiterator;
///
	BagIterator(const Bag& c);
public:
	void first();
	void next();
	TElem getCurrent() const;
	bool valid() const;
///functia supl
//    void _first();
//    void _next();
//    TElem _getCurrent() const;
//    bool _valid() const;
///
};
