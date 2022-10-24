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
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> mp;
    for (int i=0; i<n; i++) {
        int h, w;
        cin >> h >> w;
        mp[h].push_back(w);
    }
    for (int i=1; i<=1000; i++) {
        sort(mp[i].begin(), mp[i].end());
    }
    vector<vector<ll>> pref(1001);
    for (int i=1; i<=1000; i++) {
        if (mp[i].size() == 0) continue;
        pref[i].resize(mp[i].size());
        pref[i][0] = mp[i][0];
        for (int j=1; j<mp[i].size(); j++) {
            pref[i][j] = pref[i][j-1] + mp[i][j];
        }
    }
    for (int Q=0; Q<q; Q++) {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        ll cnt = 0;
        for (int i=hs+1; i<=hb-1; i++) {
            auto it = upper_bound(mp[i].begin(), mp[i].end(), ws);
            auto it2 = lower_bound(mp[i].begin(), mp[i].end(), wb);
            if (it2 == mp[i].begin()) continue;
            it2--;
            if (it2 - it < 0) continue;
            if (it == mp[i].begin()) {
                cnt += i * pref[i][it2 - mp[i].begin()];
            }
            else {
                cnt += i * (pref[i][it2 - mp[i].begin()] - pref[i][it - mp[i].begin() - 1]);
            }
        }
        cout << cnt << '\n';
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