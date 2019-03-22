#include <bits/stdc++.h>

using namespace std;

int daysOff(int n, int start){
    int day = start;
    int off = 0;
    for (int i = 1; i <= n; i++){
        if (day%(6) == 0){
            off++;
        } 
        if (day%(7) == 0){
            off++;
            day = 0;
        } 
        // cout << day << endl;
        // cout << "offs yet = " << off << endl;
        day++;
    }
    return off;
}
int main(){
    int n;
    scanf("%d", &n);

    int min, max;
    min = daysOff(n, 1);
    max = min;
    for (int i = 2; i <= 7; i++){
        int cnt = daysOff(n, i);
        if (cnt > max){
            max = cnt;
        } 
            
        if (cnt < min) min = cnt;
    }

    printf("%d %d\n", min, max);


    return 0;
}