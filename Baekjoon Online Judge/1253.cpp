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

    int n;
    cin >> n;
    vector<int> v;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a != 0) v.push_back(a);
        mp[a]++;
    }
    sort(v.begin(), v.end());
    vector<int> v2;
    for (int i=0; i<(int)v.size(); i++) {
        for (int j=i+1; j<(int)v.size(); j++) {
            v2.push_back(v[i] + v[j]);
        }
    }
    int ans = 0;
    bool mirror = false;
    sort(v2.begin(), v2.end());
    for (int i=0; i<(int)v.size(); i++) {
        if (mp[0] > 0 && mp[v[i]] > 1) ans++;
        else {
            auto it = lower_bound(v2.begin(), v2.end(), v[i]);
            if (it != v2.end() && *it == v[i]) ans++;
        }
        if (mp[-v[i]] > 0) mirror = true;
    }
    if (mirror || mp[0] > 2) ans += mp[0];
    cout << ans << '\n';
}