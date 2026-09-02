
#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//part qilah ni patutnya ada header file and cpp file dia sendiri. later change
// BY NUR AQILAH SYAFIQAH
class InventoryItem {
public:
    string itemId;
    string ModelItem;
    string category;
    float price;
    int quantity;

    // Default Constructor
    InventoryItem() {
        itemId = "";
        ModelItem = "";
        category = "";
        price = 0.00;
        quantity = 0;
    }

    // Constructor parameter
    InventoryItem(string id, string model, string category, float p, int q) {
        itemId = id;
        ModelItem = model;
        this->category = category;
        price = p;
        quantity = q;
    }

    // berfungsi utk paparkan maklumat item
    void displayItem() const {
        cout << "----------------------------------------\n";
        cout << "Item ID   : " << itemId << endl;
        cout << "Model Item : " << ModelItem << endl;
        cout << "Category  : " << category << endl;
        cout << "Price     : " << fixed << setprecision(2) << price << endl;
        cout << "Quantity  : " << quantity << endl;
        cout << "----------------------------------------\n";
    }
};

#endif