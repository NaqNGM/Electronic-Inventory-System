//sort.h

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <string>
#include <iomanip>
#include "InventoryItem.h"
using namespace std;


// by alia najwas
int splitArrayPrice(InventoryItem arr[], int low, int high);
int splitArrayId(InventoryItem arr[], int low, int high);
int splitArrayModel(InventoryItem arr[], int low, int high);

void quickSortPrice(InventoryItem arr[], int low, int high);
void quickSortId(InventoryItem arr[], int low, int high);
void quickSortModel(InventoryItem arr[], int low, int high);

void sortItem(InventoryItem arr[], int count);

#endif