#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

char p[] = {'R', 'L', 'D', 'U'}; 
int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0}; 
vector<vector<char>> grid; 
vector<vector<bool>> vis; 
vector<vector<pair<int, int>>> parent; 
vector<vector<char>> path; 

int n, m; 

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#'; 
}

bool bfs(int i, int j) {
    queue<pair<int, int>> q; 
    q.push({i, j}); 
    vis[i][j] = true; 

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop(); 

        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i]; 
            int ay = y + dy[i]; 
            if (valid(ax, ay) && !vis[ax][ay]) {
                vis[ax][ay] = true; 
                q.push({ax, ay}); 
                parent[ax][ay] = {x, y}; 
                path[ax][ay] = p[i]; 

                if (grid[ax][ay] == 'B') {
                    return true; 
                }

            } 
        }
        
    }

    return false; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m; 
    grid.resize(n, vector<char>(m)); vis.assign(n, vector<bool> (m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1})); 
    path.assign(n, vector<char>(m)); 

    int bx, by; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j]; 

            if (grid[i][j] == 'B') {
                bx = i; by = j; 
            }
        }
    }

    bool ans = false; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                ans = bfs(i, j); 
                break; 
            }
        }
    }

    if (ans) {
        cout << "YES" << pu; 

        vector<char> resp; 
        int x = bx, y = by; 
        // reconstruir caminho
        while(grid[x][y] != 'A') {
            resp.push_back(path[x][y]); 

            auto [px, py] = parent[x][y]; 
            x = px; y = py; 
        }

        reverse(resp.begin(), resp.end()); 
        cout << resp.size() << pu; 
        for (int i = 0; i < resp.size(); i++) {
            cout << resp[i]; 
        }

    } else cout << "NO"; 
    
}