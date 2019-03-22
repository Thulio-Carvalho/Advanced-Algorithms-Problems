#include <bits/stdc++.h>

using namespace std;

int N, R;
int ret[1010];
bitset <1010> alive;

int main(){
  scanf("%d %d", &N, &R);
  for (int i = 0; i < R; i++){
    scanf("%d", &ret[i]);
  }
  sort(ret, ret + R);
  for (int i = 0; i < R; i++){
    alive.set(ret[i]);
  }
  vector<int> ans;
  for (int i = 1; i <= N; i++){
    if (!alive[i]) ans.push_back(i);
  }
  if(N != R){
    for (int i = 0; i < ans.size(); i++){
      if (i == ans.size()-1){
        printf("%d\n", ans[i]);
      } else{
        printf("%d ", ans[i]);
      }
    }
  } else{
    printf("*\n");
  }
  return 0;
}
