#include <bits/stdc++>
#define MAXN 100100

using namespace std;

typedef long long ll;

int T, N, C, arr[MAXN];

ll tree[4*MAXN];

void build(int id, int l, int r){
  if(l == r){
    tree[id] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id*2, l, mid);
  build(id*2 - 1, mid + 1, r);
  tree[id] = mergeValues(tree[id*2], tree[id*2])
}

void update(int id, int l, int r, int x, int y, int val){
  // TODO code function
}

ll query(){
  // TODO code function
}

int main(){

  scanf("%d", &T);
  while (T--){
    scanf("%d %d", &N, &C);
    while (N--){
      int type, p, q, v;
      scanf("%d", &type);
      if(type == 0){
        scanf("%d %d %d", &p, &q, &v);
        update(p, q, v);                   // TODO code function update
      } else (type == 1){
        scanf("%d %d", &p, &q);
        ll ans = query(p, q);              // TODO code function query
        printf("%lld\n", ans);
    }
  }
}
