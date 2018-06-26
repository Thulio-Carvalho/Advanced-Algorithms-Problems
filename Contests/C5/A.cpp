#include <bits/stdc++.h>

using namespace std;

int main(){
    int k;
    string n;

    cin >> k;
    cin >> n;

    int values[n.size()];
    int i = 0;
    int sum = 0;

    for (char val : n){
        val = (int) val - 48;
        sum += val;
        values[i] = val;
        i++;
    }
    if (sum >= k){
        cout << 0 << endl;;
    } else{

        int cnt = 0;
        sort(values, values + i+1);
        for (int val : values){
            sum += 9 - val;
            cnt++;
            if (sum >= k){
                cout << cnt << endl;
                break;
            }
        }
    }

    return 0;
}