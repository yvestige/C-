// my first C++ calculator
// May 16, 2025 [12:37 AM]

#include <iostream>     // including input-output stream header file
#include <limits>       // for the limits thing
#include <string>       // for string
// namespaces
using namespace std;

bool IsOnlySpace(string str) {
    string whitespaces = "\n\t ";
    for (char c:str) {
        if (whitespaces.find(c) != string::npos) {
            return false; // if not whitespace, error
        }
    }
    return true;
}

// cleans the buffer
void CleanBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// for addition
void addition(double value1, double value2) {
    cout << "\n" << value1 << "+" << value2 << " = " << (value1 + value2) << endl; 
}

// for subtraction
void subtraction(double value1, double value2) {
    cout << "\n" << value1 << "-" << value2 << " = " << (value1 - value2) << endl; 
}

// for division
void division(double value1, double value2) {
    if (value2 == 0) {
        cout << "Cannot divide a value by 0!" << endl; 
    } else {
        cout << "\n" << value1 << "/" << value2 << " = " << (value1/value2) << endl; 
    }
}

// for multiplication
void multiplication(double value1, double value2) {
    cout << "\n" << value1 << "*" << value2 << " = " << (value1*value2) << endl; 
}


// calculator sample
int main() {

    // loop    
    while (1) {

        // variable declarations
        int option;
        string tempStr;
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
            cout << endl << "\nWrong option! Try again." << endl;
            CleanBuffer();
            continue;
        
        // if correct
        } else {
            CleanBuffer();

            // continuously check until completely okay
            while (1) {
                cout << "\nEnter two values: ";
                cin >> value1 >> value2;

                // place buffer values to temp string
                getline(cin, tempStr);

                // if parse failed
                if (cin.fail()) {
                    cout << "Wrong value. Try again!" << endl;
                    CleanBuffer();

                // if more than 1 value given
                } else if (!IsOnlySpace(tempStr)) {
                    cout << "Should be less than 3 values." << endl;
                    // no need to clean buffer because is empty here
                    
                } else {
                    break;
                }
            }

            // do the operations
            switch (option) {
                case 1: 
                    addition(value1, value2);
                    break;

                case 2: 
                    subtraction(value1, value2);
                    break;

                case 3:
                    multiplication(value1, value2);
                    break;

                case 4:
                    division(value1, value2);
                    break;
            }

            // loop again
            cout << endl;
        }

    }
}