#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct Shoe {
    string name;
    string brand;
    long int price;
    int quantity;
};

void search(const Shoe shoes[], int numShoes, string brandToSearch) {
    bool brandFound = false;

    cout << "Searching for shoes with brand: " << brandToSearch << endl;

    for (int i = 0; i < numShoes; i++) {
        if (shoes[i].brand < brandToSearch) {
            cout << "Name: " << shoes[i].name << endl;
            cout << "Brand: " << shoes[i].brand << endl;
            cout << "Price: " << shoes[i].price << endl;
            cout << "Quantity: " << shoes[i].quantity << endl;
            cout << endl;
            brandFound = true;
        }
    }

    if (!brandFound) {
        cout << "No shoes with the brand " << brandToSearch << " found." << endl;
    }
}

void displayMenu() {
    cout << "========== Shoe Store ==========" << endl;
    cout << "1. View Shoes" << endl;
    cout << "2. Search Shoes" << endl;
    cout << "3. View Cart" << endl;
    cout << "4. Checkout" << endl;
    cout << "5. Exit" << endl;
}

void displayShoes(const Shoe shoes[], int numShoes) {
    cout << "Available Shoes:" << endl;
    cout << setw(20) << "Name" << setw(20) << "Brand" << setw(10) << "Price" << setw(10) << "Quantity" << endl;

    for (int i = 0; i < numShoes; i++) {
        cout << setw(20) << shoes[i].name << setw(20) << shoes[i].brand << setw(10) << shoes[i].price << setw(10) << shoes[i].quantity << endl;
    }
}

int main () {
    int opsi;
    const int maxShoes = 4; // Define the maximum number of shoes
    Shoe shoes[maxShoes];
    string brandToSearch;

    // Assign data to the Shoe structures
    shoes[0] = { "Sneaker Model 1", "Nike", 100000, 10 };
    shoes[1] = { "Running Shoes", "Adidas", 200000, 15 };
    shoes[2] = { "Casual Shoes", "Puma", 300000, 8 };
    shoes[3] = { "Sneaker Model 2", "Nike", 222, 10 };
    
    displayMenu();
    cin>>opsi;

    while (true) {
        if(opsi == 1){
            displayShoes(shoes, maxShoes);
            cout << "Choose your shoes" << endl;
            cin >> 
        }
        else if (opsi == 2){
            cout << "Enter the brand to search: ";
            cin.ignore();
            getline(cin, brandToSearch);

            search(shoes, maxShoes, brandToSearch);
        }
        else if (opsi == 3) {
            break;
        }
        else{
            cout << "ERROR!!" << endl;
        }
    }
}