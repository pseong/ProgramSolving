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
    int n, m;
    cin >> n >> m;
    int l = 0, r = 0;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == -1) {
            l++;
        }
        else if (a == -2) {
            r++;
        }
        else {
            v.push_back(a);
        }
    }
    srt(v);
    v.erase(unique(v.begin(), v.end()), v.end());
    int k = v.size();
    int ans = min(m, max(r + k, l + k));
    // 왼쪽 i개, 오른쪽 k-i-1
    for (int i=0; i<k; i++) {
        ans = max(ans, min(v[i]-1, i + l) + 1 + min(m-v[i], k-i-1 + r));
    }
    cout << ans << '\n';
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