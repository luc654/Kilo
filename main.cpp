#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdint>
#include <random>

using namespace std;
vector<string> dataset;

struct Token {
    int chance;
    string value;
};

struct Word {
    string word;
    vector<vector<Token>> tokens;
};
struct Raw{
    string word;
    vector<string> nextPossible;
};

// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Util functions
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

// Returns random number.   
// Inp: int min, int max.
// Out: int, random number based on min & max

int random(int min, int max){
    return rand()%(max-min + 1) + min;
}


// Splits a string based on its delimiter. Does not return but rather uses a reference to the input.

// Inp:
// string& input, the string which will get split
// char delimiter, character to split the string on. 
// string arr[], temporary safe space for individual tokens.
// int& index, position to start the splitting.

void splitString(string& input, char delimiter,
                 string arr[], int& index)
{
    istringstream stream(input);

    string token;

    while (getline(stream, token, delimiter)) {
        arr[index++] = token;
    }
}



// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Dataset Generation functions
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-



// Logs current dataset, helper function

int debug(vector<Raw>& list){
    for(int i = 0; i < list.size(); i++){
        Raw element = list[i];
        cout << endl << element.word << endl;
        for(int j =0; j < element.nextPossible.size(); j++){
            cout << "- " << element.nextPossible[j] << endl;
        }
    }
    return 0;
}

// Fill a reference of a dataset with a processed string.
// Returns a vector of strings which later gets processed into the dataset
int formatRDS(vector<string>& dataset, string stringData) {

    // Remove whitespaces from stringData.


    // Split the string on every whitespace.
    string arrSubset[1000];
    char delimiter = ' ';
    int index = 0;

    splitString(stringData, delimiter, arrSubset, index);

    for(int i = 0; i <  (sizeof(arrSubset) / sizeof(arrSubset[0])); i++){
        if(arrSubset[i].length() > 0){
            dataset.push_back(arrSubset[i]);
        } else {
            break;
        }
    }
    return 0;
}


int handleWord(string word, string next, vector<Raw>& list){
    bool flagg = true;
    for(int i = 0; i < list.size(); i++){
        Raw& element = list[i];
        if(element.word == word){
            flagg = false;
            element.nextPossible.push_back(next);
        }
    }
    if(flagg){
        Raw element = {word, {next}};
        list.push_back(element);
    }

    return 0;
}
// 
// Transforms the formatted Raw data into a real dataset.
// 

vector<vector<string>> fillDS(vector<string> dataset){
    vector<Raw> list;
    for(int i = 1; i < dataset.size(); i++){
        string prevToken = dataset[i - 1];
        string token = dataset[i];
        handleWord(prevToken, token, list);

    }
    debug(list);

    return {{"str"}};
}


int main(){
    formatRDS(dataset, "Hello there this is a sentence. this might be unexpected or this might be totally expected");   
    fillDS(dataset);
}