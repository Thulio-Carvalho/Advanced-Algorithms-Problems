#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

typedef long long ll;

int T, N, C, arr[MAXN];

ll tree[4*MAXN], lazy[4*MAXN];

ll mergeValues(ll x, ll y){
  return x + y;
}

void build(int id, int l, int r){
  if(l == r){
    tree[id] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id*2, l, mid);
  build(id*2 - 1, mid + 1, r);
  tree[id] = mergeValues(tree[id*2], tree[id*2]);
}

void update(int id, int l, int r, int x, int y, int val){
  if (lazy[id] != 0){
    tree[id] += lazy[id] * (r-l+1);
    if (l != r){
      lazy[tree[id*2]] += lazy[id];
      lazy[tree[id*2+1]] += lazy[id];
    }
    lazy[id] = 0;
  }
  if (x > r || y < l) return;
  if (x <= l && y >= r){
    tree[id] += val * (r - l +1);
    if(l != r){
      lazy[id*2] += val;
      lazy[id*2+1] += val;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(id*2, l, mid, x, y, val);
  update(id*2 + 1, mid + 1, r, x, y, val);
  tree[id] = mergeValues(tree[id*2], tree[id*2+1]);
}

ll query(int id, int l, int r, int x, int y){
  if (x > r || y < l) return 0;
  if (lazy[id] != 0){
    tree[id] += lazy[id] * (r -l + 1);
    if(l != r){
      lazy[id*2] += lazy[id];
      lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
  }
  if (x <= l && y >= r) return tree[id];
  int mid = (l + r) / 2;
  return mergeValues(query(id*2, l, mid, x, y),
                    query(id*2 + 1, mid + 1, r, x, y));
}

int main(){
  scanf("%d", &T);
  while (T--){
    scanf("%d %d", &N, &C);
    memset(lazy, 0, sizeof lazy);
    memset(tree, 0, sizeof tree);
    build(1, 1, N);
    while (C--){
      int type, p, q, v;
      scanf("%d", &type);
      if(type == 0){
        scanf("%d %d %d", &p, &q, &v);
        update(1, 1, N, p, q, v);                   // TODO code function update
      } else{
        scanf("%d %d", &p, &q);
        ll ans = query(1, 1, N, p, q);              // TODO code function query
        printf("%lld\n", ans);
      }
    }
  }
}
