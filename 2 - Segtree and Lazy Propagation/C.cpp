#include <bits/stdc++.h>
#define NUM_BITS 20
#define MAXN 100100

using namespace std;

typedef long long ll;

int arr[MAXN], tree[NUM_BITS][4*MAXN], lazy[NUM_BITS][4*MAXN];
int n, m;

void printTree(int p){
  cout << endl << "ARVORE P=" << p << "" << endl << endl;
  for (int i = 8; i < 17; i++) cout << tree[p][i] << " ";
  cout << endl << " ";
  for (int i = 4; i < 8; i++) cout << tree[p][i] << "   ";
  cout << endl << "    ";
  for (int i = 2; i < 4; i++) cout << tree[p][i] << "     ";
  cout << endl << "        ";
  cout << tree[p][1];
}

void printTrees(){
  for (int p = 0; p < NUM_BITS; p++){
    cout << endl;
    printTree(p);
  }
}

void build(int id, int l, int r, int p){
  if (l == r){
    if((1 << p) & arr[l]) tree[p][id] = 1;
    cout << "ID=" << id << " / " <<  tree[p][id] << " ";
    return;
  }
  int mid = (l + r) / 2;
  build(id*2, l, mid, p);
  build(id*2+1, mid+1, r, p);
  cout << endl;
  tree[p][id] = tree[p][id*2] + tree[p][id*2+1];
  cout << "ID=" << id << " / " <<  tree[p][id] << " ";
}
// Builds all Segtrees
void build(int n){
  for (int p = 0; p < NUM_BITS; p++){
    cout << endl << endl;
    build(1, 1, n, p);
  }
}

void doLazy(int id, int p){
  if (lazy[p][id]){
    lazy[p][id*2] = lazy[p][id];
    lazy[p][id*2+1] = lazy[p][id];
  }
}
// Update xors the interval
void update(int id, int l, int r, int x, int y, int p, int val){
  doLazy(id, p);
  if (l > y || r < x) return;
  if (l >= x && r <= y){
    lazy[p][id] = lazy[p][id] ^ val;    // Xor current lazy with value
    doLazy(id, p);
    return;
  }
  int mid = (l + r) / 2;
  update(id*2, l, mid, x, y, p, val);
  update(id*2, mid+1, r, x, y, p, val);
}

void update(int n, int l, int r, int val){
  for (int p = 0; p < NUM_BITS; p++){
    update(1, 1, n, l, r, p, val);
  }
}

int query(int id, int l, int r, int x, int y, int p){
  doLazy(id, p);
  if (l > y || r < x) return 0;
  if (l >= x && r <= y) return tree[p][id] ^ lazy[p][id];
  int mid = (l + r) / 2;
  return query(id*2, l, mid, x, y, p) +
         query(id*2+1, mid+1, r, x, y, p);
}

ll query(int n, int l, int r){
  ll answer = 0;
  for(int p = 0; p < NUM_BITS; p++){
    answer += (1 << p) * query(1, 1, n, l, r, p);
  }
  return answer;
}

int main(){
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  build(n);
  // printTrees();
  scanf("%d", &m);
  for (int i = 0; i < m; i++){
    int t, l, r, val;
    scanf("%d %d %d", &t, &l, &r);
    if (t == 1){
      printf("%lld\n", query(n, l, r));
    } else{
      scanf("%d", &val);
      update(n, l, r, val);
    }
    // printTrees();
  }
  return 0;
}
