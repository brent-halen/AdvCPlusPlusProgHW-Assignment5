#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <cstring>   // Needed for strlen and strcpy

// Constant for the description's default size
const int DEFAULT_SIZE = 51;

class InventoryItem
{
private:
   char *description;  // The item description
   double cost;        // The item cost
   int units;          // Number of units on hand
   
   // Private member function.
   void createDescription(int size, char *value)
      { // Allocate the default amount of memory for description.
        description = new char [size];
        
        // Store a value in the memory.
        strcpy_s(description, DEFAULT_SIZE, value); }

public:
   // Constructor #1
   InventoryItem()
      { // Store an empty string in the description
        // attribute.
        createDescription(DEFAULT_SIZE, "");
        
        // Initialize cost and units.
        cost = 0.0;
        units = 0; }

   // Constructor #2
   InventoryItem(char *desc)
      { // Allocate memory and store the description.
        createDescription(strnlen_s(desc, DEFAULT_SIZE), desc); 
        
        // Initialize cost and units.
        cost = 0.0;
        units = 0; }

   // Constructor #3
   InventoryItem(char *desc, double c, int u)
      { // Allocate memory and store the description.
		  createDescription(strnlen_s(desc, DEFAULT_SIZE), desc); 

        // Assign values to cost and units.
        cost = c;
        units = u; }      
        
   // Destructor
   ~InventoryItem()
      { delete [] description; }

   // Mutator functions
   void setDescription(char *d) 
	  { strcpy_s(description, DEFAULT_SIZE, d); }

   void setCost(double c)
      { cost = c; }
      
   void setUnits(int u)
      { units = u; }

   // Accessor functions
   const char *getDescription() const
      { return description; }
         
   double getCost() const
      { return cost; }

   int getUnits() const
      { return units; }
};

#endif