/**
 * 620 E - New Year Tree
 * https://codeforces.com/problemset/problem/620/E
 **/

#include <bits/stdc++.h>
#define MAXN 400010
#define MAXC 64
#define ROOT 1

using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

struct Node {
    ll color;
    ll colors; 

    Node() {
        colors = (1LL << 1); 
    }

    void change_color(int color) {
        colors = colors | (1LL << color);
    }

    void merge(Node a, Node b) {
        colors = a.colors | b.colors | colors;
    }
    
    int diff_count() {
        return __builtin_popcount(colors);
    }
};

enum Type {
    QUERY,
    UPDATE
};

int N, M, arr[MAXN];
vector <int> adjList[MAXN];
bitset <MAXN> visited;
vector <int> tour;
ii tourPos[MAXN];
Node segTree[4 * MAXN];
int lazy[4 * MAXN];


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
    tourPos[node].first = tour.size() - 1; 
    visited.set(node);

    for (int child : adjList[node]) {
        if (!visited[child]) {
            euler_tour(child);
        }
    } 

    tour.push_back(node);
    tourPos[node].second = tour.size() - 1; 
}

void build(int id, int l, int r){
    if (l == r) {
        segTree[id].change_color(tour[l]);
    } else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        segTree[id].change_color(tour[l]);
        segTree[id].merge(segTree[id * 2], segTree[id * 2 + 1]);
    }
}

void propagate(int id, int l, int r){
    if (lazy[id] != 0) {
        if (l != r) {
            lazy[id * 2] = lazy[id];
            lazy[id * 2 + 1] = lazy[id];
        }

        segTree[id].change_color(lazy[id]);
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int x, int y, int value){
    if (x > r || y < l) return;

    if (x <= l && r <= y) {
        lazy[id] = value;
        propagate(id, l, r);
        return; 
    }

    propagate(id, l, r);

    int mid = (l + r) / 2;
    update(id * 2, l, mid, x, y, value);
    update(id * 2 + 1, mid + 1, r, x, y, value);
}

int query(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        propagate(id, l, r);
        return segTree[id].colors;                  // code repeat, care
    }
    if (x > r || y < l) {
        return 0LL;
    }
    propagate(id, l, r);
    int mid = (l + r) / 2;
    return query(id * 2, l, mid, x, y) | query(id * 2 + 1, mid + 1, r, x, y);
}

int query(int vertex) {
    ii pos = tourPos[vertex];
    return __builtin_popcount(query(0, 0, N - 1, pos.first, pos.second));
}

void update(int vertex, int color){
    ii pos = tourPos[vertex]; 
    update(0, 0, N-  1, pos.first, pos.second, color);
}

void build() {
    build(0, 0, N - 1);
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
    build();

    while (M--) {
        Type queryType = read_query();
        int v, c, ans;
        switch (queryType){
            case Type::QUERY:
            scanf("%d", &v);
            ans = query(v);
            printf("%d\n", ans);
            break;

            case Type::UPDATE:
            scanf("%d %d", &v, &c);
            update(v, c);
            break;

            default:
            throw "No query reading";
            break;
        }
    }
    return 0;
}