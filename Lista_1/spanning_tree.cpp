#include <bits/stdc++.h>
#define MAXV 200014

using namespace std;

typedef pair <int, int> ii;

int parent[MAXV], V, E;
vector <int> adjList[MAXV];
vector <ii> ans;
vector <ii> edges;

int degree[MAXV];

int find(int node){
    while(parent[node] != node) {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;
}

int unionSets(int A, int B){
    int rootA = find(A);
    int rootB = find(B);
    parent[rootA] = rootB;
}

int find(int A, int B) {
    return find(A) == find(B);
}

int main(){
    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        adjList[A].push_back(B);
        adjList[B].push_back(A);
        edges.push_back({A, B});
    }

    int startVertex = -1;
    int maximumDegree = -1;

    for (int i = 1; i <= V; i++) {
        int sz = adjList[i].size();

        if (sz > maximumDegree){
            maximumDegree = sz;
            startVertex = i;
        }
    }

    for (int i = 0; i <= V; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < adjList[startVertex].size(); i++) {
        unionSets(startVertex, adjList[startVertex][i]);
        ans.push_back({startVertex, adjList[startVertex][i]});
    }

    for (int i = 0; i < edges.size(); i++) {
        ii e = edges[i];
        if (!find(e.first, e.second)) {
            unionSets(e.first, e.second);
            ans.push_back(e);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}