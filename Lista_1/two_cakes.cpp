#include <bits/stdc++.h>
#define MAXN 200010

using namespace std;

int n, a[MAXN], moves;
bool valid_pos[MAXN];

bool valid_index(int index) {
    return index >= 0 && index < 2*n;
}

struct Player {
    int last;
    int pos;

    Player(){
        last = 0;
        pos = 0;
    }
};

int search(int i, int j, Player &p){
    if (!valid_index(i) && !valid_index(j)) return -1;

    if (valid_index(i)) {
        if (a[i] == p.last + 1 && valid_pos[i]) {
            return i;
        }
        i++;
    }
    if (valid_index(j)) {
        if (a[j] == p.last + 1 && valid_pos[j]) {
            return j;
        }
        j--;
    }
    return search(i, j, p);
}

void move(Player &p){
    int next_move = search(p.pos, p.pos, p);
    valid_pos[next_move] = false;

    moves += abs(next_move - p.pos);
    p.pos = next_move;
    p.last = p.last + 1;
}

int main(){
    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    memset(valid_pos, true, 2*n);

    Player sasha, dima;
    bool end = false;
    
    while (!end) {
        if (sasha.last != n) {
            move(sasha);
        } else if (dima.last != n){
            move(dima); 
        } else {
            end = true;
        }
    }

    cout << moves << endl;

    return 0;
}