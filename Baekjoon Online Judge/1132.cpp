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
    vector<ll> cnt(10);
    vector<int> dis(10);
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int m = s.size();
        dis[s[0]-'A'] = 1;
        for (int j=m-1; j>=0; j--) {
            cnt[s[j]-'A'] += pow(10, m-1-j);
        }
    }
    vector<pll> v(10);
    for (int i=0; i<10; i++) {
        v[i] = {cnt[i], i};
    }
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    int sel = 0;
    for (int i=9; i>=0; i--) {
        if (dis[v[i].second] == 0) {
            sel = i;
            break;
        }
    }
    int now = 9;
    for (int i=0; i<10; i++) {
        if (i == sel) continue;
        ans += v[i].first * now;
        now--;
    }
    cout << ans << '\n';
}