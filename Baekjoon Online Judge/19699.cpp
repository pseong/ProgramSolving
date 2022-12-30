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

int n, m, prime[10101], v[1010];
set<int> ans;

void go(int idx, int now, int cnt) {
    if (idx == n) {
        if (cnt == m && prime[now] == 0) ans.insert(now);
        return;
    }
    go(idx + 1, now, cnt);
    go(idx + 1, now + v[idx], cnt + 1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    prime[0] = 1;
    prime[1] = 1;
    for (int i=2; i<=10000; i++) {
        if (prime[i] == 0) {
            for (int j=i+i; j<=10000; j+=i) {
                prime[j] = 1;
            }
        }
    }

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    go(0, 0, 0);
    if (ans.empty()) cout << -1 << '\n';
    else {
        for (int x : ans) {
            cout << x << ' ';
        }
    }
}