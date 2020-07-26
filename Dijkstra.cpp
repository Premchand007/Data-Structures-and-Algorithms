//Dijkstra's Algo
#include"bits/stdc++.h"
#define int long long
#define bug cout << " not ok\n";
using namespace std;
const double pi = acos(-1);
const int inf = 1e18 + 5;
const int big = 1000005;

vector<pair<int, int> > adj[big];
vector<int> res;

int n, m;
int dist[big], pre[big] = {0};
set<pair<int, int> > s;

void bfs(int src) {
	
	s.insert(make_pair(0, src));
	dist[src] = 0;

	int u;

	while(!s.empty()) {
        
		pair<int, int> tmp = *(s.begin());
		s.erase(s.begin());
		
		u = tmp.second;
		if(u == n) break;

		for(auto i : adj[u]) {
			int v = i.first, wt = i.second;
			
			if(dist[v] > dist[u] + wt) {
				if(dist[v] != inf) s.erase(s.find({dist[v], v}));
				dist[v] = dist[u] + wt;
				s.insert({dist[v], v});
				pre[v] = u;
			}

		}

	}

	if(pre[u] || u == src) {
		while(u) {
			res.push_back(u);
			u = pre[u];
		}
	}

}


int32_t main() 
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m; // n vertices, m weighted undirected edges

	while(m--) {
		int a, b, wt;
		cin >> a >> b >> wt;

		adj[a].push_back({b, wt});
		adj[b].push_back({a, wt});
	}

	for(int i = 1; i <= n; ++i) dist[i] = inf;
	bfs(1);
	
	if(dist[n] == inf) return cout << -1 << endl, 0;

	for(int i = res.size() - 1; i >= 0; --i) cout << res[i] << " ";
	cout << endl;
}