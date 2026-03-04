#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int n; cin >> n; 
    vector<pair<int, int>> a; 
    for(int i = 0; i < n; i++) {
        int b, c; cin >> b >> c; 
        a.push_back({b, c}); 
    }

    // maximum reward

    sort(a.begin(), a.end()); 
    ll t = 0; 
    ll ans = 0; 
    for(int i = 0; i < n; i++) {
        t += a[i].first; 
        ans += a[i].second - t; 
    }

    cout << ans; 
}