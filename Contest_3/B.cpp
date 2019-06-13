#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll k;

int main(){
    cin >> n >> m >> k;
    int b = n - 1;
    int bd = b + m - 1;

    if (k <= b) {
        cout << k + 1 << " " << 1 << endl;
        return 0;
    }

    if (k <= bd) {
        cout << n << " " << 1 + k - b  << endl;
        return 0;
    }

    ll diff = k - bd;

    int column;
    int mod = diff % (m - 1);
    if (mod == 0) {
        column = 2;
    } else {
        column = m - (mod - 1);
    }
    int line = n - ((diff - 1) / (m - 1)) + 1;

    cout << line << " " << column << endl;
}