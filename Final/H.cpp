// #include <bits/stdc++.h>
// #define MAXN 100100

// using namespace std;

// typedef long long ll;

// int arr[MAXN], tree[4*MAXN], lazy[4*MAXN];
// int n, m;


// void build(int id, int l, int r){

//   if (l == r){
//     tree[id] = 0;
//     return;
//   }

//   int mid = (l + r) / 2;
//   build(id*2, l, mid);
//   build(id*2+1, mid+1, r);

//   tree[id] = tree[id*2] + tree[id*2+1];
// }

// void build(int n){
//   build(1, 1, n);
// }

// void doLazy(int id, int l, int r){
//   if (lazy[id]){
//     tree[id] += lazy[id];

//     if (l != r){
//         lazy[id*2] = lazy[id] + lazy[id*2];
//         lazy[id*2+1] = lazy[id] + lazy[id*2+1];
//     }
//     lazy[id] = 0;
//   }
// }

// void update(int id, int l, int r, int x, int y, int val){
//   doLazy(id, l, r);

//   if (l > y || r < x) return;

//   if (l >= x && r <= y){
//     lazy[id] = lazy[id] + val;   
//     doLazy(id, l, r);
//     return;
//   }

//   int mid = (l + r) / 2;

//   update(id*2, l, mid, x, y, val);
//   update(id*2, mid+1, r, x, y, val);

//   tree[0][id]= tree[0][id*2] + tree[0][id*2+1];
//   tree[1][id] = tree[1][id*2] + tree[1][id*2+1];
// }

// int query(int id, int l, int r, int x, int y){
//   doLazy(id, l, r);

//   if (l > y || r < x) return 0;

//   if (l >= x && r <= y){
//     return tree[0][id];
//   }

//   int mid = (l + r) / 2;
//   return query(id*2, l, mid, x, y) +
//          query(id*2+1, mid+1, r, x, y);
// }


// int main(){

//   scanf("%d %d", &n, &m);

//   for (int i = 1; i <= n; i++) {
//     arr[i] = i;
//   }

//   build(n);

//   for (int i = 0; i < m; i++){

//     int type, l, r, val;
//     scanf("%d %d %d", &type, &l, &r);
    
//     if (type == 1) {

//       scanf("%d", &val);
//       update(1, 1, n, l, r, val);

//     } else {

//       printf("%d\n", query(1, 1, n, l, r));
//     }
//   }

//   return 0;
// }