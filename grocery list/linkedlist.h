#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;




struct gItem
{
	int product_number;
	string name;
	double price;
	bool tax;
};

typedef gItem ItemType;

struct NodeType
{
	ItemType info;
	NodeType* next;
};


class gList
{
public:
	// default constructor
	// post: creates an empty list of zero elements
	gList();

	// copy constructor
	// post: list contents are copied to this new list
	gList(const gList& copy_me);
	
	void operator=(const gList&);

	// destructor
	// post: deletes elements from memory
	~gList();
	
	// add an element to the list, searching for it by key
	// pre: requires a list element of this list's type
	// post: new element is added to the list and length is incremented by one 
	void insertItem(ItemType );


	// searches list for a given item
	// pre: given item for search is in key data type 
	// post: returns false if it does not exist in the list or if list is empty, 
	//       or returns true if exists
	bool retrieveItem(int ) const;

	
	// remove an item from list
	// pre: list is not empty and the item exists in the list
	// post: removes gvien item from the list, deleting it from memory
	void deleteItem(ItemType );

	
	// remove all items from list
	// post: deletes all items from memory. length becomes 0
	void clear();


	// retrieves size of list
	// post: returns an integer representing list size
	int size() const;

	// returns true if the list is empty 
	// post: returns true if the list length is 0, false if the list length is >0
	bool isEmpty();

	//returns true if the list is full
	//post: returns true if the list is max length, which would be 100 in the case of the grocery list
	bool isFull();


	//iterator - returns the next item in the list
	//pre: list is not empty
	//post: if the current position is NULL, set it to the beginning of the list first.
	//		returns the item pointed by the current position and moves the current to the next
	//ItemType GetNextItem() const;  


	//reset the current position of the iterator
	//post: current is set to NULL
	void ResetList();	

	//pre: something in the list
	//post: will return the item type 
	ItemType getItem (int item, bool & found);

	
	
private:
	int length;				//the number of items in the list
	NodeType* list;			//points to the beginning of the list DON'T DELETE
	NodeType* current;		//current position for iterator
};

bool operator != (ItemType & l1, ItemType &l2);
bool operator < (ItemType & l1, ItemType & l2);
bool operator > (ItemType & l1, ItemType & l2);
bool operator ==(ItemType & l1, ItemType & l2);
//ostream& operator<< (ostream& out, const gList& l);