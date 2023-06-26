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

ll _hash(vector<int>& v) {
    ll ret = 0;
    for (auto w : v) ret *= 3, ret += w;
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    set<ll> st;
    vector<vector<int>> v(n, vector<int>(k));
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            cin >> v[i][j];
        }
        st.insert(_hash(v[i]));
    }
    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll res = 0;
        for (int j=0; j<n; j++) {
            if (j == i) continue;
            vector<int> f(k);
            for (int x=0; x<k; x++) {
                if (v[i][x] == v[j][x]) f[x] = v[i][x];
                else f[x] = 3 - v[i][x] - v[j][x];
            }
            if (st.count(_hash(f))) res++;
        }
        res /= 2;
        ans += (res - 1)*res/2;
    }
    cout << ans << '\n';
}