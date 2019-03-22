#include <bits/stdc++.h>
#define MAXN 40
using namespace std;

int S, X;
int dp[MAXN][2];

bool bit(int S, int k) {
    return (S & ( 1 << S )) >> k;
}

int solve(int i, bool carry){
    if (dp[i][carry] != -1) {
        return dp[i][carry];
    }
    if (bit(X, i) && bit(S, i) && carry) return 0;
    if (bit(X, i) && !bit(S, i) && !carry) return 0;
    if (!bit(X, i) && bit(S, i) && !carry) return 0;
    if (!bit(X, i) && !bit(S, i) && carry) return 0;

    // if (bit(X, i) && bit(S, i) && !carry){
    //     dp[]
    // }

}

int main(){
    cin >> S >> X;

    return 0;
}