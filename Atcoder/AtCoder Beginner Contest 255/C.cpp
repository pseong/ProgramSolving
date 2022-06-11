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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    if (d < 0) {
        a += (n-1)*d;
        d = -d;
    }
    ll b = a+(n-1)*d;
    if (x <= a) {
        cout << a-x;
    }
    else if (x >= b) {
        cout << x-b;
    }
    else {
        ll v = (x-a)%d;
        cout << min(v, d-v);
    }
}