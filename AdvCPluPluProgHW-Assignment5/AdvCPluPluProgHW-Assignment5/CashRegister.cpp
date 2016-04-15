// Implementation file for CashRegister
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "CashRegister.h"
using namespace std;

// Define a constructor that copies an array of InventoryItem objects to the internal array.
CashRegister::CashRegister(InventoryItem *i, int size)
{
	//Create an array of inventory items.
	inventory = new InventoryItem [size];

	// Copy the array passed as i to the new
	// inventory item array.
	for(int count = 0; count < size; count++)
		inventory[count] = i[count];
}

// Define function to allow user to select from list of items.

void CashRegister::makeChoice()
{
	cout << setw(5) << left << "#" << setw(20);
	cout << left << "Item" << setw(12);
	cout << left << "qty on Hand" << endl;
	cout << "---------------------------------------------------------------------------" << endl;

	for (int index = 0; index < 5; index++)
	{
		cout << setw(5) << left << (index+1);
		cout << setw(20) << inventory[index].getDescription();
		cout << setw(12) << inventory[index].getUnits() << endl;
	}

	cout << "Which item above is being purchased? " << endl << ">>>>>>>>    ";
	cin >> choice;
	while (choice <0 || choice > 5)
	{
		cout << "ERROR!!! THAT IS NOT A VALID SELECTION." << endl;
		cout << "Which item above is being purchased? " << endl << ">>>>>>>>    ";
		cin >> choice;
	}
	choice--;
}

// define findUnitPrice function

void CashRegister:: findUnitPrice()
{
	unitPrice = inventory[choice].getCost() * 1.3;
}

// define findSalesTax function

void CashRegister:: findSalesTax()
{
	tax = subTotal * 0.06;
}

// define findTotal function

void CashRegister::findTotal()
{
	total = subTotal + tax;
}

// define adjustUnits function

bool CashRegister::adjustUnits()
{
	int quantity = inventory[choice].getUnits();
	if (quantity >= qty)
	{
		inventory[choice].setUnits(quantity - qty);
		return true;
	}
	else
		return false;
}

// define makeSale function

void CashRegister::makeSale()
{
	//Display option list.
	makeChoice();

	// Obtain # of units.
	cout << "Please enter # of units." << endl << ">>>>>>   ";
	cin >> qty;

	// Input validation.
	while (qty < 0)
	{
		cout << "ERROR!! INPUT WAS NOT VALID!!" << endl << "Please enter # of units." << endl << ">>>>>>   ";
		cin >> qty;
	}

	// Determine price.
	findUnitPrice();

	// Determine subtotal.
	subTotal = qty * unitPrice;

	// Determine sales tax.
	findSalesTax();

	// Determine final total.
	findTotal();

	// Adjust units on hand.
	if (adjustUnits())
		displaySale();
	else
		cout << "I'm sorry. We don't have enough units in stock." << endl;
}


// Define displaySale function

void CashRegister::displaySale()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Subtotal:  $" << subTotal << endl;
	cout << "Sales Tax: $" << tax << endl;
	cout << "Total:     $" << total << endl;
}
