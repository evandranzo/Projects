/*
    Program 2:  Write a text search program.
    Programmer: Evan Dranzo
    Class:		CSCI330, Fall 2022
    Short Description:	Search a file for the first instance of a word
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void Search(const vector<string> &lineList, const string tmpString);

int main(){
    string tmpString;
    ifstream inputFile;
    vector<string> lineList;

    cout << "Filename: ";//Prompts user for the filename//
    cin >> tmpString;
    cout << endl << endl;
    inputFile.open(tmpString);
//Adds strings to the vectors//
    while(getline(inputFile, tmpString)) {
        lineList.push_back(tmpString);
    }
    while(cin){
        cout << "Text to find: ";
        cin >> tmpString;
        Search(lineList, tmpString);
    }
    inputFile.close();
    return 0;
}
void Search(const vector<string> &lineList, const string tmpString) { //Trying to find the word
    bool extLoop{false};
    int i{0};
    while (extLoop == false){
        if (lineList[i].find(tmpString) != string::npos){
            cout << tmpString << " first found on line " << i+1 << endl << endl;
            extLoop = true;
        } else if (i+1 == static_cast<int>(lineList.size())){
            cout << "Couldn't find " << tmpString << endl << endl;
            extLoop = true;
        }
        i++;
    }
}
/*
Search appears to work correctly. EOF doesn't terminate prompting for a new search time, however.

The Search function would make more sense as an actual search function. Instead, it seems to run the loop and do the searching.
*/