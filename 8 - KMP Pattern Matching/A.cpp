#include <bits/stdc++.h>

using namespace std;

void computeLPS(string word, int* match, int i, int j){
    if (i < word.size()){
        if (word[i] == word[j]){
            match[i] = j + 1;
            i++;
            j++;
        } else {
            if (j == 0){
                match[i] = 0;
                i++;
            } else {
                j = match[j - 1];
            }
        }
        computeLPS(word, match, i, j);
    }
}

int* computeLPS(string word){
    int* match = new int[word.size()];
    int i = 1, j = 0;
    computeLPS(word, match, i, j);
    return match;
}

bool KMP(string text, string pattern, int* lps){
    bool found = false;
    int matcher = 0, i = 0;

    while (matcher < pattern.size() && i < text.size()){

        if (text[i] == pattern[matcher]){
            i++;
            matcher++;
            if (matcher == pattern.size()){
                found = true;
            }

        } else {
            if (matcher == 0){
                i++;
            } else{
            matcher = lps[matcher - 1];
            }
        }
    }
    return found;
}

vector <string> findPSMatches(string text){
    int len = 1;
    int start = 0, end = text.size() - 1;
    vector <string> matches; 

    string aux = "";


    while (len < text.size()){
        if (text.substr(start, len) == text.substr(end+1 - len, len)){
            aux = text.substr(start, len);
            matches.push_back(aux); 
        }

        len++;
    }

    return matches;
}

int main(){

    string text;
    cin >> text;

    vector<string> matches = findPSMatches(text);

    bool found = false;
    string ans;

    while (!matches.empty()){

        string pattern = matches.back();
        matches.pop_back();

        int* lps = computeLPS(pattern);

        string subText = text.substr(1, text.size() - 2);

        if (KMP(subText, pattern, lps)){
            found = true;
            ans = pattern;
            break;
        }
    }

    if (found) {
        cout << ans<< endl;
    } else {
        cout << "Just a legend" << endl;
    }

    return 0;
}

