#include <bits/stdc++.h>
#define MAXN 100007
#define MAXLOG 20

using namespace std;

typedef pair <int, int> ii;

int N, Q, arr[MAXN];
int sp[MAXLOG][MAXN];

vector <ii> queries;

void build();
int access(int, int);
void read();
void print();

int main(){
    read();
    build();
    print();


    return 0;
}

void read(){
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

void build(){
    for (int j = 0; j < N; j++) {
        sp[0][j] = j;
    }
    for (int i = 1; (1 << i) < N; i++){
        for (int j = 0; j + (1 << i) < N; j++) {
            if (arr[sp[i-1][j]] < arr[sp[i-1][j + (1 << (i-1))]]){
                sp[i][j] = sp[i-1][j];
            } else {
                sp[i][j] = sp[i-1][j + (1 << (i-1))];
            }
        }
    }
}

void print(){
    for (int j = 0; j < N; j++) {
        cout << arr[sp[0][j]] << " ";
    } cout << endl;
    for (int i = 0; (1 << i) < N; i++){
        for (int j = 0; j + (1 << i) < N; j++) {
            cout << arr[sp[i][j]] << " ";
        } cout << endl;
    }
}

int access(int l, int r){
  if(l > r) swap(r, l);
  int size = r - l + 1;
  int logOfSize = __builtin_clz(1) - __builtin_clz(size);
  return min(arr[sp[logOfSize][l]], arr[sp[logOfSize][r - (1 << logOfSize) + 1 ]]);
}