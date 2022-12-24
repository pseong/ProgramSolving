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
    
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (int i=0; i<(int)s.size(); i++) {
        cnt[s[i]-'A']++;
    }
    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int ans = 1e9;
    for (int i=0; i<(1<<n); i++) {
        int res = 0;
        vector<int> c(26);
        for (int k=0; k<n; k++) {
            if (i & (1<<k)) {
                res += v[k].first;
                for (int j=0; j<(int)v[k].second.size(); j++) {
                    c[v[k].second[j]-'A']++;
                }
            } 
        }
        bool ok = true;
        for (int j=0; j<26; j++) {
            if (cnt[j] > c[j]) ok = false;
        }
        if (ok) ans = min(ans, res);
    }
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}