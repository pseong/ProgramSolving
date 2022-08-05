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

vector<int> z(string& s) {
    int n = s.size();
    vector<int> v(n);
    v[0] = n;
    int m = 0, p = 0;
    for (int i=1; i<n; i++) {
        if (i <= m) v[i] = min(m - i, v[i-p]);
        while (i + v[i] < n && s[i + v[i]] == s[v[i]]) v[i]++;
        if (i + v[i] > m) {
            m = i + v[i];
            p = i;
        }
    }
    return v;
}

void solve(int CASE) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<int> res = z(s);
    reverse(res.begin(), res.end());
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << res[x-1] << '\n';
    }
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int t=1; t<=T; t++) {
        solve(t);
    }
}