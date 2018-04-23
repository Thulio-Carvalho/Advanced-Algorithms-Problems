#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

typedef long long ll;

int arr[MAXN];
ll tree[4*MAXN];
int N, K;

void putVal(int id, int val){
  if(val > 0) tree[id] = 1;
  if(val < 0) tree[id] = -1;
  if(val == 0) tree[id] = 0;
}

void build(int id, int l, int r){
  if (l == r){
    putVal(id, arr[l]);
    return;
  }
  int mid = (l + r) / 2;
  build(id*2, l, mid);
  build(id*2+1, mid+1, r);
  tree[id] = tree[id*2] * tree[id*2+1];
}

void update(int id, int l, int r, int pos, int val){
  if (l == r){
    putVal(id, val);
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid){
    update(id*2, l, mid, pos, val);
  } else{
    update(id*2+1, mid+1, r, pos, val);
  }
  tree[id] = tree[id*2] * tree[id*2+1];
}

ll query(int id, int l, int r, int x, int y){
  if (l > y || r < x) return 1;
  if (x <= l && y >= r){
    return tree[id];
  }
  int mid = (l + r) / 2;
  return (query(id*2, l, mid, x, y) * query(id*2+1, mid+1, r, x, y));
}

int main(){
  while(scanf("%d %d", &N, &K) != EOF){
    vector<char> ans;
    for (int i = 0; i < N; i++) {
      scanf("%d", &arr[i]);
    }
    build(1, 0, N-1);

    while(K--){
      char type;
      int x, y;
      scanf(" %c %d %d", &type, &x, &y);
      if (type == 'C'){
        update(1, 0, N-1, x-1, y);
      } else{
        ll ret = query(1, 0, N-1, x-1, y-1);
        if (ret > 0) ans.push_back('+');
        if (ret < 0) ans.push_back('-');
        if (ret == 0) ans.push_back('0');
      }
    }
    for (int i = 0; i < ans.size(); i++){
      printf("%c", ans[i]);
    } printf("\n");

  }
  return 0;
}
