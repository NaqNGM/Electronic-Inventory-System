//checkStock.cpp
//made by Anis Athirah

#include <iostream>
#include <fstream>
#include <string>
#include "checkStock.h"

using namespace std;

void extraFunction()
{
	//declared variables
	string highestProduct, ModelItem, highestID, itemID, category, highestCategory;
	int quantity, answer;
	float price;

	//initialized value variables
	int stock = 0;
	int lowestStock = 0;
	int highestStock = 0;
	int findLowest = 0;

	//baca dari file inputfile.txt yg sedia ada
	ifstream file("inputfile.txt");

	//bagi guidance cara baca data yg ada dlm file.txt
	file >> itemID >> ModelItem >> category >> price >> stock;

	//special variable for highest
	highestID = itemID;
	highestProduct = ModelItem;
	highestCategory = category;
	highestStock = stock;

	while (file >> itemID >> ModelItem >> category >> price >> stock)
	{
		//cara utk cari highestStock dan identify data2 nya yg berkaitan
		if (stock > highestStock)
		{
			highestID = itemID;
			highestProduct = ModelItem;
			highestCategory = category;
			highestStock = stock;

		}
	}

	do   //akan repeat dan bagi chance kalau input tak betul
	{
		cout << "-----------------------" << endl;
		cout << "      CHECK STOCK" << endl;
		cout << "-----------------------" << endl;
		cout << "1. To back to main menu" << endl;
		cout << "2. To check stock" << endl;
		cout << "Enter your choice: ";
		cin >> answer;

		//error handling kalau user masukkan alphabet
		if (cin.fail())
		{
			cin.clear(); // clear error
			cin.ignore(1000, '\n'); // clear invalid input
			cout << "\nInvalid input! Please enter a number.\n" << endl;
			system("pause");
			system("cls");
			continue;
		}

		if (answer == 1)     //back to main menu
		{
			system("cls");
			return;
		}

		else if (answer == 2)
		{
			system("cls");

			do   //akan repeat and bagi chance kalau input tak betul
			{
				cout << "Enter minimum stock: ";
				cin >> findLowest;

				if (cin.fail())    //error handling if user masukkan alphabet
				{
					cin.clear(); // clear error
					cin.ignore(1000, '\n'); // clear invalid input
					cout << "\nInvalid input! Please enter a number.\n";
					cout << endl;
					system("pause");
					system("cls");
					continue;
				}

				if (findLowest <= 0)     //error handling if user masukkan 0 / -ve
				{
					cout << "\nInvalid number!!! Try again." << endl;
					cout << endl;
					system("pause");
					system("cls");
				}

				else
				{
					file.clear();   //utk clear kan bacaan file and baca semula from start
					file.seekg(0, ios::beg);

					bool found = false;   //mula2 set data false (sbb tak jumpa lagi

					cout << endl;
					cout << "Product with LOW STOCK: " << endl;

					while (file >> itemID >> ModelItem >> category >> price >> quantity)
					{
						if (quantity < findLowest)
						{
							cout << itemID << " | " << ModelItem << " | " << category << " | " << " -> " << quantity << endl;
							found = true;     //kalau dah betu baru ambil data
						}
					}

					if (!found)   //if takde pun lowestStock seperti yg diminta user
					{
						cout << "There is no item under " << findLowest << " stocks !!!" << endl;
					}

					file.close();     //tutup bacaan file.txt

					cout << endl;

					cout << "Product with the HIGHEST STOCK: " << endl;
					cout << highestID << " | " << highestCategory << " | " << highestProduct << " -> " << highestStock << endl;
					cout << endl;

					system("pause");
					system("cls");
					return;

				}

			} while (true);    //maksudnya required input dah betul baru stop
		}

		else
		{
			cout << "\nPlease enter valid input! Try again." << endl;
			cout << endl;
			system("pause");
			system("cls");
		}

	} while (true);     //maksudnya required input dah betul baru stop
}
