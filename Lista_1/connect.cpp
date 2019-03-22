#include <bits/stdc++.h>
#define MAXN 55

using namespace std;

typedef pair<int,int> ii;

int N, grid[MAXN][MAXN];
int colors[MAXN][MAXN];

ii start, finish;

enum Dir {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

bool validPos(ii pos) {
    int i = pos.first, j = pos.second;
    return i < N && i >= 0 && j < N && j >= 0;
}

ii move(ii pos, Dir dir){
    switch (dir)
    {
        case UP:
            return {pos.first - 1, pos.second};
        case DOWN:
            return {pos.first + 1, pos.second};
        case LEFT:
            return {pos.first, pos.second - 1};
        case RIGHT:
            return {pos.first, pos.second + 1};
        default:
            break;
    }
}

void dfs(ii start, int color){
    Dir dirs[4] = {UP, DOWN, LEFT, RIGHT};
    colors[start.first][start.second] = color;
    for (Dir dir : dirs) {
        ii nextPos = move(start, dir);
        if (validPos(nextPos) 
            && grid[nextPos.first][nextPos.second] == 0
            && colors[nextPos.first][nextPos.second] != color) {
            dfs(nextPos, color);
        }
    }
}

int cost(ii a, ii b){
    int difX = (a.first - b.first), difY = (a.second - b.second);
    return (difX * difX) + (difY * difY);
}

int measureDistance(){
    dfs(start, 1);
    if (colors[finish.first][finish.second] == 1) {
        return 0;
    }
    dfs(finish, 2);

    vector <ii> startIsle;
    vector <ii> finishIsle;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (colors[i][j] == 1) {
                startIsle.push_back({i, j});
            } else if (colors[i][j] == 2) {
                finishIsle.push_back({i, j});
            }
        }
    }

    int minimum = INT32_MAX;

    for (ii start_pos : startIsle) {
        for (ii end_pos : finishIsle) {
            ii pos1 = {start_pos.first + 1, start_pos.second + 1};
            ii pos2 = {end_pos.first + 1, end_pos.second + 1};
            int value = cost(pos1, pos2);
            if (value < minimum) {
                minimum = value;
            }
        }
    }

    return minimum;
    
}

int main(){
    scanf("%d", &N);
    scanf("%d %d", &start.first, &start.second);
    scanf("%d %d", &finish.first, &finish.second);

    start.first--; start.second--; finish.first--; finish.second--;

    for (int i = 0; i < N; i++){
        string tmp;
        cin >> tmp; 
        for (int j = 0; j < N; j++){
            grid[i][j] = tmp[j] - '0';
        }
    }

    printf("%d\n", measureDistance());

    return 0;
}