#include <bits/stdc++.h>

using namespace std;

string word;

int main(){
    cin >> word; 

    stack <char> removed;
    bool win = false;

    for (char l : word) {
        if (removed.size() > 0) {
            if (removed.top() == l) {
                removed.pop();
                win = !win;
            } else {
                removed.push(l);
            }
        } else {
            removed.push(l);
        }
    }

    if (win) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}