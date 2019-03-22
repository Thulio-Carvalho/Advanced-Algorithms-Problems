#include <bits/stdc++.h>

using namespace std;

bool isRed(int rating){
    return rating >= 2400;
}

int main(){
    int n;
    cin >> n;
    bool good = false;

    for (int i = 0; i < n; i++){
        string name;
        int before, after;
        
        cin >> name >> before >> after;

        if (isRed(before)){
            if ((after - before) > 0){
                good = true;
            }
        }
    }

    if (good) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}