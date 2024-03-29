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

void solve(int CASE) {
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), pref(n + 1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        pref[i] = pref[i-1] + b[i];
    }
    vector<ll> ans(n + 1), add(n + 1);
    for (int i=1; i<=n; i++) {
        int e = lower_bound(pref.begin()+i, pref.end(), a[i] + pref[i-1]) - pref.begin();
        ll sum = pref[e-1] - pref[i-1];
        if (e > n) {
            ans[i]++;
        }
        else {
            ans[i]++;
            ans[e]--;
            add[e] += a[i] - sum;
        }
    }
    ll now = 0;
    for (int i=1; i<=n; i++) {
        now += ans[i];
        cout << now * b[i] + add[i] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}