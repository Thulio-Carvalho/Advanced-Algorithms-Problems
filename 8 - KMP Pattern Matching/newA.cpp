#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

bitset<MAXN> SP;
int lps[MAXN];

void computeLPS(string word){
    int i = 1, j = 0;
    while (i < word.size()){
        if (word[i] == word[j]){
            lps[i] = j + 1;
            j++, i++;
        } else if (j == 0){
            lps[i] = 0;
            i++;
        } else {
            j = lps[j - 1];
        }
    }
}

void computeAllPS(int n){

    SP[lps[n-1]] = true;

    for (int i = n-2; i > 0; i--){
        if (SP[i+1]){
            SP[lps[i]] = true;
        }

    }
}

int main (){
    string word;
    cin >> word;

    computeLPS(word);
    int n = word.size();

    computeAllPS(n);

    int max = 0;

    for (int i = 1; i < n-1; i++){
        if (lps[i] > max){
            if (SP[lps[i]]){
                max = lps[i];
            }
        }    
    }
    if (max == 0){
        cout << "Just a legend" << endl;
    } else{
        cout << word.substr(0, max) << endl;
    }
    
}