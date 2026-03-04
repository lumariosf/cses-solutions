#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int n; cin >> n; 
    vector<int> a(n - 1); 
    for(int i = 0; i < n - 1; i++) cin >> a[i]; 
    sort(a.begin(), a.end()); 

    int ans = -1; 
    for(int i = 0; i < n - 1; i++) {
        if (a[i] != i + 1) {
            ans = i + 1; 
            break; 
        }
    }

    if (ans == -1) ans = n; 
    cout << ans; 
}