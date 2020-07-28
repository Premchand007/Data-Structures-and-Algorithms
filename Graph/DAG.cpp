//Directed Acyclic Graph or Not
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
vector<int> col(10000, 0);
bool cycle;

void dfs(int u) {
    col[u] = 1;
    for(int v : adj[u]) {
        if(col[v] == 1) {
            cycle = 1;
            return;
        }
        else if(col[v] == 0) dfs(v);
    }
    col[u] = 2;
}

int main() {

    int n, m; // n vertices, m edges
    cin >> n >> m;

    while(m--) {
        int a, b;
        cin >> a >> b;
        // --a, --b; If index is 1 to n
        adj[a].push_back(b);
    }

    for(int i = 0; i < n; ++i) {
        if(!col[i]) {
            dfs(i);
            if(cycle) break;
        }
    }
    if(cycle) cout << "Not a DAG" << endl;
    else cout << "DAG" << endl;
}