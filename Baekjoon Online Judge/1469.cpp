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

int n, v[20];
vector<int> ans;
vector<vector<int>> res;

void go(int idx) {
    if (idx == n) {
        res.push_back(ans);
        return;
    }
    for (int i=v[idx]+1; i<n*2; i++) {
        if (ans[i-v[idx]-1] == -1 && ans[i] == -1) {
            ans[i] = v[idx];
            ans[i-v[idx]-1] = v[idx];
            go(idx + 1);
            ans[i] = -1;
            ans[i-v[idx]-1] = -1;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    ans.assign(n*2, -1);
    go(0);
    sort(res.begin(), res.end());
    if (res.empty()) cout << -1 << '\n';
    else for (int x : res[0]) cout << x << ' ';
}