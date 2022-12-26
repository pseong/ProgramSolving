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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> ans;
    for (int k=1; k<=n; k++) {
        vector<int> res{n, k};
        while (true) {
            int n = res.size();
            int a = res[n-2] - res[n-1];
            if (a < 0) break;
            res.push_back(a);
        }
        if (ans.size() < res.size()) ans = res;
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
}