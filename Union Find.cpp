#include "bits/stdc++.h"
using namespace std;


int find(int x, int par[]) {
    if(par[x] != x) par[x] = find(par[x], par);
    return par[x]; 
}

int main() {
    
    int n, m;
    cin >> n >> m; //n vertices, m edges

    int par[n], rank[n], size[n]; 
    for(int i = 0; i < n; ++i) {
        par[i] = i, rank[i] = 0, size[i] = 1;
    }

    while(m--) {
        int a, b;
        cin >> a >> b;


        a = find(a, par); // returns parent of set in which a is present
        b = find(b, par);
        if(a == b) continue;

        // If both a and b are in different sets the union of two sets is done.
        if(rank[a] < rank[b]) {
            par[a] = b;
            size[b] += size[a];
        }
        else {
            par[b] = a;
            size[a] += size[b];
            if(rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
}