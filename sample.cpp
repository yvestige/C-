#include <iostream>     // including input-output stream header file
#include <limits>       // for the limits thing

// namespaces
using namespace std;

// cleans the buffer
void CleanBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// for addition
void addition(double value1, double value2) {
    cout << value1 << "+" << value2 << " = " << (value1 + value2) << endl; 
}

// for subtraction
void subtraction(double value1, double value2) {
    cout << value1 << "-" << value2 << " = " << (value1 - value2) << endl; 
}

// for division
void division(double value1, double value2) {
    cout << value1 << "/" << value2 << " = " << (value1/value2) << endl; 
}

// for multiplication
void multiplication(double value1, double value2) {
    cout << value1 << "*" << value2 << " = " << (value1*value2) << endl; 
}

// calculator sample
int main() {

    // loop    
    while (1) {

        // variable declarations
        int option;
        double value1, value2;

        // menu
        cout << "What would you like to do?" << endl;
        cout << "1. Perform addition" << endl;
        cout << "2. Perform subtraction" << endl;
        cout << "3. Perform multiplication" << endl;
        cout << "4. Perform division" << endl;

        // get choice
        cout << "\nOption: ";
        cin >> option;

        
        // check if wrong option found
        if (option < 1 || option > 4) {
            cout << endl << "Wrong option! Try again." << endl;
            CleanBuffer();
            continue;
        
        // if correct
        } else {
            CleanBuffer();

            // continuously check until completely okay
            while (1) {
                cout << "Enter two values: ";
                cin >> value1 >> value2;
                cout << endl;

                if (cin.fail()) {
                    cout << "Wrong value. Try again!\n";
                    CleanBuffer();
                } else {
                    break;
                }
            }
            
            // do the operations
            if (option == 1) {
                addition(value1, value2);
            } else if (option == 2) {
                subtraction(value1, value2);
            } else if (option == 3) {
                multiplication(value1, value2);
            } else if (option == 4) {
                division(value1, value2);
            } 

            // loop again
            cout << endl;
        }

    }
}