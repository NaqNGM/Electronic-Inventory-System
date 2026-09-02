#ifndef SEARCH_H
#define SEARCH_H

#include "InventoryItem.h"

// Returns the index of the found item, or -1 if not found
int binarySearchById(InventoryItem arr[], int count, const std::string& targetId);

// UI function
void searchItem(InventoryItem arr[], int count);

#endif
