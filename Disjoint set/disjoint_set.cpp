#include <bits/stdc++.h>
using namespace std;

#define SZ 15
int parent[SZ];

void make_set(int u){
    parent[u] = u;
}

void init_disjoint_set(int n){
    for(int i = 1; i <= n; i++){
        make_set(i);
    }
}

int findRepresentative(int r){
    if(parent[r] == r) return r;
    parent[r] = findRepresentative(parent[r]);
    return parent[r];
}

void make_union(int a, int b){

    int u = findRepresentative(a);
    int v = findRepresentative(b);

    if(u != v){
        parent[u] = v;
    }
}

int main(){

    int n;
    cout << "Enter number of nodes: ";
    init_disjoint_set(n);
    make_union(1, 2);
    make_union(5, 2);
    make_union(1, 4);
    make_union(1, 3);

    for(int i = 1; i <= n; i++){
        printf("parent of %d's is : %d\n", i, parent[i]);
    }

    return 0;
}


