#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> v(n+1);
    vector<ll> cnt(m);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        v[i] %= m;
        cnt[v[i]]++;
    }
    ll ans = cnt[0];
    for (int i=0; i<m; i++) {
        ans += cnt[i]*(cnt[i]-1)/2;
    }
    cout << ans;
}