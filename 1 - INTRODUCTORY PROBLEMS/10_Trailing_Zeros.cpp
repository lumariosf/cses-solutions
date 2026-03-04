#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int n; cin >> n; 

    ll ans = 0; 
    while (n != 0) {
        ans += n / 5; 

        n /= 5; 
    }

    cout << ans; 
}