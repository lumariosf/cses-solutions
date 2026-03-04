#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

vector<vector<int>> adj; 
vector<bool> vis, color; 

bool dfs(int v) {
    vis[v] = true; 

    for (int u : adj[v]) {
        if (!vis[u]) {
            color[u] = !color[v]; 
            if (!dfs(u)) return false; 
        }

        else if (color[v] == color[u]) return false; 
    }

    return true; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m; 
    adj.resize(n); vis.assign(n, false); color.resize(n); 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        a--; b--; 

        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    bool ans = true; 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans = dfs(i); 

            if (ans == false) {
                break; 
            }
        }
    }

    if (ans) {
        for (int i = 0; i < n; i++) {
            if (color[i] == true) {
                cout << "1" << es; 
            } else {
                cout << "2" << es; 
            }
        }
    } else {
        cout << "IMPOSSIBLE"; 
    }
}