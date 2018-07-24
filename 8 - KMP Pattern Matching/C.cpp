#include <bits/stdc++.h>
#define MAXN 200020
#define debug(arr, len) cerr << #arr << " = "; for (int i=0;i<len;i++)cout << arr[i] << " \n"[i == len-1]


using namespace std;

int N, W;
int KMP[2*MAXN];
long long arr[2*MAXN];

void computeKMP(){

    int i = 0, j = -1;
    KMP[0] = -1;
    while(i < W+N){
        while(j > 0 && arr[i] != arr[j]) j = KMP[j];
        KMP[++i] = ++j;
    }

}

int main(){

    scanf("%d %d", &N, &W);

    for (int i = W; i < N+W; i++){
        scanf("%lld", &arr[i]); 
    }
    for (int i = 0; i < W; i++){
        scanf("%lld", &arr[i]); 
    }  
    for (int i = N+W-1; i > W; i--){
        arr[i] = arr[i] - arr[i-1];
    }
    for (int i = W-1; i > 0; i--){
        arr[i] = arr[i] - arr[i-1];
    }

    arr[0] = 0;   
    arr[W] = -1000000007;

    // if(W == 1){ // obviamente nao eh gambiarra
        // cout << N << endl;

    // } else {
        computeKMP();
        int oi = 1;
        // debug(arr, W+N+10);
        // debug(KMP, W+N+10);


        int cnt = 0;

        for (int i = W+1; i <= N+W; i++){
            if (KMP[i] >= W){
                cnt++;
            }
        }
        

        printf("%d\n", cnt);
    // }

    return 0;
}