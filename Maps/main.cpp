//
//  main.cpp
//  235 -Maps
//
//  Created by Christian Bain on 4/21/20.
//  Copyright © 2020 Christian Bain. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <list>

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*
        PART 1
     */
    
    string fileName = "1Nephi.txt";
    
    ifstream myFile;
    myFile.open(fileName);
    
//    cout << "Opening file..." << endl;

    if (!myFile) {
        cout << "NO FILE FOUND" << endl;
        exit(1);
    } else {
        cout << "File opened... reading in now" << endl << endl;
    }
    
    set<string> wordSet;
    string word;
    set<string>::reverse_iterator rit;
    while (myFile >> word) {
            // check punctuation
        string tempWord = "";
        for (int i = 0; i < word.size(); i++) {
            if (isalpha(word[i])) {
                tempWord = tempWord + word[i];
            }
        }
        wordSet.insert(tempWord);
    }
    myFile.close();
//    cout << "Created a new set of words from input file" << endl;
//    cout << "Size of wordSet: " << wordSet.size() << endl << endl;
//    cout << "Writing to output file..." << endl;
    ofstream os;
//    string outputFileName = argv[0] = "_set.txt";
    string outputFileName = "1Nephi_set.txt";
    os.open(outputFileName);
    if (os.is_open()){
//        cout << "New file created and currently open... Now writing to file..." << endl;
    }
    set<string>::iterator it;
    for (it = wordSet.begin(); it != wordSet.end(); it++) {
        os << *it << endl;
    }
    os.close();
    
    
    /*
        PART 2
     */
        // vector from input file
    vector<string> wordVector;
    myFile.open(fileName);
//    cout << "Opening file..." << endl;

    if (!myFile) {
        cout << "NO FILE FOUND" << endl;
        exit(1);
    } else {
//        cout << "File opened... reading in now" << endl << endl;
    }

    while (myFile >> word) {
        string tempWord = "";
        for (int i = 0; i < word.size(); i++) {
            if (isalpha(word[i])) {
                tempWord = tempWord + word[i];
            }
        }
        wordVector.push_back(tempWord);
    }
    myFile.close();
//    cout << "Created a vecotr of words from input file:" << endl;
    string outFileVectorName = "1Nephi_vector.txt";
    os.open(outFileVectorName);
    if (os.is_open()) {
//        cout << "New file created and open... writing vector contents to file now..." << endl;
    }
    for (unsigned int i = 0; i < wordVector.size(); i++) {
        os << wordVector.at(i) << endl;
    }
    os.close();
    
    
    /*
        PART 3
     
            map ->  <list<string>, vector<string>>
     */
    
    
    cout << "Making map..." << endl << endl;
    
    int M = 2;
    map<list<string>, vector<string>> wordMap;
    list<string> state;
    for (unsigned int i = 0; i < M; i++) {
        state.push_back("");
    }
    
    for (unsigned int i = 0; i < wordVector.size(); i++) {
        wordMap[state].push_back(wordVector.at(i));
        state.push_back(wordVector.at(i));
        state.pop_front();
    }
    string mapOutput = "1Nephi_1_1.txt";
//    cout << endl << "Map made successfully!" << endl << endl;
    
    state.clear();
    for (unsigned int i = 0; i < M; i++) {
        state.push_back("");
    }
    
    for (unsigned int i = 0; i < 100; i++) {
        int ind = rand() % wordMap[state].size();
        cout << wordMap[state][ind] << " ";
        state.push_back(wordMap[state][ind]);
        state.pop_front();
    }

        
    return 0;
}
