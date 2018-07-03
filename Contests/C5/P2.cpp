#include <bits/stdc++.h>

#define NEG_INF -999999
#define MAX_N 1000010

using namespace std;

int N, x;

struct Node{
    int id;
    vector<Node> vizinhos;
};

bool isRoot(Node node){
    return node.id == 1;
}

// pair <distToRoot, NodeToRoot>
pair<int, Node> findRoot(Node B, bitset<MAX_N> visited){

    vector <pair<int, Node> > distDir;

    for (Node node : B.vizinhos){
        if (!visited[node.id]){
            if (isRoot(node)){
                return {1, node};
            } else {
                distDir.push_back({findRoot(node, visited).first + 1, node});
            }
        }
    }

    int max = NEG_INF;
    pair<int, Node> ret;

    for (pair<int, Node> i : distDir){
        int dist = i.first;
        if (dist > max && dist > 0){
            max = dist;
            ret = i;
        }
    }

    return ret;
}

int runAway(Node B, Node backwards, bitset<MAX_N> visited){

    vector<int> dists;

    for (Node node : B.vizinhos){
        if (!visited[node.id]){
            // can't go in root direction
            if (node.id != backwards.id){
                dists.push_back(runAway(node, B, visited));
            }
        }
    }

    int max = 0;

    for (int i : dists){
        if (i > max && i > 0){
            max = i;
        }
    }

    return max + 1;
}




int main(){
    
    scanf("%d %d", &N, &x);

    Node root;
        if (root == NULL){
            
        }
    for (int i = 0; i < N-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        Node *node1 = new Node();
        Node *node2 = new Node();
        node1->vizinhos.push_back(*node2);
        node2->vizinhos.push_back(*node1);
    }



    return 0;
}