#include <bits/stdc++.h>

using namespace std;

struct node{
    struct node* word[20];
    int end;
    virtual ~node(){
        for (int i=0; i<20; i++) {
            if (word[i] != NULL) {
                delete word[i];
            }
        }
    }
} *root;

int ans;
void init(){
    delete root;
    root = new node();
    root->end = false;
}

void add(string s){
    node* current = root;

    for(int i = 0; i < s.size(); i++){
        int letra = s[i]-'0';

        if(current->word[letra] == NULL){
            current->word[letra] = new node();
        }else ans++;

        current = current->word[letra];
    }
    current->end = true;
}
int main(){
    int cases;
    while(cin >> cases){
        init();
        string s;
        ans = 0;
        for(int i = 0; i < cases; i++){
            cin >> s;
            add(s);
        }
        cout << ans << endl;
    }
    return 0;
}