#include <bits/stdc++.h>
#define MAX 100010

using namespace std;
typedef pair<int, int> ii;

vector<ii> tree[MAX];
int parent[20][MAX], minTable[20][MAX], maxTable[20][MAX];
int level[MAX], logs[MAX];
int n, lower, higher;

void computeLog() {
  for (int i = 2; i <= n; i++) {
    logs[i] = logs[i / 2] + 1;
  }
}

void build() {
  computeLog();
  for (int j = 1; j <= logs[n]; j++) {
    for (int i = 1; i <= n; i++) {
      if (parent[j - 1][i]) {

        parent[j][i] = parent[j - 1][parent[j - 1][i]];
        maxTable[j][i] =
            max(maxTable[j - 1][parent[j - 1][i]], maxTable[j - 1][i]);
        minTable[j][i] =
            min(minTable[j - 1][parent[j - 1][i]], minTable[j - 1][i]);
      }
    }
  }
}

void DFS(int node, int p) {
  for (int i = 0; i < tree[node].size(); i++) {

    if (tree[node][i].first != p) {

      level[tree[node][i].first] = 1 + level[node];
      parent[0][tree[node][i].first] = node;

      maxTable[0][tree[node][i].first] = tree[node][i].second;
      minTable[0][tree[node][i].first] = tree[node][i].second;

      DFS(tree[node][i].first, node);
    }
  }
}

int LCA(int u, int v) {

  if (level[u] < level[v]) {
    swap(u, v);
  }

  lower = INT_MAX;
  higher = INT_MIN;

  for (int i = logs[n]; i >= 0; i--) {
    if ((level[u] - (1 << i)) >= level[v]) {
      lower = min(lower, minTable[i][u]);
      higher = max(higher, maxTable[i][u]);
      u = parent[i][u];
    }
  }

  if (u == v)
    return u;

  for (int i = logs[n] - 1; i >= 0; i--) {
    if (parent[i][u] != parent[i][v]) {
      lower = min(lower, min(minTable[i][u], minTable[i][v]));
      higher = max(higher, max(maxTable[i][u], maxTable[i][v]));
      u = parent[i][u];
      v = parent[i][v];
    }
  }

  lower = min(lower, min(minTable[0][u], minTable[0][v]));
  higher = max(higher, max(maxTable[0][u], maxTable[0][v]));

  return parent[0][u];
}

int main() {
  int K, A, B, C;

  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d %d", &A, &B, &C);
    tree[A].push_back(make_pair(B, C));
    tree[B].push_back(make_pair(A, C));
  }
  scanf("%d", &K);

  minTable[0][0] = INT_MAX;
  minTable[0][1] = INT_MAX;

  DFS(1, 1);

  build();

  int ans;

  for (int i = 0; i < K; i++) {
    scanf("%d %d", &A, &B);
    LCA(A, B);
    printf("%d %d\n", lower, higher);
  }

  return 0;
}