#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int t; cin >> t; 

    while (t--) {
        int y, x; cin >> y >> x; 

        ll m = max(y, x); 
        ll val = (m * m) - (m - 1); 

        ll ans = val; 
        if (m % 2 == 0) {
            if (y < m) {
                ans -= m - y; 
            } else if (x < m) {
                ans += m - x; 
            }
        } else {
            if (y < m) {
                ans += m - y; 
            } else if (x < m) {
                ans -= m - x; 
            }
        }

        cout << ans << "\n"; 
        // row y coluna x
    }
}