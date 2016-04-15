// AdvCPluPluProgHW-Assignment5.cpp : Defines the entry point for the console application.
// Assignment 5.cpp : Defines the entry point for the console application.
// WARNING: To get this code to compile, you must add "_CRT_SECURE_NO_WARNINGS;%(PreprocessorDefinitions)" to Preprocessor Definitions.
// Right-click on 'Assignment 5' project, click 'Properties'. Follow & Expand to "Configuration Properties" -> "C/C++" -> "Preporcessor" -> "Preprocessor Definitions"

#include "stdafx.h"
#include <cctype>
#include <iostream>
#include "CashRegister.h"
using namespace std;
// Declare # of inventory items.
const int INVENTORYCOUNT = 5;


int main()
{
	
	InventoryItem inventory[INVENTORYCOUNT] = {
		InventoryItem("Human Foot", 83.0, 12),
		InventoryItem("Human Eye", 32.4, 11),
		InventoryItem("Eye of Newt", 12.2, 32),
		InventoryItem("Unknown Heart", 55.12, 3),
		InventoryItem("Kidney", 47.32, 55) };

	CashRegister reg(inventory, INVENTORYCOUNT);
	char again = 'y';
	

	do
	{
			reg.makeSale();
			cout << endl << "Would you like to buy something else?" << endl << "Enter \"N\" if you are finished." << endl << ">>>>>>  ";
			cin >> again;
	}while (tolower(again) !='n');
		


}