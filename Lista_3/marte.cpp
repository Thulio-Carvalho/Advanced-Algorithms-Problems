#include <bits/stdc++.h>
#define MAXN 100100

using namespace std;

typedef long long ll;

int N;

ll tree[4*MAXN];
int arr[MAXN];

ll mergeValues(ll x, ll y){
  return x + y;
}

void build(int id, int l, int r){
  if (l == r) {
    tree[id] = arr[l];
    return;
  }
  int mid = (l + r) / 2;
  build(id*2, l, mid);
  build(id*2 + 1, mid + 1, r);

  tree[id] = mergeValues(tree[id*2], tree[id*2+1]);
}

void update(int id, int l, int r, int pos, ll val){
  if (l == r) {
    tree[id] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (pos <= mid) {
    update(id*2, l, mid, pos, val);
  } else {
    update(id*2 + 1, mid + 1, r, pos, val);
  }
  tree[id] = mergeValues(tree[id*2], tree[id*2+1]);
}

ll query(int id, int l, int r, int x, int y){
  if (x > r || y < l) return 0;
  if (x <= l && y >= r) {
    return tree[id];
  }
  int mid = (l + r) / 2;
  return mergeValues(query(id*2, l, mid, x, y),
                    query(id*2 + 1, mid + 1, r, x, y));
}

int main(){

  scanf("%d", &N);
  memset(tree, 0, sizeof tree);

  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
  }

  build(1, 1, N);
  char type;
  int pos;

  while (scanf(" %c %d", &type, &pos) != EOF) {
    if (type == 'a') {
      update(1, 1, N, pos, 0);
    } else if (type == '?') {
      ll ans = query(1, 1, N, 1, pos - 1);
      cout << ans << endl;
    }
  }

}
