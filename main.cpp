															//Tyler Tirado --- CS-210 --- Module Seven --- Project Three --- Corner Grocer App //
#include <iostream>
#include "GroceryItemNameandQuantity.h"
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef map <string, int> StringIntMap;//creates a map that will hold the item(string) and the quantity(int).
int userchoice{};

void count_words(istream& in, StringIntMap& words) { //function used to count the words from the text file and add them to the map while also incrementing the quantity.
	string text;
	while (in >> text) {
		++words[text];
	}
}

void PrintMenu() {//function that prints the menu to the user and records the user choice.
	
	cout << "Welcome to Corner Grocer App!" << endl;
	cout << "Please select an option from below: " << endl;
	cout << "1- Search frequency by item name" << endl;
	cout << "2- Display frequency for all items" << endl;
	cout << "3- Display frequency as a special character for all items" << endl;
	cout << "4- Quit the program" << endl;
	cin >> userchoice;
	system("CLS");
}


int main()
{
	ifstream in("CS210_Project_Three_Input_File.txt");//opens the data file for scanning.
	StringIntMap words_map; //calls the map named words_map.
	count_words(in, words_map);//calls the function above to count words.

	//for (StringIntMap::iterator it = words_map.begin(); it != words_map.end(); ++it) {//iterates through the map so we can output the data.
		//cout << "item: " << it->first << "\t" << it->second << endl;//TEST TO SEE IF THE MAP WORKED.
	//}

	ofstream outFS; //output file stream
	outFS.open("frequency.dat"); //opens an output file for our daily freq.
	if (!outFS.is_open()) { //lets you know if the file does not open.
		cout << "Could not open file...";
		return 1;
	}
	for (StringIntMap::iterator it = words_map.begin(); it != words_map.end(); ++it) {
		outFS << "item: " << it->first << "\t" << it->second << endl;
	}
	outFS.close();
	GroceryItemNameandQuantity useritem;

	do {//loops the menu and output until the user decides to quit the program.
		PrintMenu();
		if (userchoice == 4) {//handles user choice 4, which will simply quit the program.
			cout << "goodbye...";
			exit;
		}
		else if (userchoice == 2) {//handles user chocie 2, printing all item frequencies.

			for (StringIntMap::iterator it = words_map.begin(); it != words_map.end(); ++it) {//iterates through the map so we can output the data.
				cout << "item: " << it->first << "\t" << it->second << endl;//prints out the freq for all items at the users request.
				continue;
			}
		}
		else if (userchoice == 1) {//handles user choice 1, printing the freq for the user entered item.
			string itemName;
			cout << "Enter an Item you wish to search for: " << endl;//asks for the user to enter an item and then stores it as itemName.
			cin >> itemName;
			useritem.setGroceryItem(itemName);//uses the class object useritem to set the name of item entered to the Grocery item class.
			auto it = words_map.find(itemName);//iterates through the words_map to see if the entered name is present in the map.
			if (it != words_map.end()) {//if the item is found in the map, print out the item name with the quantity attached to it.
				cout << it->first << " " << it->second << endl;
			}
			else {
				cout << "not a valid item..." << endl;//if the item is not found it will print an error message telling you it is not valid.
			}
		}
		else if (userchoice == 3) {//handles user choice 3, printing the histogram of all items with the quantity as astericks.
			for (StringIntMap::iterator it = words_map.begin(); it != words_map.end(); ++it) { //iterates through the map and pulls out the item name and then converts the quantity from a number value to astericks of that quantity.
				cout << "item: " << it->first << "\t";
				for (int i = 0; i < it->second; i++) {
					cout << "*";
				}
				cout << endl;
			}
		}

		else {//handles if the user enters a choice that is not 1-4
			cout << "not a valid entry..." << endl;
			return 1;
		}
	} while (userchoice != 4);

	

	return 0;

}