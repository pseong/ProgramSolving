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

ll scores[]{1, 10, 100, 1000, 10000};
vector<ll> chk(5);
ll ans;

bool ok(ll x) {
    for (ll i=x+1; i<5; i++) {
        if (chk[i]) return false;
    }
    return true;
}

void cal(string& s) {
    ll n = s.size();
    chk.assign(5, 0);
    ll res = 0;
    for (ll i=n-1; i>=0; i--) {
        if (ok(s[i]-'A')) res += scores[s[i]-'A'];
        else res -= scores[s[i]-'A'];
        chk[s[i]-'A'] = 1;
    }
    ans = max(ans, res);
}

void solve(int CASE) {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> idx(5);
    for (int i=0; i<n; i++) {
        idx[s[i]-'A'].push_back(i);
    }
    ans = -2e9;
    cal(s);
    for (int k=0; k<5; k++) {
        if (idx[k].empty()) continue;
        for (int r=0; r<5; r++) {
            s[idx[k].front()] = 'A' + r;
            cal(s);
            s[idx[k].front()] = 'A' + k;
        }
        for (int r=0; r<5; r++) {
            s[idx[k].back()] = 'A' + r;
            cal(s);
            s[idx[k].back()] = 'A' + k;
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