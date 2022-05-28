#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}
ll cal(ll x, ll n) {
    ll cnt = n / x;
    ll ret = cnt*(cnt+1)/2*x;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;
    ll sum = n*(n+1)/2;
    ll asum = cal(a, n);
    ll bsum = cal(b, n);
    ll absum = cal(lcm(a, b), n);
    ll ans = sum - asum - bsum + absum;
    cout << ans;
}