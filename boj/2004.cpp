#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll Findfive(ll n) {
    ll cnt = 0;
    for(ll i = 5; i <= n; i *= 5) {
        cnt += n / i;
    }
    return cnt;
}

ll FindTwo(ll n) {
    ll cnt = 0;
    for(ll i = 2; i <= n; i *= 2) {
        cnt += n / i;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    
    ll two = FindTwo(n) - FindTwo(n - m) - FindTwo(m);
    ll five = Findfive(n) - Findfive(n - m) - Findfive(m);

    cout << min(two, five);
}