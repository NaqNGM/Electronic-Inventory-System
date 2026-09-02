//Main.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream> // file txt
#include "sort.h"
#include "search.h"
using namespace std;

// part qilah ni nnti kena ada cpp dia sendiri. later change
InventoryItem inventoryList[100];
int itemCount = 0;

//qiuqiu
// toUpper buat dia tak kisah user taip PHONE, Phone, atau phone
string toUpper(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
// BY NUR AQILAH SYAFIQAH
// berfungsi utk menambah item baru
void add() {
    string id, model, category;
    float price;
    int qty;


    cout << "-----------------------------------\n";
    cout << "            ADD NEW ITEM           \n";
    cout << "-----------------------------------\n";
    cout << "-----------------------------------\n";
    cout << "            ID TEMPLATE            \n";
    cout << "   Laptop: L**** || Phone: P****   \n";
    cout << "   TV: T****     || Scooter: S**** \n";
    cout << "           Cooker: C****           \n\n";
    cout << "Enter Item ID: ";
    cin >> id;
    cout << "Enter Model Item: ";
    cin.ignore();
    getline(cin, model);
    cout << "Enter Category : ";
    getline(cin, category);
    cout << "Enter Price (RM): ";
    cin >> price;
    do
    {
        cout << "Enter Quantity: ";
        cin >> qty;
        if (qty <= 0)
        {
            cout << "\nTHE QUANTITY IS INVALID\n\n";
        }
    } while (qty <= 0);
    cout << "-----------------------------------\n";
    inventoryList[itemCount] = InventoryItem(id, model, category, price, qty);
    itemCount++;
    cout << "Success! Item added successfully .\n";
    cout << "-----------------------------------\n";

    system("pause");
    system("cls");

    ofstream outFile("inputfile.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << id << " " << model << " " << category << " "
            << fixed << setprecision(2) << price << " " << qty << "\n";
        outFile.close();
    }
}

//function untuk divices 
void displayPhone() {
    cout << "\n----------------------------\n";
    cout << "            PHONE             \n";
    cout << "------------------------------\n";
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (toUpper(inventoryList[i].category) == "PHONE") {
            cout << " Model : " << inventoryList[i].ModelItem
                << " | Price : RM " << fixed << setprecision(2) << inventoryList[i].price
                << " | Quantity : " << inventoryList[i].quantity << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Phone item unavailable.\n";
    }
    cout << "-----------------------------------\n";
    system("pause");
    system("cls");
}

void displayLaptop() {
    cout << "\n-----------------------------\n";
    cout << "           LAPTOP             \n";
    cout << "------------------------------\n";
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (toUpper(inventoryList[i].category) == "PHONE") {
            cout << " Model : " << inventoryList[i].ModelItem
                << " | Price : RM " << fixed << setprecision(2) << inventoryList[i].price
                << " | Quantity : " << inventoryList[i].quantity << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No laptop item available.\n";
    }
    cout << "-----------------------------------\n";
    system("pause");
    system("cls");
}


void displayTV() {
    cout << "\n---------------------------------\n";
    cout << "\n              TV                 \n";
    cout << "-----------------------------------\n";
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (toUpper(inventoryList[i].category) == "PHONE") {
            cout << " Model : " << inventoryList[i].ModelItem
                << " | Price : RM " << fixed << setprecision(2) << inventoryList[i].price
                << " | Quantity : " << inventoryList[i].quantity << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No TV iteam available.\n";
    }
    cout << "-----------------------------------\n";
    system("pause");
    system("cls");
}

void displayScooter() {
    cout << "\n---------------------------------\n";
    cout << "              SCOOTER              \n";
    cout << "-----------------------------------\n";
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (toUpper(inventoryList[i].category) == "PHONE") {
            cout << " Model : " << inventoryList[i].ModelItem
                << " | Price : RM " << fixed << setprecision(2) << inventoryList[i].price
                << " | Quantity : " << inventoryList[i].quantity << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No scooter iteam available.\n";
    }
    cout << "-----------------------------------\n";
    system("pause");
    system("cls");
}

void displayCooker() {
    cout << "\n---------------------------------\n";
    cout << "              COOKER               \n";
    cout << "-----------------------------------\n";
    bool found = false;
    for (int i = 0; i < itemCount; i++) {
        if (toUpper(inventoryList[i].category) == "PHONE") {
            cout << " Model : " << inventoryList[i].ModelItem
                << " | Price : RM " << fixed << setprecision(2) << inventoryList[i].price
                << " | Quantity : " << inventoryList[i].quantity << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No cooker item available.\n";
    }
    cout << "-----------------------------------\n";
    system("pause");
    system("cls");
}

//category untuk switch case 
void CategoryMenu() {
    int categoryChoice;

    cout << "\n----------------------------------\n";
    cout << "         SELECT CATEGORY            \n";
    cout << "------------------------------------\n";
    cout << "1. PHONE\n";
    cout << "2. LAPTOP\n";
    cout << "3. TV\n";
    cout << "4. SCOOTER\n";
    cout << "5. COOKER\n";
    cout << "-----------------------------------\n";
    cout << "Enter your choice: ";
    cin >> categoryChoice;

    switch (categoryChoice) {
    case 1:
        displayPhone();
        break;
    case 2:
        displayLaptop();
        break;
    case 3:
        displayTV();
        break;
    case 4:
        displayScooter();
        break;
    case 5:
        displayCooker();
        break;
    default:
        cout << "\nInvalid category choice!\n";
    }
}

void extraFunction() {
    cout << "\nEXTRA\n";
}

// BY AQILAH 
int main() { // SUPPOSEDLY THIS SHOULD BE MAIN.CPP START FROM HERE
    ifstream inFile("inputfile.txt");

    if (!inFile.is_open()) {
        cout << "Error: Cannot open input file!\n";
        return 1;
    }

    string id, model, category;
    float price;
    int qty;

    // Operator >> automatik skip spaces dan baca ikut turutan
    while (inFile >> id >> model >> category >> price >> qty) {
        if (itemCount < 100) {
            inventoryList[itemCount] = InventoryItem(id, model, category, price, qty);
            itemCount++;
        }
    }

    inFile.close();

    int choice;

    do {
        cout << "\n---- INVENTORY SYSTEM MENU ----\n";
        cout << "1. Add Item\n";
        cout << "2. Category Menu\n";
        cout << "3. Sort Items\n";
        cout << "4. Search Items\n";
        cout << "5. Extra Function\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            add();
            break;
        case 2:
            CategoryMenu();
            break;
        case 3:
            sortItem(inventoryList, itemCount);
            break;
        case 4:
            searchItem(inventoryList, itemCount);
            break;
        case 5:
            extraFunction();
            break;
        case 6:
            cout << "Exit.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
