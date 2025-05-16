// app that counts words

// Started: May 16, 2025 (1:52 PM)
//   Ended: May 16, 2025 (2:59 PM)


// includes
#include <iostream>     // including input-output stream header file
#include <limits>       // for the limits thing
#include <string>       // for string
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

// namespaces
using namespace std;

// function that gets the words
vector<string> getWords(const string& str) {

    // variables
    istringstream iss(str);
    vector<string> words;
    string temp;

    while (iss >> temp) {
        words.push_back(temp);
    }

    // actuallyr return something
    return words;
}


map<string,int> mapWords(const vector<string>& words) {
    map<string,int> wordMap;

    // do the mapping 
    for (const string& word : words) {
        ++wordMap[word];
    }

    // actually return something
    return wordMap;
}

vector<pair<string,int>> sortFrequency(const map<string,int>& wordMap) {

    // array of pairs of string
    vector<pair<string,int>> sortedPairs(wordMap.begin(), wordMap.end());

    // begin sorting
    sort(sortedPairs.begin(), sortedPairs.end(), 
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        }
    );

    // actually return something
    return sortedPairs;

}

/// @brief Function that processes the string
/// @param str String to process
void processString(string str) {

    // acquire the words
    vector<string> words = getWords(str);

    // map the words
    map<string, int> wordMap = mapWords(words);

    // sort according to frequency
    vector<pair<string,int>> sorted = sortFrequency(wordMap);

    // print out results
    for (const pair<string,int>& details : sorted) {
        cout << details.first << ": " << details.second << endl;
    }

}

// main program
int main() {

    string str;

    // menu notification
    cout << "Enter a sentence: ";
    getline(cin, str);

    // process the string
    processString(str);

    // make the new line
    cout << endl;
}