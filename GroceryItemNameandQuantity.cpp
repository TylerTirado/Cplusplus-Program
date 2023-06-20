#include <iostream>
using namespace std;

#include "GroceryItemNameandQuantity.h"

GroceryItemNameandQuantity::GroceryItemNameandQuantity()
{
	this->itemName = "none";
}

void GroceryItemNameandQuantity::setGroceryItem(string itemName)
{
	this->itemName = itemName;
}

string GroceryItemNameandQuantity::getGroceryItem()
{
	return itemName;
}
