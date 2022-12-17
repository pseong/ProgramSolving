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

ll res = 0;
vector<int> v;
int n, k;

void solve(int CASE) {
    cin >> n >> k;
    v.resize(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int l = 0;
    int r = n - 1;
    int ans = 1e9;
    int cnt = 0;
    while (l < r) {
        int c = v[l] + v[r];
        if (ans > abs(k - c)) {
            cnt = 1;
            ans = abs(k - c);
        }
        else if (ans == abs(k - c)) cnt++;
        if (c == k) l++;
        else if (c < k) l++;
        else r--;
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}