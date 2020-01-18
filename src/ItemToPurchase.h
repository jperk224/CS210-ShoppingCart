/*
 * Programmers typically put all code for a class into two files
 * The header file contains the class definition, including data
 * members and function declarations; function definitions are
 * written in the class.cpp file; any file that uses this class
 * must include the header file in which it is defined
 */

#include <string>				// Includes the class definition for built-in
								// string class

using namespace std;

#ifndef ITEMTOPURCHASE_H_
#define ITEMTOPURCHASE_H_

class ItemToPurchase {
	public:
		ItemToPurchase();					// Default Constructor
		void SetName(string itemName);
		void SetPrice(int itemPrice);
		void SetQuantity(int itemQuantity);
		string GetName();
		int GetPrice();
		int GetQuantity();
	private:
		string itemName;
		int itemPrice;						// Double is better for prices, but int
											// seems sufficient for this lab
		int itemQuantity;

};

#endif /* ITEMTOPURCHASE_H_ */
