#include <iostream>
#include <vector>
#include <stdexcept>	// Library needed to generate runtim_error objects
						// for exception handling
#include <string>		// Includes the class definition for built-in
						// string class
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

// Implement the PrintMenu() function. PrintMenu() has a ShoppingCart parameter
// and outputs a menu of options to manipulate the shopping cart.
// Each option is represented by a single character

void PrintMenu(/*Add Shopping Cart Parameter*/) {
	string displayMenu = 	"MENU\na - Add item to cart\nd - Remove item from cart\n"
							"c - Change item quantity\ni - Output items' descriptions\n"
							"o - Output shopping cart\nq - Quit\n\nChoose an option: ";
	char userInput;
	bool validEntry;		// flag to drive exception handling

	while (userInput != 'q') {
		do {
			validEntry = true;
			try {
				cout << displayMenu;
				cin >> userInput;
				userInput = tolower(userInput);
				if ((userInput != 'a') && (userInput != 'd') && (userInput != 'c')
						&& (userInput != 'i') && (userInput != 'o') && (userInput != 'q')) {
					throw runtime_error("Invalid selection.");
				}

				if (userInput == 'a') {
					cout << "FIXME: add item to cart" << endl;
				}
				else if (userInput == 'd') {
					cout << "FIXME: Remove item from cart." << endl;
				}
				else if (userInput == 'c') {
					cout << "FIXME: Change item quantity" << endl;
				}
				else if (userInput == 'i') {
					cout << "FIXME: Output items' descriptions" << endl;
				}
				else if (userInput == 'o') {
					cout << "FIXME: Output shopping cart" << endl;
				}
				else {
					continue;
				}
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl;
				validEntry = false;
			}
		} while(!validEntry);
	}

	cout << "QUIT";

	return;
}

int main() {

	PrintMenu();
	return 0;
}


