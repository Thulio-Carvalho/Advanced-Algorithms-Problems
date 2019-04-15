#include <bits/stdc++.h>
#define MAXN 200014

using namespace std;

int N, arr[MAXN], l[MAXN], r[MAXN];
stack<int> s;

int main(){
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    fill(l, l + MAXN, -1);
    fill(r, r + MAXN, N);

    for (int i = 0; i < N; i++) {
        while(!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
        if (!s.empty())
            l[i] = s.top();
        s.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    for (int i = 0; i < N; i++) {
        cout << l[i] << " ";
    } cout << endl;

    return 0;
}