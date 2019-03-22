#include <bits/stdc++.h>

using namespace std;

int N, arr[110];

int main(){
  scanf("%d", &N);
  for (int n = 0; n < N; n++){
    scanf("%d", &arr[n]);
  }
  int progression = arr[1] - arr[0];
  bool progressive = true;
  for (int i = 1; i < N; i++){
    if(arr[i] - arr[i-1] != progression) progressive = false;
  }
  if(progressive){
    printf("%d\n", arr[N-1] + progression);
  } else{
    printf("%d\n", arr[N-1]);
  }
  return 0;
}
