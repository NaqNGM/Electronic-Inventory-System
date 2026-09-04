//sort.cpp

#include "Sort.h"
#include <iostream>
#include <string>

using namespace std;

// BY ALIA NAJWA
int splitArrayPrice(InventoryItem arr[], int low, int high) {
    float pivot = arr[low].price; // set leftmost data as pivot
    int left = low + 1;
    int right = high;

    while (true) {
        // traverse from right to find value smaller than pivot
        while (left <= right && arr[right].price >= pivot) {
            right--;
        }

        // traverse from left to find value larger than pivot
        while (left <= right && arr[left].price <= pivot) {
            left++;
        }

        // kalu pointers cross, traverse end
        if (left > right) {
            break;
        }
        else {
            // swap 2 values
            InventoryItem temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // swap pivot value dgn last value of smaller side
    InventoryItem temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    return right;
}

int splitArrayId(InventoryItem arr[], int low, int high) {
    string pivot = arr[low].itemId; // set leftmost data as pivot
    int left = low + 1;
    int right = high;

    while (true) {
        // traverse from right to find value smaller than pivot
        while (left <= right && arr[right].itemId >= pivot) {
            right--;
        }

        // traverse from left to find value larger than pivot
        while (left <= right && arr[left].itemId <= pivot) {
            left++;
        }

        // pointers cross, traverse end
        if (left > right) {
            break;
        }
        else {
            // swap 2 values
            InventoryItem temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // swap pivot value dgn last value of smaller side
    InventoryItem temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    return right;
}

int splitArrayModel(InventoryItem arr[], int low, int high) {
    string pivot = arr[low].ModelItem; // set leftmost data as pivot
    int left = low + 1;
    int right = high;

    while (true) {
        // taverse from right to find value smaller than pivot
        while (left <= right && arr[right].ModelItem >= pivot) {
            right--;
        }

        // traverse from left to find value larger than pivot
        while (left <= right && arr[left].ModelItem <= pivot) {
            left++;
        }

        // pointers cross, traverse end
        if (left > right) {
            break;
        }
        else {
            // swap 2 values
            InventoryItem temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // swap pivot value dgn last value of smaller side
    InventoryItem temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    return right;
}

void quickSortPrice(InventoryItem arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = splitArrayPrice(arr, low, high);

        // repeat on both side
        quickSortPrice(arr, low, pivotIndex - 1);
        quickSortPrice(arr, pivotIndex + 1, high);
    }
}

void quickSortId(InventoryItem arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = splitArrayId(arr, low, high);

        // repeat on both side
        quickSortId(arr, low, pivotIndex - 1);
        quickSortId(arr, pivotIndex + 1, high);
    }
}

void quickSortModel(InventoryItem arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = splitArrayModel(arr, low, high);

        // repeat on both side
        quickSortModel(arr, low, pivotIndex - 1);
        quickSortModel(arr, pivotIndex + 1, high);
    }
}

void sortItem(InventoryItem arr[], int count) {
    if (count == 0) {
        cout << "Inventory is empty. Nothing to sort.\n";
        system("pause");
        system("cls");
        return;
    }

    int sortChoice;

    do {
        system("cls");
        cout << "\n-----------------------------------\n";
        cout << "           SORTING MENU            \n";
        cout << "-----------------------------------\n";
        cout << "1. Sort by Price (Ascending)\n";
        cout << "2. Sort by Item ID (Alphabetical)\n";
        cout << "3. Sort by Model Name (Alphabetical)\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> sortChoice;

        // if user masukkan selain nombor
        if (cin.fail()) {
            cin.clear(); // clear error
            cin.ignore(1000, '\n'); // clear invalid input
            cout << "\nInvalid input! Please enter a number.\n\n";
            system("pause");
            continue;
        }

        if (sortChoice == 1) {
            quickSortPrice(arr, 0, count - 1);
            cout << "\nItems successfully sorted by Price (Ascending)\n";
            break;
        }
        else if (sortChoice == 2) {
            quickSortId(arr, 0, count - 1);
            cout << "\nItems successfully sorted by Item ID (Alphabetical)\n";
            break;
        }
        else if (sortChoice == 3) {
            quickSortModel(arr, 0, count - 1);
            cout << "\nItems successfully sorted by Model Name (Alphabetical)\n";
            break;
        }
        else if (sortChoice == 4) {
            system("cls");
            return;
        }
        else {
            cout << "\nInvalid choice. Please try again.\n\n";
            system("pause");
        }
    } while (true);

    cout << "-----------------------------------\n";

    // display sorted list
    for (int i = 0; i < count; i++) {
        arr[i].displayItem();
    }

    system("pause");
    system("cls");
}
