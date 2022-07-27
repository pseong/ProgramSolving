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

vector<int> p;
void solve(int CASE) {
    int n;
    cin >> n;
    vector<int> v(n+1), pref(n+1);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        v[a]++;
    }
    for (int i=1; i<=n; i++) {
        pref[i] = pref[i-1] + v[i];
    }
    int ans = INT_MAX;
    for (int i=0; i<=n; i++) {
        int x = *(lower_bound(p.begin(), p.end(), pref[i])) - pref[i];
        for (int k=0; k<(int)p.size(); k++) {
            int j = upper_bound(pref.begin()+i+1, pref.end(), p[k]+pref[i]) - pref.begin() - 1;
            int y = p[k] - pref[j] + pref[i];
            int z = *(lower_bound(p.begin(), p.end(), pref[n] - pref[j])) - (pref[n] - pref[j]);
            ans = min(ans, x + y + z);
        }
    }
    cout << ans << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int i = 1;
    while (true) {
        p.push_back(i);
        if (i >= 200000) break;
        i *= 2;
    }

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}