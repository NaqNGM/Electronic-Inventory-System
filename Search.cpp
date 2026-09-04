#include "search.h"
#include "sort.h"
#include <iostream>
#include <string>

using namespace std;

int binarySearchById(InventoryItem arr[], int count, const string& targetId) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
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

    //Array MUST be sorted by itemId for binary search
    quickSortId(arr, 0, count - 1);


    int index = binarySearchById(arr, count, targetId);

    cout << "\nSearch Result:\n";
    if (index != -1) {
        arr[index].displayItem();
    }
    else {
        cout << "Item with ID '" << targetId << "' was not found.\n";
    }

    system("pause");
    system("cls");
}

int ProbabilitySearchByModel(InventoryItem array[], int count, const string& TargetModel)
{
    int index = 0;
    InventoryItem temp;

    while (index < count)
    {
        if (array[index].ModelItem != TargetModel)
        {
            index++;
        }
        else
        {
            if (index != 0)
            {
                temp = array[index - 1];
                array[index - 1] = array[index];
                array[index] = temp;

                return index - 1;
            }
            return index;
        }
    }
    return -1;
}

void ProbabilityItem(InventoryItem array[], int count)
{
    if (count == 0)
    {
        cout << "Inventory is empty. Nothing to search.\n";
        system("pause");
        return;
    }

    string TargetModel;

    cout << "\n-----------------------------------\n";
    cout << "        SEARCH ITEM BY MODEL          \n";
    cout << "-----------------------------------\n";
    cout << "Enter Item Model to search: ";
    cin.ignore();
    getline(cin, TargetModel);

    int index = ProbabilitySearchByModel(array, count, TargetModel);

    cout << "\nSearch Result:\n";
    if (index != -1) {
        array[index].displayItem();
    }
    else {
        cout << "Item with Model '" << TargetModel << "' was not found.\n";
    }

    system("pause");
    system("cls");
}

void SearchingChoices(InventoryItem arr[], InventoryItem array[], int count)
{
    int searchingChoice;

    do
    {
        cout << "\n-----------------------------------\n";
        cout << "           SEARCHING MENU            \n";
        cout << "-----------------------------------\n";
        cout << "1. Searching by Item ID\n";
        cout << "2. Searching by Model Name\n";
        cout << "0. BACK TO MAIN MENU\n";
        cout << "\nEnter your choice: ";
        cin >> searchingChoice;

        if (cin.fail()) {
            cin.clear(); // clear error
            cin.ignore(1000, '\n'); // clear invalid input
            cout << "\nInvalid input! Please enter a number.\n\n";
            system("pause");
            system("cls");
            continue;
        }

        if (searchingChoice == 1)
        {
            searchItem(arr, count);
            break;
        }
        else if (searchingChoice == 2)
        {
            ProbabilityItem(array, count);
            break;
        }
        else if (searchingChoice == 0)
        {
            system("cls");
            return;
        }
        else
        {
            cout << "\nInvalid choice.\n\n";
            system("pause");
            system("cls");
        }

    } while (true);

}
