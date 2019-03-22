#include <bits/stdc++.h>
#define MAXN 200100
#define MAXV 10000010

using namespace std;

typedef long long ll;

int t, n, arr[MAXN], counter[MAXV], BIT[MAXV];

void update(int index, int val){
  while (index <= MAXV){
    BIT[index] += val;
    index += (index & -index);
  }
}

ll acess(int index){
  ll total = 0;
  while (index > 0){
    total += BIT[index];
    index -= (index & -index);
  }
  return total;
}
// acess range, left and right included
ll acess(int l, int r){
  return acess(r) - acess(l-1);
}

int main(){
  scanf("%d", &t);
  for (int test = 0; test < t; test++){
    ll answer = 0;
    memset(BIT, 0, sizeof BIT);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &arr[i]);
      counter[arr[i]]++;
      update(arr[i], 1);
      answer += acess(arr[i]+1, MAXV);
    }
    printf("%lld\n", answer);
  }


  return 0;
}
