#include <bits/stdc++.h>
using namespace std; 
#define ll long long

ll check(vector<int>& a, ll m) {
    ll products = 0; 
    for (int i = 0; i < a.size(); i++) {
        products += m / a[i]; 
    }

    return products; 
}

int main() {
    ll n, t; cin >> n >> t; 

    vector<int> a(n); 
    for (int i = 0; i < n; i++) { cin >> a[i]; }

    sort(a.begin(), a.end()); 

    ll l = 1, h = t * a[0]; 
    ll ans = 0; 
    while (l <= h) {
        ll m = l + (h - l) / 2; 

        ll products = check(a, m); 
        if (products >= t) {
            ans = m; 
            h = m - 1; 
        } else {
            l = m + 1; 
        }
    }

    cout << ans; 
}