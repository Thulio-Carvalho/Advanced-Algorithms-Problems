#include <bits/stdc++.h>
#define MAX 8

using namespace std;

char grid[MAX][MAX];

int baguncinha2(int xking, int yking){
    //vertical
    for(int i = yking+1; i <= 7; i++){
        char val = grid[xking][i];
        if(val == '$') continue;
        if(val == 'T' || val == 'R' || val == 'W'){
            if(val == 'W'){
                if(i-yking == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }

    for(int i = yking-1; i >= 0; i--){
        char val = grid[xking][i];
        if(val == '$') continue;
        if(val == 'T' || val == 'R' || val == 'W'){
            if(val == 'W'){
                if(abs(yking-i) == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }

    //horizontal
    for(int i = xking+1; i <= 7; i++){
        char val = grid[i][yking];
        if(val == '$') continue;
        if(val == 'T' || val == 'R' || val == 'W'){
            if(val == 'W'){
                if(i-yking == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }


    for(int i = xking-1; i >= 0; i--){
        char val = grid[i][yking];
        if(val == '$') continue;
        if(val == 'T' || val == 'R' || val == 'W'){
            if(val == 'W'){
                if(abs(yking-i) == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }

    //diagonal cima
    for(int i = 1; xking-i >= 0 && yking+i <= 7; i++){
        char val = grid[xking-i][yking+i];
        if(val == '$') continue;
        if(val == 'B' || val == 'R' || val == 'W' || val == 'P'){
            if(val == 'W' || val == 'P'){
                if(i == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }


    for(int i = 1; xking-i >= 0 && yking-i >= 0; i++){
        char val = grid[xking-i][yking-i];
        if(val == '$') continue;
        if(val == 'B' || val == 'R' || val == 'W' || val == 'P'){
            if(val == 'W' || val == 'P'){
                if(i == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }

    //diagonal baixo
    for(int i = 1; yking+i <= 7 && xking+i <= 7; i++){
        char val = grid[xking+i][yking+i];
        if(val == '$') continue;
        if(val == 'B' || val == 'R' || val == 'W'){
            if(val == 'W'){
                if(i-yking == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }

    for(int i = 1; xking+i <= 7 && yking-i >= 0; i++){
        char val = grid[xking+i][yking-i];
        if(val == '$') continue;
        if(val == 'B' || val == 'R' || val == 'W'){
            if(val == 'W'){
                if(i-yking == 1){
                    return 1;
                    return 0;
                }
            }else{
                return 1;
                return 0;
            }
        }else break;
    }
    return 0;
}
void baguncinha(int black){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++) grid[i][j] = '$';
    }

    for(int i = 0; i < black; i++){
        string b; cin >> b;
        int y = b[1]-'a';
        int x = b[2]-'1';
        grid[x][y] = b[0];
    }

    string king; cin >> king;
    int yking = king[1]-'a';
    int xking = king[2]-'1';

    grid[xking][yking] = '@';
    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < 8; j++) cout << grid[i][j] << " \n"[7 == j];
    // }
    grid[xking][yking] = '$';

    bool isInMate = true;
    int newI[9] = {0, 0,  0, 1, -1, 1, -1,  1, -1};
    int newY[9] = {0, 1, -1, 0,  0, 1,  1, -1, -1}; 

    for (int k = 0; k < 9; k++){
        if (xking+newI[k] >= 0 && xking+newI[k] <= 7 && yking+newY[k] >= 0 && yking+newY[k] <= 7){
            if (baguncinha2(xking + newI[k], yking + newY[k]) == 0){
                isInMate = false;
                break;
            }

        }
    }

    if (isInMate){
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }
}
int main(){
    int black; 
    while(cin >> black){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++) grid[i][j] = '$';
        }
        
        baguncinha(black);
    }
    return 0;
}