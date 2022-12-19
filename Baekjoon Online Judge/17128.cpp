#include <bits/stdc++.h>
#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
using namespace std;
using ll=long long;
using i128 = __int128_t;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int>;
using tll=tuple<ll, ll, ll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
void no() { cout << "No" << '\n'; }
void yes() { cout << "Yes" << '\n'; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> v(n*3 + 1);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        v[i+n] = v[i];
        v[i+n*2] = v[i];
    }
    int sum = 0;
    for (int i=1; i<=n; i++) {
        sum += v[i] * v[i+1] * v[i+2] * v[i+3];
    }
    while (q--) {
        int a;
        cin >> a;
        int now = 0;
        for (int i=a+n-3; i<=a+n; i++) {
            now += v[i] * v[i+1] * v[i+2] * v[i+3];
        }
        sum -= now * 2;
        cout << sum << '\n';
        v[a] = -v[a];
        v[a+n] = -v[a+n];
        v[a+n*2] = -v[a+n*2];
    }
}