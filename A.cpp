#include <bits/stdc++.h>

using namespace std;

int N, M, x, y;
int arr[100010];
int sp[20][100010];

typedef long long ll;

void build();
int acess(int, int);

int main(){

  scanf("%d", &N);
  for (int i = 0; i < N; i++){
    scanf("%d", &arr[i]);
  }
  build();

  scanf("%d %d %d", &M, &x, &y);
  ll ans = 0;
  for (int i = 1; i <= M; i++){
    ans += acess(x, y);
    x = (x + 7) % (N - 1);
    y = (y + 11) % N;
  }
  printf("%lld\n", ans);
  return 0;
}

void build(){
  for (int j = 0; j < N; j++){
    sp[0][j] = j;
  }
  for (int i = 1; (1 << i) <= N; i++){
    for (int j = 0; j + (1 << i) <= N; j++){
      if (arr[sp[i-1][j]] > arr[sp[i-1][j + (1 << (i-1))]]){
        sp[i][j] = sp[i-1][j];
      } else {
        sp[i][j] = sp[i-1][j + (1 << (i-1))];
      }
    }
  }
}

int acess(int l, int r){
  if(l > r) swap(r, l);
  int size = r - l + 1;
  int logOfSize = __builtin_clz(1) - __builtin_clz(size);
  return max(arr[sp[logOfSize][l]], arr[sp[logOfSize][r - (1 << logOfSize) + 1 ]]);
}
