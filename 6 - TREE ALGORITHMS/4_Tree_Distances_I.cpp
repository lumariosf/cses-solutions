#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

int dfs(int atual,
    vector<vector<int>>& adj,
    vector<bool>& vis,
    vector<int>& dist, 
    int& maiordistancia, int& node, int distancia) 

    {
    vis[atual] = true; 
    dist[atual] = distancia; 

    if (maiordistancia < distancia) {
        maiordistancia = distancia; 
        node = atual; 
    }

    for (auto nxt : adj[atual]) {
        if (!vis[nxt]) {
            dfs(nxt, adj, vis, dist, maiordistancia, node, distancia + 1); 
        }
    }

    return node; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n; cin >> n; 
    vector<vector<int>> adj(n); 
    vector<bool> vis1(n, false); 
    vector<int> dist1(n, 0); 
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; 
        a--; b--; 
        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    int farthestnode = -1;
    int biggestdistance = -1; 
    // achar extremo 1
    int x1 = dfs(0, adj, vis1, dist1, biggestdistance, farthestnode, 0); 

    vector<bool> vis2(n, false); 
    vector<int> dist2(n, 0); 
    biggestdistance = -1; 
    farthestnode = -1;
    // achar extremo 2
    int x2 = dfs(x1, adj, vis2, dist2, biggestdistance, farthestnode, 0); 

    vector<bool> vis3(n, false); 
    vector<int> dist3(n, 0); 
    biggestdistance = -1; 
    farthestnode = -1;
    // achar extremo 3
    int x3 = dfs(x2, adj, vis3, dist3, biggestdistance, farthestnode, 0); 

    for (int i = 0; i < n; i++) {
        cout << max(dist2[i], dist3[i]) << es; 
    }

}