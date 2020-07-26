/*
Topological sorting for Directed Acyclic Graph (DAG) is a 
linear ordering of vertices such that for every directed edge uv, 
vertex u comes before v in the ordering.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10000]; // Adjacency List
vector<bool> visited;
vector<int> ans;

void dfs(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) dfs(v);
    }
    ans.push_back(u); 
    // u is added to the list after all outgoing vertices from u are added to list.
}

void topological_sort(int n) {
    visited.assign(10000, false);
    ans.clear();

    for(int i = 0; i < n; ++i) {
        if(!visited[i]) dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main() {

    int n, m;
    cin >> n >> m; // n vertices, m edges

    while(m--) {
        int a, b;
        cin >> a >> b;
        // --a, --b; If index is 1 to n
        adj[a].push_back(b);
    }

    topological_sort(n);
    for(int i = 0; i < n; ++i) cout << ans[i] << " "; // ans[i] + 1 if index is 1 to n
    cout << endl;
    
}