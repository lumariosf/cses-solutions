#include <bits/stdc++.h>
using namespace std; 
#define ll long long

bool check(vector<int>& a, ll m, int k) {
    ll soma = 0; 
    ll nk = 1;  
    for (int i = 0; i < a.size(); i++) {
        if (soma + a[i] <= m) {
            soma += a[i]; 
        } else {
            nk++;  
            soma = a[i]; 
        }
    }

    return nk <= k; 
}

int main() {
    int n, k; cin >> n >> k; 

    vector<int> a(n); 
    ll l = 0, h = 0; 
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        h += a[i]; 
        l = max(l, (ll)a[i]); 
    }

    ll ans = h; 
    while (l <= h) {
        ll m = (l + h)/2; 

        if (check(a, m, k)) {
            ans = min(ans, m); 
            h = m - 1; 
        } else {
            l = m + 1;  
        } 
    }

    cout << ans; 
}