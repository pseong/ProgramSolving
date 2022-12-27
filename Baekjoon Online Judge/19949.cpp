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

int ans, v[11], c[11];

void go(int x) {
    if (x == 11) {
        bool ok = true;
        for (int i=3; i<=10; i++) {
            if (v[i] == v[i-1] && v[i-1] == v[i-2]) ok = false;
        }
        if (ok) {
            int cnt = 0;
            for (int i=1; i<=10; i++) {
                if (v[i] == c[i]) cnt++;
            }
            if (cnt >= 5) ans++;
        }
        return;
    }
    for (int i=1; i<=5; i++) {
        v[x] = i;
        go(x + 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i=1; i<=10; i++) {
        cin >> c[i];
    }
    go(1);
    cout << ans << '\n';
}