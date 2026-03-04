#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define pu "\n"
#define es " "

vector<vector<int>> adj; 
vector<int> estados; 
stack<int> st; 

void toposort(int atual, bool& entrou) {
    estados[atual] = 1; 

    for (auto vizinho : adj[atual]) {
        if (estados[vizinho] == 0) {
            toposort(vizinho, entrou); 
        } else if (estados[vizinho] == 1) {
            entrou = true; 
            return; 
        }
    }

    estados[atual] = 2; 
    st.push(atual); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m; cin >> n >> m; 
    adj.resize(n); estados.assign(n, 0); 
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; 
        a--; b--; 

        adj[a].push_back(b);
    }

    bool entrou = false; 
    for (int i = 0; i < n; i++) {
        if (estados[i] == 0) {
            toposort(i, entrou); 

            if (entrou) {
                break; 
            }
        }
    }

    if (st.size() != n) {
        cout << "IMPOSSIBLE"; 
    } else {
        while (!st.empty()) {
            cout << st.top() + 1 << es; 
            st.pop(); 
        }
    }
}