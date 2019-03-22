#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;

typedef pair<int, int> ii;

int arr[MAXN], N, Q;
ii segTree[4*MAXN];

ii mergePairs(ii left, ii right){
  int tempArr1[2] = {left.first, left.second};
  int tempArr2[2] = {right.first, right.second};
  int solvedArr[4];
  int i = 0;
  int j = 0;
  int k = 0;
  while(i < 2 && j < 2){
    if(tempArr1[i] >= tempArr2[j]){
      solvedArr[k] = tempArr1[i];
      i++;
    } else{
      solvedArr[k] = tempArr2[j];
      j++;
    }
    k++;
  }
  return make_pair(solvedArr[0], solvedArr[1]);
}

void build(int id, int l, int r){
  if (l == r) {
    segTree[id] = make_pair(arr[l], 0);
    return;
  }
  int mid = (l + r) / 2;
  build(id*2, l, mid);
  build(id*2 + 1, mid + 1, r);

  segTree[id] = mergePairs(segTree[id*2], segTree[id*2+1]);
}

void update(int id, int l, int r, int pos, int val){
    if (l == r){
      segTree[id] = make_pair(val, 0);
      return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid){
      update(id*2, l, mid, pos, val);
    } else{
      update(id*2 + 1, mid + 1, r, pos, val);
    }
    segTree[id] = mergePairs(segTree[id*2], segTree[id*2+1]);
}

ii query(int id, int l, int r, int x, int y){
  if (y < l || x > r) return make_pair(0, 0);
  if (x <= l && r <= y) return segTree[id];
  int mid = (l + r) / 2;
  return mergePairs(query(id*2, l, mid, x, y),
               query(id*2 + 1, mid+1, r, x, y));
}
int main(){
  scanf("%d", &N);
  for (int i = 1; i <= N; i++){
    scanf("%d", &arr[i]);
  }
  scanf("%d", &Q);
  build(1, 1, N);
  for (int q = 0; q < Q; q++){
    char type;
    int x, y;
    scanf(" %c %d %d", &type, &x, &y);
    if (type == 'U') update(1, 1, N, x, y);
    else{
      if (type == 'Q'){
        ii ansPair = query(1, 1, N, x, y);
        int ans = ansPair.first + ansPair.second;
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
