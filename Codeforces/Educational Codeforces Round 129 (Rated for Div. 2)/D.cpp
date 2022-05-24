#include <bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector<__int128_t> get(__int128_t x) {
    vector<__int128_t> v;
    while (x) {
        v.push_back(x%10);
        x /= 10;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    return v;
}

vector<__int128_t> hist;
map<__int128_t, ll> chk;
ll n;
ll ans;
bool f;

void dfs(__int128_t x, ll cnt) {
    chk[x] = cnt;
    vector<__int128_t> v = get(x);
    if (v.size() == n) {
        ans = min(ans, cnt);
        f = true;
        return;
    }
    else if (v.size() > n) return;
    for (__int128_t y : v) {
        if (y == 0 || y == 1) continue;
        __int128_t z = x*y;
        if (chk.find(z) != chk.end() && chk[z] <= cnt+1) continue;
        dfs(z, cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    hist.clear();
    chk.clear();
    f = false;
    ans = 1000000000000000000;
    ll x; cin >> n >> x;
    dfs(x, 0);
    if (f) cout << ans;
    else cout << -1;
}