#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstdint>

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
void splitString(string& input, char delimiter,
                 string arr[], int& index)
{
    istringstream stream(input);

    string token;

    while (getline(stream, token, delimiter)) {
        arr[index++] = token;
    }
}



int fillDS(vector<string>& dataset, string stringData) {

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



vector<Word> calcProb(vector<string> dataset){
    for(int i = 0; i < dataset.size(); i++){
        string prevToken = dataset[i - 1];
        string token = dataset[i];
        cout << token << endl;
    }

    return {{0}};
}

// 
// Sort the dataset based on this {firstword, {nextword, nextword, netword}, firstword, {nextword, nexword}}
// 

vector<vector<string>> filterList(vector<string> dataset){
    vector<vector<Raw>> list;
    for(int i = 1; i < dataset.size(); i++){
        string prevToken = dataset[i - 1];
        string token = dataset[i];
        cout << prevToken << " -> " << token << endl;

    }

    return {{"str"}};
}

int handleWord(string word, string next, vector<vector<Raw>>& list){
    bool flagg = true;
    for(int i = 0; i < list.size(); i++){
        Raw element = list[i];
        if(element.word == word){
            flagg = false;
            element.nextPossible.push_back(next);
        }
        cout << element[word];
    }
    if(flagg){
        Raw element = {word, {next}};
        list.push_back(element);
    }

    return 0;
}

int main(){
    fillDS(dataset, "Hello there this is a sentence");   
    filterList(dataset);
}