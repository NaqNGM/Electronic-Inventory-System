#include "search.h"
#include "sort.h"
#include <iostream>
#include <string>

using namespace std;

int binarySearchById(InventoryItem arr[], int count, const string& targetId) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        // Prevents potential overflow compared to (low + high) / 2
        int mid = low + (high - low) / 2;

        if (arr[mid].itemId == targetId) {
            return mid; // Target found
        }
        else if (targetId < arr[mid].itemId) {
            high = mid - 1; // Discard right half
        }
        else {
            low = mid + 1;  // Discard left half
        }
    }

    return -1; // Not found
}

void searchItem(InventoryItem arr[], int count) {
    if (count == 0) {
        cout << "Inventory is empty. Nothing to search.\n";
        system("pause");
        return;
    }

    string targetId;
    cout << "\n-----------------------------------\n";
    cout << "        SEARCH ITEM BY ID          \n";
    cout << "-----------------------------------\n";
    cout << "Enter Item ID to search: ";
    cin >> targetId;

    // Prerequisite: Array MUST be sorted by itemId for binary search
    // If using Alia's specific function:
    quickSortId(arr, 0, count - 1);
    // (Or if using the unified function: quickSort(arr, 0, count - 1, 2);)

    int index = binarySearchById(arr, count, targetId);

    cout << "\nSearch Result:\n";
    if (index != -1) {
        arr[index].displayItem();
    }
    else {
        cout << "Item with ID '" << targetId << "' was not found.\n";
    }

    system("pause");
}