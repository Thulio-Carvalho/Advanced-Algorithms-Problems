#include <bits/stdc++.h>
#define MAXN 55

using namespace std;

int n, m, k;
int arr[MAXN];

int main(){
    cin >> n >> m >> k;


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + n, greater<int>());

    int sockets = k;
    int active_slots = sockets;
    int i = 0;
    int answer = i;

// s = 1
// 3 2 1 1 1
// a 
    while (true) {
        if (active_slots >= m) {
            answer = i;
            break;
        }
        if (sockets > 0) {
            sockets--;
            active_slots += arr[i];
            active_slots--;
        } else {
            active_slots += arr[i];
            active_slots--;
            active_slots--;
        }
        i++;
        if(i >= n) {
            answer = -1;
            break;
        }
    }

    cout << answer << endl;
    
    return 0; 
}