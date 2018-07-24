#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

typedef vector<int> vi;


bitset<MAXN> matrix[MAXN];

int friendsCounter[MAXN];

bitset<MAXN> vis;

int N, M, K;

void unfriendNexts(int node){
    queue <int> Q;
    Q.push(node);

    while (!Q.empty()){
        int actual = Q.front();
        Q.pop();

        for (int i = 1; i <= N; i++){

            if (matrix[actual][i]){

                matrix[actual][i] = 0;
                matrix[i][actual] = 0;

                friendsCounter[i]--;

                if (friendsCounter[i] == K-1){
                    Q.push(i);
                }
            }
        }
    }
}
void resetMatrix(){
    for (int i = 1; i <= N; i++){

        friendsCounter[i] = 0;
        
        for (int j = 1; j <= N; j++){
            matrix[i][j] = 0;
        }
    }
}
int main(){

    while (scanf("%d %d %d", &N, &M, &K) != EOF){

        resetMatrix();
        

        // reading
        for (int i = 0; i < M; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            matrix[a][b] = 1;
            friendsCounter[a]++;
            friendsCounter[b]++;
            matrix[b][a] = 1;
        }

        // debug
        // for (int i = 1; i <= N; i++){
        //     for (int j = 1; j <= N; j++){
        //         cout << matrix[i][j] << " ";
        //     } cout << endl;
        // }

        for (int i = 1; i <= N; i++){
            if (friendsCounter[i] < K){
                unfriendNexts(i);
            }
        }


        vector <int> party;

        for (int i = 1; i <= N; i++){
            if (friendsCounter[i] >= K){
                party.push_back(i);
            }
        }
        
        if (party.size() >  0){
            for (int i = 0; i < party.size(); i++){
                if (i < party.size() - 1){
                    printf("%d ", party[i]);
                } else {
                    printf("%d\n", party[i]);
                }
            }
        } else {
            printf("0\n");
        }
    }
    return 0;
}