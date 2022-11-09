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

int cal[] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int go(int a, int b) {
    return accumulate(cal, cal + a, b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pi> v(n);
    for (int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i].first = go(a, b);
        v[i].second = go(c, d) - 1;
    }
    sort(v.begin(), v.end());
    int now = go(3, 1);
    int next = -1;
    int ans = 0;
    int i = 0;
    while (true) {
        if (i < n && v[i].first <= now) {
            next = max(next, v[i].second);
            i++;
        }
        else if (next < now) {
            cout << 0 << '\n';  
            return 0;   
        }
        else {
            ans++;
            now = next + 1;
            next = -1;
            if (now > go(11, 30)) break;
        }
    }
    cout << ans << '\n';
}