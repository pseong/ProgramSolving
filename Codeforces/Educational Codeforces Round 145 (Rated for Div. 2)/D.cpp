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

const ll d = 1e12;
void solve(int CASE) {
    string s;
    cin >> s;
    int n = s.size();
    s.insert(s.begin(), 'x');
    vector<ll> zero(n + 1), one(n + 1);
    for (int i=1; i<=n; i++) {
        zero[i] = zero[i-1];
        one[i] = one[i-1];
        if (s[i] == '0') zero[i]++;
        else one[i]++;
    }
    ll ans = one[n] * (d + 1);
    for (int i=1; i<=n; i++) {
        ll cnt = zero[n] - zero[i-1] + one[i-1] - one[0];
        if (s[i-1] == '1' && s[i] == '0') {
            ans = min(ans, (cnt - 2) * (d + 1) + d);
        }
        else {
            ans = min(ans, cnt * (d + 1));
        }
    }
    cout << ans << '\n';
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