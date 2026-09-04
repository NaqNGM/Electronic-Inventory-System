//Main.cpp
// BY NUR AQILAH SYAFIQAH

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream> // file txt
#include "sort.h"
#include "search.h"
#include "checkStock.h"
using namespace std;

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

// berfungsi utk menambah item baru
void add() {
    string id, model, category;
    float price;
    int qty, MainMenu;

    do
    {
        //paparan menu untuk add new item
        cout << "-----------------------------------\n";
        cout << "            ADD NEW ITEM           \n";
        cout << "-----------------------------------\n";
        cout << "-----------------------------------\n";
        cout << "            ID TEMPLATE            \n";
        cout << "   Laptop: L**** || Phone: P****   \n";
        cout << "   TV: T****     || Scooter: S**** \n";
        cout << "           Cooker: C****           \n\n";
        cout << "1. Back to Main Menu" << endl;
        cout << "2. Proceed" << endl;

        cout << "Enter your number: ";
        cin >> MainMenu;

        if (cin.fail()) // pastikan pilihan menu nombor yang betul
        {
            cin.clear(); // clear error
            cin.ignore(1000, '\n'); // clear invalid input
            cout << "\nInvalid input! Please enter a number.\n\n";
            system("pause");
            system("cls");
            continue;
        }

        if (MainMenu == 2)
        {
            // 1. Validation untuk ID (1 Huruf dan 4 Digit)
            bool invalidId;
            do {
                invalidId = false;
                cout << "Enter Item ID: ";
                cin >> id;
                id = toUpper(id);

                //Validate id kene ada 5 char : 1 huruf + 4 nombor
                if (id.length() != 5 || id[0] < 'A' || id[0] > 'Z') {
                    invalidId = true;
                }
                else {
                    for (int i = 1; i < 5; i++) {
                        if (id[i] < '0' || id[i] > '9') {
                            invalidId = true;
                            break;
                        }
                    }
                }

                if (invalidId) {
                    cout << "\nError: Invalid format! Must be 1 Letter and 4 Numbers (e.g., P1001).\n\n";
                    continue; // Skip the duplicate check and restart the loop
                }

                // 2. Loop through existing inventory to see if ID matches
                for (int i = 0; i < itemCount; i++) {
                    if (inventoryList[i].itemId == id) {
                        invalidId = true;
                        cout << "\nError: Item ID '" << id << "' already exists!\n";
                        cout << "Please enter a unique ID.\n\n";
                        break; // Break the for-loop, repeat the do-while loop
                    }
                }
            } while (invalidId);

            // 2. Validation untuk model item 
            cout << "Enter Model Item: ";
            cin.ignore();
            getline(cin, model);

            // ganti ' ' dengan '-'
            for (int i = 0; i < model.length(); i++) {
                if (model[i] == ' ') {
                    model[i] = '-';
                }
            }
            //uppercase input
            model = toUpper(model);

            // 3. Validation untuk Category Laptop, Phone, TV, Scooter atau Cooker sahaja
            bool validCategory;
            do {
                cout << "Enter Category (PHONE, LAPTOP, TV, SCOOTER, or COOKER): ";
                getline(cin, category);
                category = toUpper(category);

                if (category == "PHONE" || category == "LAPTOP" ||
                    category == "TV" || category == "SCOOTER" ||
                    category == "COOKER") {
                    validCategory = true;
                }
                else {
                    validCategory = false;
                    cout << "\nError: Invalid category! Please enter one of the specified options.\n\n";
                }
            } while (!validCategory);

            //4. Validation untuk Price
            bool validPrice;
            do {
                validPrice = true;
                cout << "Enter Price (RM): ";
                cin >> price;

                //untuk pastikan price ialah nombor dan lebih dari 0
                if (cin.fail() || price <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    validPrice = false;
                    cout << ">> Error: Price must be a valid number only and greater than 0.\n\n";
                }
            } while (!validPrice);

            // 5. Validation untuk Quantity 
            bool validQty;
            do {
                validQty = true;
                cout << "Enter Quantity: ";
                cin >> qty;

                //untuk pastikan kuantiti ialah nombor dan lebih dari 0
                if (cin.fail() || qty <= 0) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    validQty = false;
                    cout << ">> Error: Quantity must be a valid number only and greater than 0.\n\n";
                }
            } while (!validQty);

            //simpan ke dalam array
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
        else if (MainMenu == 1)
        {
            system("cls");
            return;
        }
        else
        {
            cout << "\nInvalid Number!!! Try again.\n\n" << endl;
            system("pause");
            system("cls");
        }

    } while (true);

}

//function untuk display device
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
        if (toUpper(inventoryList[i].category) == "LAPTOP") {
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
        if (toUpper(inventoryList[i].category) == "TV") {
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
        if (toUpper(inventoryList[i].category) == "SCOOTER") {
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
        if (toUpper(inventoryList[i].category) == "COOKER") {
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

    system("cls");

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
        cout << "5. Check Stock\n";
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
            SearchingChoices(inventoryList, itemCount);
            break;
        case 5:
            extraFunction();
            break;
        case 6:
            cout << "Exit.\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            system("pause");
            system("cls");
        }
    } while (choice != 6);

    return 0;
}
