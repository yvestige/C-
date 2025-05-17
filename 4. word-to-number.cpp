#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <cctype>

std::map<std::string,std::map<std::string,std::string>> getMapTable() {

    // make the map table
    std::map<std::string,std::map<std::string,std::string>> mapTable = {
        {
            "numeric", {
                {"one", "1"},
                {"two", ""},
                {"three", ""},
                {"four", ""},
                {"five", ""},
                {"six", ""},
                {"seven", ""},
                {"eight", ""},
                {"nine", ""},
                {"ten", ""},
                {"eleven", ""},
                {"twelve", ""},
                {"thirteen", ""},
                {"fourteen", ""},
                {"fifteen", ""},
                {"sixteen", ""},
                {"seventeen", ""},
                {"eighteen", ""},
                {"nineteen", ""},
                {"twenty", ""},
                {"thirty", ""},
                {"forty", ""},
                {"fifty", ""},
                {"sixty", ""},
                {"seventy", ""},
                {"eighty", ""},
                {"ninety", ""},
            }
        },
        {
            "multiplier", {
                {"hundred",""},
                {"thousand",""},
                {"million",""},
                {"billion",""},
                {"trillion",""},
                {"quadrillion",""},
                {"quintillion",""},
                {"sextillion",""},
                {"septillion",""},
                {"octillion",""},
                {"nonillion",""},
                {"",""},
            }
        }
    };

    // actually return something
    return mapTable;
}

/// @brief Function that converts a string of words into a list of strings
/// @param words stringed words that will be tokenized.
/// @return Vector of string words
std::vector<std::string> getTokenWordsVector(const std::string& words) {

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
    std::vector<std::string> wordVector = getTokenWordsVector(words);


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

}