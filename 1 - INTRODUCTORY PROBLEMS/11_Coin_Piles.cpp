#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    int t; cin >> t; 

    while(t--) {
        int a, b; cin >> a >> b; 
        
        if (a == 0 || b == 0) {
            cout << "NO" << "\n"; 
        } else if (a % 3 == 0 && b % 3 == 0) {
            cout << "YES" << "\n"; 
        } else if ((a+b) % 3 == 0) {
            cout << "YES" << "\n"; 
        } else {
            cout << "NO" << "\n"; 
        }
    }
}