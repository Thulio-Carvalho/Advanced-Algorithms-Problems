#include <bits/stdc++.h>
#define MAXN 100010
#define debug(arr, len) cerr << #arr << " = "; for (int i=0;i<len;i++)cout << arr[i] << " \n"[i == len-1]


using namespace std;

int N, W;
int KMP[MAXN];
int word[MAXN], text[MAXN];
int difWord[MAXN], difText[MAXN];


void computeKMP(){
    int i = 1, j = 0;
    while (i < W){
        if (word[i] == word[j]){
            KMP[i++] = ++j;
        } else if (j == 0){
            KMP[i++] = 0;
        } else {
            j = KMP[j - 1];
        }
    }
}

int diff(int a, int b){
    return a - b;
}

int searchOccurrences(){
    int cnt = 0;
    int i = 0, k = 0;
    while (1){
        if (difText[i] == difWord[k]){
            i++; k++;
        } else {
            if (k > 0){
                k = KMP[k];
            } 
        }
    }
    
   
}

int main(){

    scanf("%d %d", &N, &W);

    for (int i = 0; i < N; i++){
        scanf("%d", &text[i]); 
    }
    for (int i = 0; i < W; i++){
        scanf("%d", &word[i]); 
    }   

    computeKMP();
    debug(KMP, W);
    int ans = searchOccurrences();

    printf("%d\n", ans);

    return 0;
}