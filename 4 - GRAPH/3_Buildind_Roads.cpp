#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

vector<vector<int>> adj; 
vector<bool> vis; 

void dfs(int atual) {
    vis[atual] = true; 

    for (auto nxt : adj[atual]) {
        if (!vis[nxt]) {
            dfs(nxt); 
        }
    }

    return; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m; 

    adj.resize(n); vis.assign(n, false); 

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        a--; b--; 

        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    ll ans = 0; 
    vector<int> path; 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i); 
            ans++; 
            path.push_back(i + 1); 
        }
    }

    cout << ans - 1 << pu; 

    for (int i = 1; i < path.size(); i++) {
        cout << path[i - 1] << " " << path[i] << pu; 
    }
    
}