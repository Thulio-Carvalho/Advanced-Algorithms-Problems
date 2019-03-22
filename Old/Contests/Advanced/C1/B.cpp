#include <bits/stdc++.h>

using namespace std;

vector<int> merged[200100];
int n, arr[200100];
bitset<200100> used;
int pointer[200100];
int previous[200100];
int cnt = 1;

void printAll(){
  for (int i = 0; i < cnt; i++){
    for(int j = 0; j < merged[i].size(); j++){
      if (j == merged[i].size() - 1){
        printf("%d", merged[i][j]);
      } else {
        printf("%d ", merged[i][j]);
      }
    }
    if (i == cnt-1) printf("\n");
  }
}
void readAll();

int firstUnusedIndex(){
  for(int i = 0; i < n; i++){
    if(!used[i]) return i;
  }
  return -1;
}

int tryPointers(int cnt, int index){
  for (int i = 0; i < cnt; i++){
    if (arr[pointer[i]] - arr[pointer[i] - 1] > previous[i]){
      return i;
    }
  }
  return -1;
}




int main(){
  readAll();

  int master = 0;
  int index = 1;
  previous[0] = arr[0];
  while(master <= n){   // CAREFUL

    int actualPointer = tryPointers(cnt, index);
    if (actualPointer == -1){
      pointer[cnt] = index;
      previous[cnt] = arr[index];
      merged[cnt].push_back(arr[index]);
      cnt++;
    } else{
      int pt = pointer[actualPointer];
      merged[actualPointer].push_back(arr[pt]);
      pointer[actualPointer]++;
    }

    master++;
  }

  printAll();
  return 0;
}




void readAll(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
}
