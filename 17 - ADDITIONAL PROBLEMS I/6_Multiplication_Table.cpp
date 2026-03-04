#include <bits/stdc++.h>
using namespace std; 
#define ll long long

ll n; 
ll check(ll m) {
    ll qnt = 0; 
    for (int i = 1; i <= n; i++) {
       qnt += min(m/i, n); 
    }

    return qnt; 
}

void bs() {
    ll h = n*n, l = 1; 
    ll ans = 0; 

    ll target = (h + 1) / 2; 

    while (l <= h) {
        ll m = (l + h) / 2; 

        ll qnt = check(m); 
        if (qnt >= target) {
            ans = m; 
            h = m - 1; 
        } else {
            l = m + 1; 
        }
    }

    cout << ans; 
}

int main() {
    cin >> n; 
    bs(); 
}