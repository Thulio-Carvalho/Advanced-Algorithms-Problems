#include <bits/stdc++.h>

using namespace std;

void generateMatch(string word, int* arr, int i, int j){
    if (i < word.size()){
        if (word[i] == word[j]){
            arr[i] = j + 1;
            i++, j++;
        } else {
            if (j == 0){
                arr[i] = 0;
                i++;
            } else {
                j = arr[j - 1];
            }
        }
        generateMatch(word, arr, i, j);
    }
}

int* PrefixSuffixMatch(string word){
    int* arr = new int[word.size()];
    int j = 0, i = 1;
    generateMatch(word, arr, i, j);

    return arr;
}

int KMP(string text, string pattern, int* match){
    return 0;
}   


int main(){
    string text, pattern;
    cin >> pattern;
    int* match = PrefixSuffixMatch(pattern);
    for (int i = 0; i < pattern.size(); i++){
        cout << match[i] << " ";
    } cout << endl;

    return 0;
}