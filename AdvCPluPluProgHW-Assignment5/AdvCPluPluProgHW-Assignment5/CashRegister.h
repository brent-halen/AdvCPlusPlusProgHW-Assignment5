#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "stdafx.h"
#include "InventoryItem.h"

class CashRegister
{
private:
	// Private member variables
	InventoryItem *inventory;
	int choice;
	int qty; 
	double unitPrice;
	double subTotal;
	double tax;
	double total;

	// Private member functions
	void findUnitPrice();
	void findSalesTax();
	void findTotal();
	bool adjustUnits();
	void makeChoice();

public:
	// Constructor 
	CashRegister(InventoryItem*, int);

	// Other public functions
	void makeSale();
	void displaySale();
};

#endif