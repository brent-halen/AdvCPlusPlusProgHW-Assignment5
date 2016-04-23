#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include "stdafx.h"
//#include <cstring>   // Needed for strlen and strcpy
#include <string>
using namespace std;

// Constant for the description's default size
//const int DEFAULT_SIZE = 51;
//
//class InventoryItem
//{
//private:
//   char description[32];  // The item description
//   double cost;        // The item cost
//   int units;          // Number of units on hand
   
class InventoryItem
{
private:
	string description; // Item Description
	double cost; // Item cost
	int units; // # of units on hand

   // Private member function.
   
public:
   //// Constructor #1
   //InventoryItem()
   //   { // Store an empty string in the description
   //     // attribute.
   //     strcpy(description, "");
   //     
   //     // Initialize cost and units.
   //     cost = 0.0;
   //     units = 0; }

   //// Constructor #2
   //InventoryItem(char *desc)
   //   { // Allocate memory and store the description.
   //     strcpy(description,desc);
   //     
   //     // Initialize cost and units.
   //     cost = 0.0;
   //     units = 0; }

   //// Constructor #3
   //InventoryItem(char *desc, double c, int u)
   //   { // Allocate memory and store the description.
		 // strcpy(description,desc);

   //     // Assign values to cost and units.
   //     cost = c;
   //     units = u; }      
   //     
   //InventoryItem(const InventoryItem &i)
   //{
	  // strcpy(description, i.description);
	  // cost = i.cost;
	  // units = i.units;
   //}
   //
   //// Destructor
   //~InventoryItem()
   //   { delete [] description; }

	// Constructor #1
	InventoryItem()
	{ description = ""; cost = 0.0; units = 0; }

	//Constructor 2
	InventoryItem(string desc)
	{ description = desc; cost = 0.0; units = 0; }

	// Constructor 3
	InventoryItem(string desc, double c, int u)
	{ description = desc; cost = c; units = u; }


   // Mutator functions
   /*void setDescription(char *d) 
	  { strcpy(description, d); }*/
	void setDescription(string d)
	{ description = d; }

   void setCost(double c)
      { cost = c; }
      
   void setUnits(int u)
      { units = u; }

   // Accessor functions
   /*const char *getDescription() 
      { return description; }*/
     
   const string getDescription() const
	   { return description; }

   double getCost() const
      { return cost; }

   int getUnits() const
      { return units; }
};

#endif