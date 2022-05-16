#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> an(n+1);
    for (int i=1; i<=n; i++) {
        cin >> an[i];
        an[i] += an[i-1];
    }
    int ans = -10000000;
    for (int i=k; i<=n; i++) {
        ans = max(ans, an[i]-an[i-k]);
    }
    cout << ans;
}