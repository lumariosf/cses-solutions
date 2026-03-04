#include <bits/stdc++.h>
using namespace std; 
#define ll long long

const ll MOD = 1e9 + 7; 

ll fexp(ll a, ll b){
    ll ans = 1;

    while(b){
        if(b & 1) ans = (ans * a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }

    return ans;
}

int main() {
    int n; cin >> n; 
    cout << fexp(2, n); 
}