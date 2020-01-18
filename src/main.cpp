#include <iostream>
#include <vector>

using namespace std;

#include "ItemToPurchase.h"

int main() {

	const int NUMBER_OF_ITEMS = 2;							// Number of items to prompt user for
	vector<ItemToPurchase> shoppingList;					// Vector to hold items
	string itemName;
	string itemDescription;
	int itemPrice;
	int itemQuantity;
	int totalCost = 0;										// Summation of all item prices

	// Exception handling is beyond the scope of this lab
	// Capture the items purchased
	for (int i = 0; i < NUMBER_OF_ITEMS; ++i) {
		// Instantiate a new ItemToPurchase
		// Default constructor will be called at initialization
		ItemToPurchase itemToPurchase;
		cout << "Item " << (i + 1) << endl;
		cout << "Enter the item name:" << endl;
		// getline() captures all remaining text on the current input line
		// up to the next newline character, allowing for entry of whitespace
		getline(cin, itemName);
		// Set input to itemName
		itemToPurchase.SetName(itemName);
		cout << "Enter the item description:" << endl;
		getline(cin, itemDescription);
		// Set input to itemDescription
		itemToPurchase.SetDescription(itemDescription);
		cout << "Enter the item price:" << endl;
		cin >> itemPrice;
		// Set input to itemPrice
		itemToPurchase.SetPrice(itemPrice);
		cout << "Enter the item quantity:" << endl;
		cin >> itemQuantity;
		cout << endl;
		// Set input to itemQuantity
		itemToPurchase.SetQuantity(itemQuantity);
		// add the item to the ShoppingList vector
		shoppingList.push_back(itemToPurchase);
		// Add the item's price to the total cost
		totalCost += (itemToPurchase.GetPrice() * itemToPurchase.GetQuantity());
		// Before prompting for the second item, call cin.ignore()
		// to allow the user to input a new string
		cin.ignore();
	}

	// Print the items purchased and their total cost
	cout << "TOTAL COST" << endl;
	for (unsigned int i = 0; i < shoppingList.size(); ++i) {
		shoppingList.at(i).PrintItemCost();
		cout << endl;
		shoppingList.at(i).PrintItemDescription();
	}

	cout << endl;
	cout << "Total: $" << totalCost << endl;

	return 0;
}


