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

int n;
vector<int> v[1010];
vector<int> hist;
bool ok;
int dp[1010][10];

void go(int x) {
    if (dp[x][hist.back()]) return;
    if (x > n) {
        for (int y : hist) {
            if (y == 0) continue;
            cout << y << '\n';
        }
        ok = true;
        return;
    }
    for (int y : v[x]) {
        if (hist.back() == y) continue;
        hist.push_back(y);
        go(x + 1);
        if (ok) return;
        hist.pop_back();
    }
    dp[x][hist.back()] = 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=1; i<=n; i++) {
        int a;
        cin >> a;
        while (a--) {
            int b;
            cin >> b;
            v[i].push_back(b);
        }
    }
    hist.push_back(0);
    go(1);
    if (!ok) cout << -1 << '\n';
}