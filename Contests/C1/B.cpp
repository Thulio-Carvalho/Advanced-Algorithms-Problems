#include <bits/stdc++.h>

using namespace std;

bitset<1010> matrix[1010];
int n, m, cnt;

bool canMove(int dir, int i, int j){
  // 0 = up; 1 = right; 2 = down; 3 = left
  // cout << "actual pos: i=" << i << " // j=" << j << endl;
  // cout << "dir = " << dir << endl;
  int adderI = 0;
  int adderJ = 0;

  switch (dir) {
    case 0: adderI--;
            break;
    case 1: adderJ++;
            break;
    case 2: adderI++;
            break;
    case 3: adderJ--;
            break;
  }
  // cout << "adderI = " << adderI << " // adderJ = " << adderJ << endl;
  // if(i + adderI < 0 || i + adderI > n) return false;
  // if(j + adderJ < 0 || j + adderJ > m) return false;
  if(matrix[i + adderI][j + adderJ]){
    // cout << "valores: i = " << i + adderI
         // << " // j = " << j + adderJ << endl;
    // cout << matrix[i+adderI][j+adderJ] << endl;
    return false;
  }
  return true;
}

void move(int i, int j){
  // moving up
  int newI = i;
  int newJ = j;
  while(canMove(0, newI, newJ)){
    newI--;
    cnt++;
    // cout << newI << " " << newJ << endl;
    // cout << "movin up..." << endl;
  }
  // moving right
  newI = i;
  newJ = j;
  while(canMove(1, newI, newJ)){
    newJ++;
    cnt++;
    // cout << newI << " " << newJ << endl;
    // cout << "movin right..." << endl;
  }
  // moving down
  newI = i;
  newJ = j;
  while(canMove(2, newI, newJ)){
    newI++;
    cnt++;
    // cout << newI << " " << newJ << endl;
    // cout << "movin down..." << endl;
  }
  // moving left
  newI = i;
  newJ = j;
  while(canMove(3, newI, newJ)){
    newJ--;
    cnt++;
    // cout << newI << " " << newJ << endl;
    // cout << "movin left..." << endl;
  }
}

int main(){
  for(int i = 0; i < 1010; i++){
    matrix[i].set();
  }
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int aux;
      scanf("%d", &aux);
      matrix[i][j] = aux;
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (matrix[i][j]){
        // cout << "debug123" << endl;
        move(i, j);
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
