#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

int dx[] = {-1, -1, -1,  0,  0,  1,  1,  1};
int dy[] = {-1,  0,  1, -1,  1, -1,  0,  1};

bool valid(int i, int j, int n, vector<vector<char>>& tabuleiro) {
    if (tabuleiro[i][j] == '*') return false; // reservado

    for (int d = 0; d < 8; d++) {
        int ni = i + dx[d]; 
        int nj = j + dy[d]; 

        while (ni >= 0 && ni < n && nj >= 0 && nj < n) {
            if (tabuleiro[ni][nj] == 'Q') return false; // rainha

            ni += dx[d];
            nj += dy[d];
        }
    }

    return true; 
}

ll backtracking(int i, int j, int n, int rainha, vector<vector<char>>& tabuleiro) {
    if (rainha == 8) {
        return 1; 
    }
    
    // fim do tabuleiro
    if (j == n) {
        i++; j = 0; 
    }

    if (i == n) {
        return 0; 
    }

    ll total = 0; 
    // coloco um nessa posição se for valido
    if (valid(i, j, n, tabuleiro)) {
        // coloco
        tabuleiro[i][j] = 'Q';  
        total += backtracking(i, j + 1, n, rainha + 1, tabuleiro); 

        // tirar
        tabuleiro[i][j] = '.'; 
    } 

    // tiro
    total += backtracking(i, j + 1, n, rainha, tabuleiro); 

    return total; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<char>> tabuleiro(8, vector<char>(8)); 

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> tabuleiro[i][j]; 
        }
    }

    cout << backtracking(0, 0, 8, 0, tabuleiro) << pu; 
}