#include <bits/stdc++.h>

using namespace std;

int potTwo(int n){
    int res = 1;
    for (int i = 0; i < n; i++){
        res *= 2;
    }
    return res;
}
int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    startPos[];
    for (int i = 1; i < n-1; i++){
        startPos[i] = potTwo(i);
    }
    for (int i = )
    // 1 - 2^1
    // 2 - 1 + 2^2
    // 3 - 3 + 2^3 
    // 4 - 2^4
     10 

    return 0;
}

// 1 [1]
// 2 [1, 2, 1]
// 3 [1, 2, 1, 3, 1, 2, 1]
// 4 [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1]
// 5 [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1, 5, 1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1]