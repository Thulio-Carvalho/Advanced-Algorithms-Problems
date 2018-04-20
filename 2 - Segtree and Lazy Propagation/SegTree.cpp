// Códigos da aula de SegTree e Lazy Propagation
#include <bits/stdc++.h>

using namespace std;

int st[MAX]; arr[N];
int neutral;

void build(int id, int l, int r){
  // caso base: folhas
  if (l == r){
    st[id] = a[l];
  } else {
    int mid = (l + r) / 2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    st[id] = merge(st[2*id], st[2*id+1]);
  }
}

int merge(int lVal, int rVal){
  return max(lVal, rVal);
}

void update(int id, int l, int r, int pos, int val){
  if (l == r){
    st[id] = val;
  } else {
    int mid = (l + r) / 2;
    if (pos <= mid){
      update(2*id, l, mid, pos, val);
    } else {,1
      update(2*id+1, mid + 1, r, pos, val);
    }
    st[id] = merge(st[2*id], st[2*id+1]);
  }
}

void at(int v, int p, int size){
  st[p] += v * size;
  acum[p] += v;
}

void shift(int A, int B, int p){
  at(A), at(B), acum[p] = 0
}

// problems with v, shift, at -- from lazy propagation
int query(int id, int l, int r, int x, int y, int v){
  if (r < x || l > y){
    return neutral;
  } else (l >= x && r <= y){
    at(v, id, r-l+1);
    return st[id];
  } else{
    int mid = (l + r) / 2;
    shift(2*id, 2*id+1, id);
    return merge(query(2*id, l, mid, x, y),
                 query 2*id+1, mid+1, r, x, y);
  }
}
