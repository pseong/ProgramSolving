#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
const ll inf = 1000000000000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> v(k);
    for (int i=0; i<k; i++) {
        cin >> v[i]; --v[i];
    }
    vector<ll> x(n), y(n);
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll dist = inf;
        for (int a : v) {
            dist = min(dist, (x[i]-x[a]) * (x[i]-x[a]) + (y[i]-y[a]) * (y[i]-y[a]));
        }
        ans = max(ans, dist);
    }
    
    cout << fixed << setprecision(5) << sqrt(ans);
}