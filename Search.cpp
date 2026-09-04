#include "search.h"
#include "sort.h"
#include <iostream>
#include <string>

using namespace std;

//BY NAQIU
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

//BY NAQIU
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

    targetId = toUpper(targetId);

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

//BY ULFAH
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

//BY ULFAH
void ProbabilityItem(InventoryItem array[], int count)
{
    if (count == 0)     //TO DETECT IF THERE IS STOCK IN THE ARRAY
    {
        cout << "Inventory is empty. Nothing to search.\n";
        system("pause");
        system("cls");
        return;
    }

    string TargetModel;

    cout << "\n-----------------------------------\n";
    cout << "        SEARCH ITEM BY MODEL           ";
    cout << "\n-----------------------------------\n";
    cout << "Enter Item Model to search: ";
    cin.ignore();           //IGNORE SPACE
    getline(cin, TargetModel);

    for (int i = 0; i < TargetModel.length(); i++) {
        if (TargetModel[i] == ' ') {
            TargetModel[i] = '-';
        }
    }

    TargetModel = toUpper(TargetModel);

    int index = ProbabilitySearchByModel(array, count, TargetModel);       //INDEX IN THE ARRAY

    cout << "\nSearch Result:\n";
    if (index != -1)
    {
        array[index].displayItem();     //DISPLAY OUTPUT THAT HAS BEEN SEARCHED
    }
    else        //IF THE ITEM NOT FOUND
    {
        cout << "Item with Model '" << TargetModel << "' was not found.\n";
    }

    system("pause");
    system("cls");
}

//BY ULFAH
void SearchingChoices(InventoryItem arr[], int count)    //TO CHOOSE WHICH CHOICES USER WANT TO USE FOR SEARCHING
{
    int searchingChoice;

    do
    {
        cout << "\n-----------------------------------\n";
        cout << "           SEARCHING MENU            \n";
        cout << "-----------------------------------\n";
        cout << "1. Searching by Item ID\n";
        cout << "2. Searching by Model Name\n";
        cout << "3. Back to Main Menu\n";
        cout << "\nEnter your choice: ";
        cin >> searchingChoice;

        if (cin.fail()) {
            cin.clear();                // CLEAR ERROR
            cin.ignore(1000, '\n');     // CLEAR INVALID INPUT
            cout << "\nInvalid input! Please enter a number.\n\n";
            system("pause");
            system("cls");
            continue;
        }

        if (searchingChoice == 1)       //FIRST CHOICE TO SEARCH BY ITEM ID
        {
            searchItem(arr, count);
            break;
        }
        else if (searchingChoice == 2)  //SECOND CHOICE TO SEARCH BY MODEL NAME
        {
            ProbabilityItem(arr, count);
            break;
        }
        else if (searchingChoice == 3)   //TO BACK TO MAIN MENU
        {
            system("cls");
            return;
        }
        else
        {
            cout << "\nInvalid choice.\n\n";    //ANY CHOICE THAT DIFFERENT FROM THE CHOICES GIVEN
            system("pause");
            system("cls");
        }

    } while (true);     //LOOP IF THE CHOICE IS FALSE

}
