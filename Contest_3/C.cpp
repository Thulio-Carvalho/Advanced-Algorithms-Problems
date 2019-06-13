#include <bits/stdc++.h>

using namespace std;

string s;

int main (){
    cin >> s;


    vector <char> answer;

    if (s.size() <= 2) {
        cout << s << endl;
        return 0;
    }

    int mid;

    if (s.size() % 2 == 0) {
        mid = s.size() / 2 - 1;
    } else {
        mid = s.size() / 2;
    }

    int i = mid;
    int j = mid + 1;

    while (i >= 0 && j < s.size()){ 
        answer.push_back(s[i--]);
        answer.push_back(s[j++]);
    }

    while (i >= 0) {
        answer.push_back(s[i--]);
    }

    while (j < s.size()) {
        answer.push_back(s[j++]);
    }

    string final_answer(answer.begin(), answer.end());

    cout << final_answer << endl;

    return 0;
}