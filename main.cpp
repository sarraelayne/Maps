#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int main(int argC, char *argV[]) {
    cout << "beginning" << endl;
    string line;
    cout << "line" << endl;
    ifstream nephiFile;
    ofstream outputFile;
    cout << "make the files" << endl;
    nephiFile.open("1Nephi.txt");
    cout << "open the files" << endl;
    set<string> nephiSet;
    vector<string> nephiVector;
    cout << "create s & v" << endl;
    string userFile =  "output";
    cout << "string userFile" << endl;
    userFile = argV[1];
    
    cout << "parts 1 n 2" << endl;
    
    //PARTS 1 & 2
    if(nephiFile.is_open()) {
        while(nephiFile >> line) {
            if (!isalpha(line[line.length()-1])) {
                line.erase(line.length() - 1);
            }
            nephiSet.insert(line + " ");
            nephiVector.push_back(line + " ");
        }
        nephiFile.close();
    }
    cout << "Help" << endl;
    int M=2;
    map<vector<string>, vector<string>> wordMap;
    vector<string> state;
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    //output file for map
    outputFile.open(userFile + "_1_1.txt");
    for (vector<string>::iterator it=nephiVector.begin(); it!=nephiVector.end(); it++) {
        wordMap[state].push_back(*it);
        state.push_back(*it);
        state.erase(state.begin());
    }
    cout << "Me" << endl;
    srand(time(NULL));
    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    cout << "please" << endl;
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordMap[state].size();
        cout << wordMap[state][ind] << " ";
        state.push_back(wordMap[state][ind]);
        state.erase(state.begin());
    }
    outputFile.close();
    cout << "something" << endl;
    outputFile.open(userFile + "_set.txt");
    for(set<string>::iterator it = nephiSet.begin(); it!=nephiSet.end(); it++) {
        outputFile << *it << " ";
    }
    outputFile.close();
    cout << "is" << endl;
    outputFile.open(userFile + "_vector.txt");
    for (int i = 0; i < nephiVector.size(); i++) {
        outputFile << nephiVector.at(i);
    }
    outputFile.close();
    cout << "wrong" << endl;
    return 0;
}