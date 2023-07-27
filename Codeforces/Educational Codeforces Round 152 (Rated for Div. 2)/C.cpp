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
    int n, m;
    string s;
    cin >> n >> m >> s;
    s.insert(s.begin(), ' ');
    vector<int> l(n + 2), r(n + 2);
    for (int i=1; i<=n; i++) {
        r[i] = r[i-1];
        if (s[i] == '0') r[i] = i;
    }
    for (int i=n; i>=1; i--) {
        l[i] = l[i+1];
        if (s[i] == '1') l[i] = i;
    }
    int k = 0;
    set<pi> st;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        if (x == y || l[x] == 0 || r[y] == 0 || l[x] > r[y]) k = 1;
        else st.insert({l[x], r[y]});
    }
    cout << st.size() + k << '\n';
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