#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

const int dx[] = {1, 0, 0, -1}; 
const int dy[] = {0, 1, -1, 0}; 

vector<vector<char>> grid; 
vector<vector<bool>> vis; 

int n, m; 

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.'; 
}

void dfs(int i, int j) {
    grid[i][j] = '#'; 

    for (int d = 0; d < 4; d++) {
        int x = i + dx[d]; 
        int y = j + dy[d]; 

        if (valid(x, y)) {
            dfs(x, y); 
        }
    }

    return; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m; 

    grid.resize(n, vector<char>(m)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j]; 
        }
    }

    ll ans = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                ans++; 
                dfs(i, j); 
            }
        }
    }

    cout << ans; 
    
}