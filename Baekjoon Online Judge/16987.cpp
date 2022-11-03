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

int n, s[10], w[10], ans;

void go(int idx) {
    if (idx == n) {
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (s[i] <= 0) cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    if (s[idx] <= 0) {
        go(idx + 1);
        return;
    }
    bool ok = false;
    for (int i=0; i<n; i++) {
        if (i == idx) continue;
        if (s[i] > 0) {
            ok = true;
            s[i] -= w[idx];
            s[idx] -= w[i];
            go(idx + 1);    
            s[i] += w[idx];
            s[idx] += w[i];
        }
    }
    if (!ok) go(idx + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> w[i];
    }
    go(0);
    cout << ans << '\n';
}