#include <bits/stdc++.h>
using namespace std; 
#define ll long long

int main() {
    string s; cin >> s; 

    map<char, int> freq; 
    for (auto c : s) {
        freq[c]++; 
    }

    int impar = 0; 
    for (auto [ch, cnt] : freq) {
        if (cnt % 2 == 1) {
            impar++; 
        }
    }

    if (impar > 1 && s.size() % 2 == 1) {
        cout << "NO SOLUTION"; 
        return 0; 
    } else if (impar > 0 && s.size() % 2 == 0) {
        cout << "NO SOLUTION"; 
        return 0; 
    }

    string l = "";
    string m = ""; 
    for (auto [ch, cnt] : freq) {
        l += string(cnt/2, ch); 
        if (cnt % 2 == 1) {
            m = ch; 
        } 
    }

    cout << l + m + string(l.rbegin(), l.rend()); 
}