#include <bits/stdc++.h>
#define MAXN 110
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

ii adjList[MAXN];
bitset<MAXN> vis;
int vectorCnt;
vector<int > vectors[MAXN];

int N;

void reverseBFS(int start){
  vis[start] = 1;
  if (adjList[start].first == 0){
    vectors[vectorCnt].push_back(start);
    return;
  }
  reverseBFS(adjList[start].first);
  vectors[vectorCnt].push_back(start);
}
void BFS(int start){
  vis[start] = 1;
  vectors[vectorCnt].push_back(start);
  if (adjList[start].second == 0){
    return;
  }
  BFS(adjList[start].second);
}

void buildVector(int start){
  reverseBFS(start);
  vectors[vectorCnt].pop_back();
  BFS(start);
  vectorCnt++;
}
int main(){
  scanf("%d", &N);
  for(int i = 1; i <= N; i++){
    int l, r;
    scanf("%d %d", &l, &r);
    adjList[i] = make_pair(l, r);
  }
  for(int i = 1; i <= N; i++){
    if (!vis[i]){
      buildVector(i);
    }
  }
  if (vectorCnt > 1){
    for(int i = 1; i < vectorCnt; i++){
      int a, b;
      a = vectors[i-1].back();
      b = vectors[i].front();
      adjList[a] = make_pair(adjList[a].first, b);
      adjList[b] = make_pair(a, adjList[b].second);
    }
  }
  for(int i = 1; i <= N; i++){
    printf("%d %d\n", adjList[i].first, adjList[i].second);
  }
  return 0;
}
