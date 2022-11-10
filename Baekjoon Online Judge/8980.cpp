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

struct Box {
    int s, e, cnt;

    bool operator< (Box& b) {
        if (e != b.e) return e < b.e;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, c, m;
    cin >> n >> c >> m;
    vector<Box> v(m);
    for (int i=0; i<m; i++) {
        int s, e, cnt;
        cin >> s >> e >> cnt;
        v[i] = {s, e, cnt};
    }
    sort(v.begin(), v.end());
    vector<int> cnt(n+1);
    int ans = 0;
    for (int i=0; i<m; i++) {
        int left = c;
        for (int j=v[i].s; j<v[i].e; j++) {
            left = min(left, c - cnt[j]);
        }
        int pos = min(left, v[i].cnt);
        ans += pos;
        for (int j=v[i].s; j<v[i].e; j++) {
            cnt[j] += pos;
        }
    }
    cout << ans << '\n';
}