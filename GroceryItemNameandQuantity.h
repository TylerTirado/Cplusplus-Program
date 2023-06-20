#ifndef GROCERY_ITEM_NAME_AND_QUANTITY_H
#define GROCERY_ITEM_NAME_AND_QUANTITY_H
#include <iostream>
#include <string>
using namespace std;

class GroceryItemNameandQuantity {
public:
	GroceryItemNameandQuantity();
	void setGroceryItem(string itemName);

	string getGroceryItem();
private:
	string itemName;
};
#endif

