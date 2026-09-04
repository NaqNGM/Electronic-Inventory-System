//Search.h
#ifndef SEARCH_H
#define SEARCH_H

#include "InventoryItem.h"

// Returns the index of the found item, or -1 if not found
int binarySearchById(InventoryItem arr[], int count, const std::string& targetId);

// UI function
void searchItem(InventoryItem arr[], int count);

int ProbabilitySearchByModel(InventoryItem array[], int count, const string& TargetModel);

void ProbabilityItem(InventoryItem array[], int count);

void SearchingChoices(InventoryItem arr[], int count);

#endif
