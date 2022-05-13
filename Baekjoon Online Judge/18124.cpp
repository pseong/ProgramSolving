#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    ll m = 1LL<<40;
    for (; m >= 1; m >>= 1) {
        if (m < n) break; 
    }
    cout << m + m/2 + (n-m-1)/2;
}