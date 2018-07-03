#include <bits/stdc++.h>
#define MAXN 100010
#define debug(arr, len) cerr << #arr << " = "; for (int i=0;i<len;i++)cout << arr[i] << " \n"[i == n-1]
using namespace std;

vector<int> SP;
bitset<MAXN> hasSP;
int lps[MAXN];
int freq[MAXN];

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

    SP.push_back(lps[n-1]);
    hasSP[lps[n-1]] = true;
    for (int i = n-2; i > 0; i--){
        if (hasSP[i+1]){
           SP.push_back(lps[i]);
           hasSP[lps[i]] = true;
        }

    }
}

void computeFreq(int n){
    for (int i = n-1; i >= 0; i--){
        freq[i]++;
        if (lps[i] > 0){
            freq[lps[i] - 1] += freq[i];
        }
    }
}

int main (){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    int n = word.size();

    computeLPS(word);
    computeAllPS(n);
    computeFreq(n);

    // debug(lps, n);
    // debug(freq, n);
    
    int size = SP.size() + 1;

    if (SP.back() == 0){
        SP.pop_back();
        size--;
    }

    cout << size << endl;  
    while (!SP.empty()){
        int actual = SP.back();
        SP.pop_back();
        cout << actual << " " << freq[actual-1] << endl;
    }

    cout << word.size() << " " << 1 << endl;
    
}