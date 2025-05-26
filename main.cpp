#include <iostream>
#include <vector>
#include <sstream>


using namespace std;
vector<string> dataset;




void splitString(string& input, char delimiter,
                 string arr[], int& index)
{
    istringstream stream(input);

    string token;

    while (getline(stream, token, delimiter)) {
        arr[index++] = token;
    }
}



int fillDS(vector<string>& dataset, string data) {

    string arrSubset[1000];
    char delimiter = ' ';
    int index = 0;

    splitString(data, delimiter, arrSubset, index);

    for(int i = 0; i <  (sizeof(arrSubset) / sizeof(arrSubset[0])); i++){
        if(arrSubset[i].length() > 0){
            dataset.push_back(arrSubset[i]);
        } else {
            break;
        }
    }
    return 0;
}



int main(){
    fillDS(dataset, "Hello there this is a sentence");   
}