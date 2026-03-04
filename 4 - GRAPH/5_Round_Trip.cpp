#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

vector<vector<int>> adj; 
vector<bool> vis;
vector<int> pai; 
int inicio = -1, final = -1; 

bool dfs(int atual, int anterior) {
    vis[atual] = true; 

    for (int nxt : adj[atual]) {
        if (!vis[nxt]) {
            pai[nxt] = atual; 
            if (dfs(nxt, atual)) {
                return true; 
            }
        } else if (nxt != anterior) {
            inicio = nxt; 
            final = atual; 
            return true; 
        }
    }

    return false; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m; 
    adj.resize(n); vis.assign(n, false); 
    pai.resize(n); 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        a--; b--; 

        adj[a].push_back(b); 
        adj[b].push_back(a); 
    }

    bool ans = false; 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans = dfs(i, -1); 

            if (ans) {
                break; 
            }
        }
    }

    if (ans) {
        vector<int> caminho; 
        for (int v = final; v != inicio; v = pai[v]) {
            caminho.push_back(v); 
        }

        caminho.push_back(inicio); 
        reverse(caminho.begin(), caminho.end()); 

        cout << caminho.size() + 1 << pu; 
        for (int i = 0; i < caminho.size(); i++) {
            cout << caminho[i] + 1 << es;
        }
        cout << caminho[0] + 1; 
    } else {
        cout << "IMPOSSIBLE"; 
    }
}