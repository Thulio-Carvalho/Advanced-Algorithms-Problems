#include <bits/stdc++.h>

using namespace std;

int n, a, b, total;


int measure(int x){
    return min(a / x, b / (n - x));
}

int search(){
    int best = INT32_MIN;

    for (int i = 1; i < n; i++) {
        int tmp = measure(i);
        if (tmp > best) {
            best = tmp;
        }
    }
    return best;
}

int main(){
    cin >> n >> a >> b;

    total = a + b;

    cout << search() << endl;

    return 0;
}