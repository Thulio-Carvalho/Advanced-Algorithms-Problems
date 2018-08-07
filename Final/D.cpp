#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int N, arr[MAXN];

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  int a, b, c;
  a = arr[0];
  b = arr[1];
  c = arr[2];

  for (int num : arr) { 
    if (num < a) { 
      a = num; 
    } else if (num < b) { 
      b = num;
    } else if (num < c) {
      c = num;
    }
  }

  map<int, vector<int>> indexes;

  for (int i = 0; i < N; i++) {
    int actual = arr[i];

    if (actual == a) { 
      indexes[a].push_back(i);
    } else if (actual == b){
      indexes[b].push_back(i);
    } else if (actual == c){
      indexes[c].push_back(i);
    }
  }

  

  return 0;
}