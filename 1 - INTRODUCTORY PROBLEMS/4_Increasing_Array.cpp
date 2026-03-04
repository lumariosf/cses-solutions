#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int n; cin >> n; 
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i]; 
    int prev = a[0]; 

    ll ans = 0; 
    for (int i = 1; i < n; i++) {
        if (a[i] < prev) {
            ans += prev - a[i]; 
        }
        prev = max(prev, a[i]); 
    }

    cout << ans; 
}