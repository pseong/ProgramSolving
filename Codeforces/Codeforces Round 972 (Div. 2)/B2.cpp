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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (int i=0; i<m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int Q=0; Q<q; Q++) {
        int a;
        cin >> a;
        auto it = lower_bound(b.begin(), b.end(), a);
        if (it == b.end()) {
            cout << n - b.back() << '\n';
        }
        else if (it == b.begin()) {
            cout << b.front() - 1 << '\n';
        }
        else {
            cout << (*it - *(--it)) / 2 << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("C:/dnrseong/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}