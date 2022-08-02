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
    string s;
    cin >> s >> n;
    vector<string> v(n);
    set<string> st;
    map<string, int> mp;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        st.insert(v[i]);
        mp[v[i]] = i;
    }
    int t = s.size();
    vector<pi> ans;
    int i = 0;
    while (i < t) {
        for (int j=10; j>=1; j--) {
            int r = i + j - 1;
            if (r >= t) continue;
            for (int k=j; k<=10; k++) {
                int l = r - k + 1;
                int d = r - l + 1;
                if (l < 0) continue;
                string str = s.substr(l, d);
                if (st.find(str) != st.end()) {
                    ans.push_back({mp[str]+1, l+1});
                    i = r + 1;
                    goto g;
                }
            }
        }
        cout << -1 << '\n';
        return;
        g:
        continue;
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a << ' ' << b << '\n';
    }
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}