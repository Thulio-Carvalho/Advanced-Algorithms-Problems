#include <bits/stdc++.h>

#define MAXN 55
#define x first 
#define y second

using namespace std;

typedef pair <int, int> ii;

int n, m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
string answer;

bool valid_pos(ii pos) {
    if ((pos.x >= 0 && pos.x < MAXN) && (pos.y >= 0 && pos.y < MAXN)) {
        return (grid[pos.x][pos.y] != '$');
    }
    return false;
}

char get_color(ii pos) {
    return grid[pos.x][pos.y];
}

vector<ii> adjacents(ii node) {
    vector<ii> adj;
    char rootColor = get_color(node);
    ii possibleDirections[4] = {{node.x + 1, node.y},
                               {node.x - 1, node.y},
                               {node.x, node.y + 1},
                               {node.x, node.y - 1}};
    for (ii dir : possibleDirections) {
        if (valid_pos(dir) && (get_color(dir) == rootColor)) {
            adj.push_back(dir);
        }
    }
    return adj;
}

void dfs(ii node, int count){
    visited[node.x][node.y] = true;
    for (ii adj : adjacents(node)) {
        if (!visited[adj.x][adj.y]){
        
        }
    }
}

void reset_grid(){
    for (int i = 0; i < MAXN; i++) {
        memset(grid[i], '$', MAXN);
    }
}

int main(){

    reset_grid();

    cin >> n, m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    return 0;
}