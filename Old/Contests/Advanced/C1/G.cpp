#include <bits/stdc++.h>

using namespace std;

int N;
int arr[7];

int main(){
  scanf("%d", &N);
  for(int n = 0; n < N; n++){
    string aux;
    cin >> aux;
    for(int i = 0; i < 7; i++){
      if (aux[i] == '1'){
        arr[i]++;
      }
    }
  }
  int ans = arr[0];
  for (int i = 0; i < 7; i++){
    if (arr[i] > ans) ans = arr[i];
  }
  printf("%d\n", ans);
  return 0;
}
