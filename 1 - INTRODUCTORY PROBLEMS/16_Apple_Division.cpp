#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int n; cin >> n; 
    vector<int> a(n);
    for(int &i : a) cin >> i; 

    // bitmask 
    ll ans = LLONG_MAX; 
    for (int mask = 0; mask < (1<< n); mask++) {
        ll sum1 = 0; ll sum2 = 0; 

        for (int i = 0; i < n; i++) {
            // ver se está ligado
            if (mask & (1 << i)) {
                sum1 += a[i]; 
            } else {
                sum2 += a[i]; 
            }
        }

        ans = min(ans, abs(sum1 - sum2)); 
    }

    cout << ans; 
}