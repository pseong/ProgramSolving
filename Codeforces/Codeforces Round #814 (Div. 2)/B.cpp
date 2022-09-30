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
    int n, k;
    cin >> n >> k;
    if (k%2 == 1) {
        yes();
        for (int i=1; i<=n; i+=2) {
            cout << i << ' ' << i+1 << '\n';
        }
    }
    else {
        vector<pi> ans;
        for (int i=1; i<=n; i+=2) {
            if ((i+1)%4 == 0) ans.push_back({i, i+1});
            else {
                if ((i+k)%4 == 0) ans.push_back({i, i+1});
                else if ((i+1+k)%4 == 0) ans.push_back({i+1, i});
                else {
                    no();
                    return;
                }
            }
        }
        yes();
        for (int i=0; i<(int)ans.size(); i++) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }
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