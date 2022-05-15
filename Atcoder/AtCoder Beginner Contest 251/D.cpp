#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int w; cin >> w;
    cout << 300 << '\n';
    for (int i=1; i<=100; i++) {
        cout << i << ' ' << i * 100 << ' ' << i * 10000 << ' ';
    }
}