// App that prints the pattern appropriately.
// This is my 3rd C++ application. Learning C++ for fun.

//  Started: May 17, 2025 (4:36 AM)
//    Ended: May 17, 2025 (5:48 AM)

// includes stated here
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

// constant values (can change these values)
constexpr int STARTING_POINT = 2;
constexpr int INCREMENTAL_POINT = 6;


// cleans the buffer
void cleanBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


/// @brief Function that checks if the string characters are all just whitespaces
/// @param str String to check.
/// @return Boolean value if string is all whitespace or not.
bool isAllWhiteSpace(const std::string& str) {
    return all_of(str.begin(), str.end(), [](const char& a) { return isspace(a); });
}

/// @brief Function that processes the triangle
/// @param n Value of n
void processTriangle(const int& n) {

    // variables
    std::vector<int> startingPoints;

    // Step 1: compute initial starting points
    {
        int currentStartingPoint = STARTING_POINT;

        for (int i=0; i<n; ++i) {
            currentStartingPoint = (i==0) ? STARTING_POINT : currentStartingPoint + (INCREMENTAL_POINT+1-i);
            startingPoints.push_back(currentStartingPoint);
        }
    }

    // Step 2: print appropriately
    {
        int temp = 0, currentValue;
        for (int x : startingPoints) {
            currentValue = x;
            for (int i=0; i<temp+1; ++i) {
                std::cout << currentValue-i << " ";
                currentValue-=i; 
            }
            temp++;
            std::cout << std::endl;
        }
    }
}


// main function
int main() {

    // n stores the value for pyramid
    int n;

    // Prompt user for a valid value of n
    {
        std::string choice;

        // continuously ask for appropriate number
        while (true) {

            // get the n 
            std::cout << "Provide n: ";
            std::cin >> n;
            std::getline(std::cin, choice);

            // if failed, do again
            if (std::cin.fail()) {
                std::cout << "ERROR: incorrect value!\n" << std::endl;
                cleanBuffer();
                continue;
            
            
            // if more than one choice found
            } else if (!isAllWhiteSpace(choice)) {
                std::cout << "ERROR: 1 value only!\n" << std::endl;
                continue;
            
            
            // if n is negative
            } else if (n < 0) {
                std::cout << "ERROR: positive n only!\n" << std::endl;
                continue;

            
            // if success, stop while loop
            } else {
                std::cout << std::endl;
                break;
            }
        }
    }

    // process the triangle
    processTriangle(n);

    // exit main without issue
    return 0;
}