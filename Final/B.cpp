#include <bits/stdc++.h>
#define BIT_SIZE 32
#define MAXN 100010

using namespace std;

int arr[MAXN];
int N, T;

struct Node {
  int value;
  Node* bits[2];
};

bool getBit(int value, int index) {
  return value & (1 << index);
}

Node *createNode(){
  Node *actual = new Node;
  actual->bits[0] = actual->bits[1] = NULL;
  actual->value = 0;
  return actual;
}
void insert(Node *root, int actualXor){
  
  Node *actual = root;

  for (int i = BIT_SIZE - 1; i >= 0; i--){

    bool bit = getBit(actualXor, i);

    if (actual->bits[bit] == NULL) {
      actual->bits[bit] = createNode();    
    }
    actual = actual->bits[bit];
  }

  actual->value = actualXor;
}

int query(Node *root, int actualXor) {

  Node *actual = root;

  for (int i = BIT_SIZE - 1; i >= 0; i--) { 
    bool bit = getBit(actualXor, i);

    if (actual->bits[1 - bit] != NULL){
      actual = actual->bits[1 - bit];
    } else if (actual->bits[bit] != NULL) {
      actual = actual->bits[bit];
    }
  }

  return (actual->value) ^ actualXor;
}

int solve(){

  Node *root = createNode();
  insert(root, 0);

  int ret = INT_MIN;
  int actualXor = 0;

  for (int i = 0; i < N; i++) {
    actualXor ^= arr[i];
    insert(root, actualXor);

    ret = max(ret, query(root, actualXor));
  }

  return ret;
}
int main(){

  scanf("%d", &T);
  for (int t = 0; t < T; t++) {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) { 
      scanf("%d", &arr[i]);
    }

    cout << solve() << endl;
  }

  return 0;
}