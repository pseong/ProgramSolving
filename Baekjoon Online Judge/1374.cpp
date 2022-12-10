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

struct Event {
    int x, op;

    bool operator< (Event& r) {
        if (x != r.x) return x < r.x;
        return op < r.op;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<Event> v;
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({b, 1});
        v.push_back({c, -1});
    }
    sort(v.begin(), v.end());
    int now = 0;
    int ans = 0;
    for (int i=0; i<(int)v.size(); i++) {
        if (v[i].op == 1) now++;
        else now--;
        ans = max(ans, now);
    }
    cout << ans << '\n';
}