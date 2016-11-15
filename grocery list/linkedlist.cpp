//.cpp file for the default link list.
#include "stdafx.h"
#include "linkedlist.h"
#include <iostream>

using namespace std;

//the default constructor
gList::gList()
{
	length = 0;
	list = NULL;
	current = NULL;
}

//part of the big three, it is the copy constructor
gList::gList(const gList& copy_me)
{
	for (auto node = copy_me.list; node != NULL; node = node->next)
	{
		insertItem(node->info);
	}
	
}

//part of the big three, is the destructor 
gList::~gList()
{
	NodeType * tempPtr;
	while (list != NULL)
	{
		tempPtr = list;
		list = list->next;
		delete tempPtr;
	}
}

//clears the list
void gList::clear()
{
	NodeType* ptr;
	while (list != NULL)
	{
		ptr = list;
		list = list->next;
		delete ptr;
	}
	length = 0;
}

//checks to see if the list is full
bool gList::isFull()
{
	NodeType * ptr = new NodeType;
	if(ptr == NULL)
		return true;
	delete ptr;
	return false;
}

//checks to see if the item is there or not
bool gList::retrieveItem(int target) const
{
	NodeType * ptr = list;
	while(ptr != NULL)
	{
		if(ptr->info.product_number == target)
			return true;
		ptr = ptr->next;
	}
	return false;
}

//part of the big three it overloads the = operator
void gList::operator = (const gList& src)
{
	//length = src.length;
	for (auto node = src.list; node != NULL; node = node->next)
	{
		insertItem(node->info);
	}
}

//inserts the item into the list
void gList::insertItem(ItemType item)
{
	NodeType* newNode;
	NodeType* predLoc;
	NodeType* location;
	bool moreToSearch;

	location = list;
	predLoc = NULL;
	moreToSearch = (location != NULL);

	while (moreToSearch)
	{
		if(item > location->info)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
			break;
		}

		if(item < location->info)
		{
			moreToSearch = false;
			break;
		}
	}

	newNode = new NodeType;
	newNode->info = item;

	if(predLoc == NULL)
	{
		newNode->next = list;
		list = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
}

	
//checks to see if it is empty
bool gList::isEmpty()
{
	return length == 0;
}

//returns the size or the length of the list
int gList::size() const
{
	return length;
}

//resets the list
void gList::ResetList()
{
	clear();
}

//is given the product number and returns the itemtype
ItemType gList::getItem (int  item, bool & found)
{
	
	NodeType * ptr = list;
	while(ptr != NULL)
	{
		if(ptr->info.product_number == item)
			return ptr->info;
			
		ptr = ptr->next;
	}
}

	

	
//deletes an item
void gList::deleteItem(ItemType item)
{
	NodeType* location = list;
	NodeType* tempLoc;

	if(item == list->info)
	{
		tempLoc = location;
		list = list->next;
	}

	else
	{
		while(item != list->info)
		{
			location = location->next;
		}

		tempLoc = location->next;
		location->next = (location->next)->next;
	}
	delete tempLoc;
	length--;

}

//overloads the != operator 
bool operator != (ItemType & l1, ItemType &l2)		// cheks to see if products are not equal
{
	if((l1.name != l2.name) && (l1.price != l2.price) && (l1.product_number != l2.product_number)
		&& (l1.tax != l2.tax))
		return true;
	else
		return false;
}

//overloads the == operator
bool operator ==(ItemType & l1, ItemType &l2)  //checks to see if products are equal
{
	if((l1.name == l2.name) && (l1.price == l2.price) && (l1.product_number == l2.product_number)
		&& (l1.tax == l2.tax))
		return true;
	else
		return false;
}

//checks to see if product number is less than other product number for sorting 
bool operator <(ItemType & l1, ItemType &l2)  
{
	if(l1.product_number < l2.product_number)
		return true;
	else
		return false;
}

//checks to iss if product number is greater than other product number for sorting
bool operator >(ItemType & l1, ItemType &l2)
{
	if(l1.product_number > l2.product_number)
		return true;
	else
		return false;
}


