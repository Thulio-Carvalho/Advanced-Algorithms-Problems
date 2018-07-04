#include <bits/stdc++.h>
#define MAXN 100010
#define debug(arr, len) cerr << #arr << " = "; for (int i=0;i<len;i++)cout << arr[i] << " \n"[i == len-1]


using namespace std;

int N, W;
int KMP[MAXN];
int arr[2*MAXN];

void computeKMP(){
    int i = 1, j = 0;
    while (i <= W+N){
        if (arr[i] == arr[j]){
            KMP[i++] = ++j;
        } else if (j == 0){
            KMP[i++] = 0;
        } else {
            j = KMP[j - 1];
        }
    }
}

//
//  1 2 3 4 5
//  <0,0> <0,1> <0,1> <0,1> <0,1>

// 1 2
// <0,0> <0,1>

    // 0       1            0      1     1     1     1
    // 0       0
    // <1,1>  <1,2>        <1,1>  <1,2> <1,2> <1,2> <1,2>
    // <0,0>  <0,0>        <1,1>  <1,2> <1,1>  
// [<0,0>] <0,1> <E,E> [<0,0>] <0,1> <0,1> <0,1> <0,1>
// [<1,1>] <1,2> <E,E> [<1,1>] <1,2> <1,2> <1,2> <1,2>


int main(){

    scanf("%d %d", &N, &W);

    for (int i = W+1; i <= N+W; i++){
        scanf("%d", &arr[i]); 
    }
    for (int i = 0; i < W; i++){
        scanf("%d", &arr[i]); 
    }  

    debug(arr, W+N);

    for (int i = N+W; i > W; i--){
        arr[i] = arr[i] - arr[i-1];
    }
    for (int i = W-1; i > 0; i--){
        arr[i] = arr[i] - arr[i-1];
    }

    arr[0] = 0, arr[W+1] = 0;    
    arr[W] = INT_MIN;
    computeKMP();

    debug(arr, W+N+1);
    debug(KMP, W+N+1);


    int cnt = 0;

    for (int i = W+1; i <= N+W; i++){
        if (KMP[i] == W){
            cnt++;
        }
    }
    

    printf("%d\n", cnt);

    return 0;
}