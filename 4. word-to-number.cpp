#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <cctype>

/// @brief Function that returns the map table.
/// @return A map of form {<value/multiplier>, {<identifier>,<int_value>}}
std::map<std::string,std::map<std::string,long long>> getMapTable() {

    // make the map table
    std::map<std::string,std::map<std::string,long long>> mapTable = {
        {
            "value", {
                {"one", 1},
                {"two", 2},
                {"three", 3},
                {"four", 4},
                {"five", 5},
                {"six", 6},
                {"seven", 7},
                {"eight", 8},
                {"nine", 9},
                {"ten", 10},
                {"eleven", 11},
                {"twelve", 12},
                {"thirteen", 13},
                {"fourteen", 14},
                {"fifteen", 15},
                {"sixteen", 16},
                {"seventeen", 17},
                {"eighteen", 18},
                {"nineteen", 19},
                {"twenty", 20},
                {"thirty", 30},
                {"forty", 40},
                {"fifty", 50},
                {"sixty", 60},
                {"seventy", 70},
                {"eighty", 80},
                {"ninety", 90},
            }
        },

        {
            "multiplier", {
                {"hundred",100},
                {"thousand",1000},
                {"million",1000000},
                {"billion",1000000000},
                {"trillion",1000000000000},
                {"quadrillion",1000000000000000},
                {"quintillion",1000000000000000000},
                {"negative",-1},
            }
        }
    };

    // actually return something
    return mapTable;
}

/// @brief Function that converts a string of words into a list of strings
/// @param words stringed words that will be tokenized.
/// @return Vector of string words
std::vector<std::string> turnWordsToWordVector(const std::string& words) {

    // variables
    std::istringstream wordStream(words);
    std::vector<std::string> wordVector;
    std::string word;

    // do for each word
    while (wordStream >> word) {

        // for each tokenized word, remove comma
        word.erase(std::remove(word.begin(), word.end(), ','), word.end());
        
        // make all words small letter
        std::transform(word.begin(), word.end(), word.begin(), 
            [](const unsigned char& c) { return std::tolower(c); }
        );

        // push character to word vector
        wordVector.push_back(word);
    }

    // actually return a value
    return wordVector;
}


/// @brief Function that converts the words to its current number
/// @param str Stringed word that will be converted to number
void convertWordToNumber(const std::string& words) {
    
    // acquire vector of strings
    std::vector<std::string> wordVector = turnWordsToWordVector(words);

    // get the map table
    const auto& mapTable = getMapTable();

    // assign references
    const auto& valueMap = mapTable.at("value");
    const auto& multiplierMap = mapTable.at("multiplier");

    // variables for reference in computation
    long long value = 0, multiplier = 1;
    bool isNegative = false;

    // iterate through each word
    for (const auto& word : wordVector) {

        // if negative, set bool switch and skip to next
        if (word == "negative") {
            isNegative = true;
            continue;
        }

        // if word is a value
        if (valueMap.find(word) != valueMap.end()) {
            // do algorithm for value
        

        // if word is a multiplier
        } else if (multiplierMap.find(word) != multiplierMap.end()) {
            // do method for multiplier
        
        // if none found
        } else {
            std::cout << "ERROR: token '" << word << "' invalid.\n"; 
        }
    }
}

// main function
int main() {

    // continuous loop
    while (true) {

        // variables declarations
        std::string words;

        // ask for user input
        std::cout << "Enter string: ";
        std::getline(std::cin, words);

        // process the entire string
        convertWordToNumber(words);

        // leave an empty line
        std::cout << "\n";
    }

    // actually return something
    return 0;
}