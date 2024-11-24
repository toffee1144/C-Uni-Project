#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int cartNumber[1000];
int cartQuantity[1000];
int x = 0;

string shoesName[] = {"A", "B", "C", "D", "E"};
string brand[] = {"G", "H", "I", "J", "K"};
long int shoesPrice[] = {100000, 200000, 300000, 400000, 500000};

void displayShoes() {
    cout << "Available Shoes:" << endl<< endl;
    cout << setw(2) << "No." << setw(20) << "Name" << setw(20) << "Brand" << setw(10) << "Price" << endl;

    for (int i = 0; i < 5; i++) {
        cout << setw(2) << i + 1 << setw(20) << shoesName[i] << setw(20) << brand[i] << setw(10) << shoesPrice[i] << endl;
    }
    cout << endl << "Choose 0 to exit." << endl;
}

void searchShoes() {
    cout << "Search for Shoes:" << endl;
    cout << "Enter shoe name or brand: ";
    string searchKeyword;
    cin.ignore(); // Consume newline character
    getline(cin, searchKeyword);

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (shoesName[i] == searchKeyword || brand[i] == searchKeyword) {
            found = true;
            cout << "Shoe found: " << shoesName[i] << " - Brand: " << brand[i] << " - Price: " << shoesPrice[i] << endl;
        }
    }
    if (!found) {
        cout << "Shoe not found." << endl;
    }
}

void menu(){
    cout << "Menu:" << endl;
    cout << "1. Buy Shoes" << endl;
    cout << "2. Search for Shoes" << endl;
    cout << "3. View Cart" << endl;
    cout << "4. Checkout" << endl;
    cout << "0. Finish" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int chooseShoes, quantity, total = 0;
    
    while (true) {
        menu();
        int menuChoice;
        cin >> menuChoice;

        if (menuChoice == 0) {
            break; // Exit the loop if the customer is done
        }

        if (menuChoice == 1) {
            displayShoes();

            while(true){
                cout << "Enter the number of the shoe to add to the cart: ";
                cin >> chooseShoes;

                if (chooseShoes >= 1 && chooseShoes <= 5) {
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    cout << "Added to the cart." << endl;
                    cartNumber[x] = chooseShoes; // Add the selected choice to the cartNumber array
                    cartQuantity[x] = quantity;
                    x++;
                } 
                
                else if (chooseShoes==0){
                    break;
                }

                else {
                    cout << "Invalid choice." << endl;
                }
            }
        } 
        
        else if (menuChoice == 2) {
            searchShoes();
        } 
        
        else if (menuChoice == 3) {
            cout << "Items in the cart:" << endl;
            for (int i = 0; i < x; i++) {
                int itemIndex = cartNumber[i] - 1;
                cout << "Selected item: " << shoesName[itemIndex] << setw(20) << "Brand: " << brand[itemIndex]
                     << setw(20) << "Price: " << shoesPrice[itemIndex] << " Quantity: " << cartQuantity[i]
                     << " Total Price: " << shoesPrice[itemIndex] * cartQuantity[i] << endl;
            }
        }

        else if (menuChoice == 4) {
            cout << "========================== INVOICE ==========================" << endl << endl;

            for (int i = 0; i < x; i++) {
                int itemIndex = cartNumber[i] - 1;
                cout << "Selected item: " << shoesName[itemIndex] << setw(20) << "Brand: " << brand[itemIndex]
                     << setw(20) << "Price: " << shoesPrice[itemIndex] << " Quantity: " << cartQuantity[i]
                     << " Total Price: " << shoesPrice[itemIndex] * cartQuantity[i] << endl;
                total += shoesPrice[itemIndex] * cartQuantity[i];
            }

            cout << "Total Price: " << total << endl;
        }
    }
    return 0;
}
