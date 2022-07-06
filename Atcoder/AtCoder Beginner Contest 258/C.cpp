#include <bits/stdc++.h>
#define int long long
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

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cur = 0;
    for (int Q=0; Q<q; Q++) {
        int what;
        cin >> what;
        if (what == 1) {
            int x; cin >> x;
            cur = (cur - x + n) % n;
        }
        else {
            int x; cin >> x;
            x--;
            cout << s[(cur+x)%n] << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}