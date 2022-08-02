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
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(a*60 + b);
    }
    srt(v);
    v.push_back(v.front() + 24 * 60);
    int a = *lower_bound(v.begin(), v.end(), h*60+m);
    int b = a - h*60 - m;
    cout << b/60 << ' ' << b%60 << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}