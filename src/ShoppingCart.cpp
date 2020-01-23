/*
 * Any file that uses this class, including the member function
 * definition file, must include the header file in which
 * the class is defined
 */

#include <iostream>
#include <cctype>				// Needed for char to lower conversion
using namespace std;

#include "ShoppingCart.h"

/*
 * In order to compile correctly, the scope resolution operator (::)
 * must be used to tie the function definition to it's original
 * declaration in the header file
 */

/*
 * The 'this' implicit parameter is used to reference the class data
 * members where applicable; The compiler converts object function calls
 * via the dot operator into a function call where the object is implicitly
 * passed as one of the function arguments.  The object is an implicit parameter
 * of the member function and is accessed via 'this->'
 */

// Default Constructor
ShoppingCart::ShoppingCart() {
	this->customerName = "none";
	this->currentDate = "January 1, 2016";
	return;
}

// Parameterized constructor which takes the customer name and date as parameters
ShoppingCart::ShoppingCart(string customerName, string currentDate) {
	this->customerName = customerName;
	this->currentDate = currentDate;
	return;
}

// Getters
string ShoppingCart::GetCustomerName() {
	return this->customerName;
}

string ShoppingCart::GetDate() {
	return this->currentDate;
}

// Add an item to cartItems vector
void ShoppingCart::AddItem(ItemToPurchase itemToPurchase) {
	cartItems.push_back(itemToPurchase);
	return;
}

void ShoppingCart::RemoveItem(string itemName) {
	// Case sensitivity removal via conversion to lower is beyond
	// the scope of this lab exercise
	for (unsigned int i = 0; i < cartItems.size(); ++i) {
		string cartItemName = cartItems.at(i).GetName();
		if (itemName == cartItemName) {
			cout << "FIXME: Match Found";
			break;
		}
		else {
			cout << "Item not found in cart. Nothing removed.";
		}
	}
}

void ShoppingCart::ModifyItem(ItemToPurchase itemToPurchase) {
	// FIXME: Add ModifyItem Logic
	cout << "FIXME: Add Modify Item Logic";
	return;
}

int ShoppingCart::GetNumItemsInCart() {
	return cartItems.size();
}

int ShoppingCart::GetCostOfCart() {
	int cartCost = 0;							// Local variable to store cart cost
	for (unsigned int i = 0; i < cartItems.size(); ++i) {
		cartCost += (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
	}
	return cartCost;
}

void ShoppingCart::PrintTotal() {
	cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
	if(GetNumItemsInCart() < 1) {
		cout << "SHOPPING CART IS EMPTY";
	}
	else {
		cout << "Number of items: " << GetNumItemsInCart() << endl;
		cout << endl;
		for (unsigned int i = 0; i < cartItems.size(); ++i) {
			cartItems.at(i).PrintItemCost();
		}
		cout << endl;
		cout << endl;
		cout << "Total: $" << GetCostOfCart();
	}
	return;
}

void ShoppingCart::PrintDescriptions() {
	cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
	cout << endl;
	cout << "Item Descriptions" << endl;
	for (unsigned int i = 0; i < cartItems.size(); ++i) {
		cartItems.at(i).PrintItemDescription();
	}
	cout << endl;
	return;
}
