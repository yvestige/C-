// App that transforms A3[B]B2[A] to "ABBBBAA" or B2[A2[C2[A]]] to "BACAACAAACAACAA"
// Assume numbers cannot exceed 10, but can support 0-9. Assume none before [] = 1.
// This is my 5th C++ application. Learning C++ for fun.

// potential improvements:
// 1. allow 2 or more digits
// 2. check for integrity of []'s.

// What I learned: More about iterators, also a new container "deque" which acts like a stack.
// also, string manipulation such as substrings, appending, character checking if alpha or number, etc.

//  Started: May 20, 2025 (11:45 PM)
//    Ended: May 20, 2025 (2:02 PM)


#include <string>
#include <deque>
#include <iostream>
#include <cctype>  // for std::isalpha

// defines
constexpr bool SHOW_SOLUTION = false;


/// @brief Function that processes the string.
/// @param str String to process
void processString(const std::string& str) {

    // function that stacks the values
    std::deque<char> stack;
    
    // other variables
    std::string result;
    int strIndex = 0;
    bool success = true;

    // do for every character
    for (const char& c : str) {

        // print current context
        if (SHOW_SOLUTION) {
            std::cout << "[" << strIndex++ << "] Current character '" << c << "'\n";
        }

        // add to stack
        stack.push_back(c);

        // get beginning character
        char beginChar = *(stack.begin());

        // if a letter has been discovered at first item
        if (isalpha(*stack.begin())) {

            // add all characters to result string
            for (auto it = stack.end()-1; it != stack.begin()-1; --it) {
                result.append(1,*it);
                if (SHOW_SOLUTION) {
                   std::cout << "logged: '" << *it << "'\n";
                }
            }

            // clear the stack
            stack.clear();
        
        
        // if current value is a ']', check for integrity
        } else if (c == ']') {

            // variable declarations
            int currentIndex = stack.size();
            bool integrityValid = false;
            std::string substring = "";

            // actually check integrity
            for (auto it = stack.end(); it != stack.begin(); --it) {

                // update index
                currentIndex--;

                // add to substring if it is letter
                if (isalpha(*it)) {
                    substring.insert(0,1,*it);
                    if (SHOW_SOLUTION) {
                        std::cout << "    substring: " << substring << "\n";
                    }
                }

                // if appropriate integrity found
                if (*it == '[') {

                    // integrity success
                    integrityValid = true;

                    // multiplier
                    int n = 1, n_found = 0;

                    // if before the character '[' was a number, set multiplier
                    if (it != stack.begin() && std::isdigit(*(it-1))) {
                        n = *(it-1) - '0';
                        n_found = 1;
                    }

                    if (SHOW_SOLUTION) {
                        std::cout << "    n: " << n << "\n";
                    }
                    
                    // finally, delete current context from stack
                    stack.erase(it - (n_found ? 1:0), stack.end());

                    // and add the new substring context
                    for (int i=0; i<n; ++i) {
                        for (char substring_c : substring) {
                            stack.push_back(substring_c);
                        }
                    }

                    // and break
                    break;
                }
            }

            // if integrity not valid, failed
            if (!integrityValid) {
                success = false;
                std::cout << "Error: format '_n_[<C>]' required (10001)\n\n";
                return;
            }
        }

        if (SHOW_SOLUTION) {
            std::cout << "Current stack: | ";
            for (auto stack_c : stack) {
                std::cout << stack_c;
            } 
            std::cout << " |\n";
            std::cout << "Current result: " << result << "\n\n";
        }
        
    }

    // add last stack after everything
    for (char c : stack) {
        if (SHOW_SOLUTION) {
            std::cout << "logged: '" << c << "'\n";
        }        
        result.append(1,c);
    }

    // if mismatch found, do not print string
    if (result.find('[') != std::string::npos) {
        std::cout << "Error: unmatched '[]' (10002)\n\n";
        return;
    }

    // print out result
    std::cout << "Here is the result: " << result << "\n\n";



}


// main function
int main() {

    // stores the string for processing 
    std::string str;

    // continually ask for string
    while (true) {

        // ask user input
        std::cout << "Give a string: ";
        getline(std::cin, str);

        // do checks
        if (str == "exit") {
            std::cout << "\nBye bye\n";
            break;
        
        // if not exit, process string
        } else {
            processString(str);
        }
    }

    return 0;
}