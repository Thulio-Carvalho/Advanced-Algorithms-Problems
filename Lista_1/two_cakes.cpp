#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

ii arr[MAXN];
int N;
int posA, posB, cnt;
ll ans;

void read() {
    scanf("%d", &N);

    for (int i = 1; i <= 2*N; i++) {
        int index;
        scanf("%d", &index);

        if (arr[index].first != 0) {
            arr[index].second = i;
        } else {
            arr[index].first = i;
        }
    }
}


int main(){
    read();

    posA = 1;
    posB = 1;
    ans = 0;

    bool finished = false;

    while(!finished) {
        int f = arr[cnt + 1].first;
        int s = arr[cnt + 1].second;

        if (abs(posA - f) + abs(posB - s) < abs(posB - f) + abs(posA - s)) {
            ans += abs(posA - f) + abs(posB - s);
            posA = f;
            posB = s;
        } else {
            ans += abs(posB - f) + abs(posA - s);
            posB = f;
            posA = s;
        }

        cnt++;
        if (cnt == N){
            finished = true;
        }
    }

    cout << ans << endl;    

    return 0;
}