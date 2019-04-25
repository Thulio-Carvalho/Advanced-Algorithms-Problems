/**
 * 620 E - New Year Tree
 * https://codeforces.com/problemset/problem/620/E
 **/

#include <bits/stdc++.h>
#define MAXN 400010
#define ROOT 1

using namespace std;

int N, M, arr[MAXN];
vector <int> adjList[MAXN];
bitset <MAXN> visited;
vector <int> tour;

struct Node {
    int color;
    int value;

    Node merge_values(Node a, Node b) {
        int maxValue = max(a.value, b.value);
        if (color) {
            
        } // Stopped here
    }
};

Node segTree[4 * MAXN];

enum Type {
    QUERY,
    UPDATE
};

Type read_query(){
    int num;
    scanf("%d", &num);
    if (num == 1) return Type::UPDATE;
    else if (num == 2) return Type::QUERY;
    throw "Query number not 1 or 2";
    return Type();
}

void euler_tour(int node){
    tour.push_back(node);
    visited.set(node);
    for (int child : adjList[node]) {
        if (!visited[child]) {
            euler_tour(child);
        }
    } tour.push_back(node);
}

void build(int id, int l, int r){
    if (l == r) {
        segTree[id].color = tour[l];
        segTree[id].value = 1;
    } else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        segTree[id].color = tour[l];
        segTree[id].merge_values(segTree[id * 2], segTree[id * 2 + 1]);
    }
}

int main(){
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    euler_tour(ROOT);

    while (M--) {
        Type query = read_query();
        int v, c;
        switch (query){
            case Type::QUERY:
            scanf("%d", &v);
            // TODO query v vertex
            break;

            case Type::UPDATE:
            scanf("%d %d", &v, &c);
            // TODO update v vertex
            break;

            default:
            throw "No query reading";
            break;
        }
    }
    return 0;
}