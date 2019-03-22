#include <bits/stdc++.h>
#define MAXM 10010
#define MAXN 1010

using namespace std;

int N, M;

struct Node {

  int height;

  vector<Node> parents;
  deque<Node> children;

  Node() {}
  Node(int h) : height(h) {}

  bool operator>(Node other) const { return height > other.height; }
  bool operator<(Node other) const { return height < other.height; }

  void addChild(Node node) {
    children.push_back();
    
    while (i < children.size() && children[i] > node) i++;
    
  }

  void addParent(Node node) { parents.push_back(node); }

} tree[MAXN];

bitset<MAXN> visited;

void reset() {
  for (int i = 1; i <= N; i++) {
    tree[i] = Node(0);
  }
  visited.reset();
}

void DFS(Node node) {
  for (int i = 0; i < node.children.size(); i++) {
    Node actual = node.children[i];
  }
}

int main() {

  while (scanf("%d %d", &N, &M) != EOF) {

    reset();

    for (int i = 0; i < M; i++) {
      int a, b;
      scanf("%d %d", &a, &b);

      Node nodeA = tree[a];
      Node nodeB = tree[b];

      nodeA.addChild(nodeA);
      nodeB.addParent(nodeB);
    }

    for (int i = 1; i <= N; i++) {
    }
  }

  return 0;
}