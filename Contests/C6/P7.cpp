#include <bits/stdc++.h>

using namespace std;

bool match(int a, int b){
    return a == b;
}
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int last = 0;
    int groups = 1;

    for (int i = 1; i < n; i++){
        if (!match(arr[i], arr[last])){
            groups++;
        }
        last++;
    } 

    printf("%d\n", groups);

    return 0;
}