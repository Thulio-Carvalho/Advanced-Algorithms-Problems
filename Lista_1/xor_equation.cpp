#include <bits/stdc++.h>
#define MAXN 61
 
using namespace std;
 
typedef long long ll;
 
ll S, X;
ll dp[MAXN][2];
int limit;
 
bool bit(ll S, int k) {
    return (S & ( 1LL << k ));
}
 
ll solve(int i, bool carry){
	if (i >= limit) return !carry;
 
    if (dp[i][carry] != -1) {
        return dp[i][carry];
    }
 
    if (bit(X, i) && bit(S, i) && carry) return dp[i][carry] = 0;
    if (bit(X, i) && !bit(S, i) && !carry) return dp[i][carry] = 0;
    if (!bit(X, i) && !bit(S, i) && carry) return dp[i][carry] = 0;
    if (!bit(X, i) && bit(S, i) && !carry) return dp[i][carry] = 0;
 
    if (bit(X, i) && bit(S, i) && !carry){
        return dp[i][carry] = 2 * solve(i+1, 0);
    }
    if (bit(X, i) && !bit(S, i) && carry){
        return dp[i][carry] = 2 * solve(i+1, 1);
    }
    if (!bit(X, i) && bit(S, i) && carry){
        return dp[i][carry] = solve(i+1, 0) + solve(i+1, 1);
    }
    if (!bit(X, i) && !bit(S, i) && !carry){
        return dp[i][carry] = solve(i+1, 1) + solve(i+1, 0);
    }
}
 
int main(){
    cin >> S >> X;
 
    for(int i = 0; i < MAXN; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
 
    limit = 61;

    if (S == X) {
        cout << solve(0, 0) - 2 << endl;    
    } else {
        cout << solve(0, 0) << endl;
    }
 
    return 0;
}