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
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    int mex = 0;
    while (mp[mex] > 0) {
        mex++;
    }
    if (mex == 0) {
        yes();
        return;
    }
    int l = -1;
    int r = -1;
    for (int i=n-1; i>=0; i--) {
        if (v[i] == mex + 1) l = i;
    }
    for (int i=0; i<n; i++) {
        if (v[i] == mex + 1) r = i;
    }
    if (l == -1) {
        bool ok = false;
        for (auto [x, cnt] : mp) {
            if (x > mex || x < mex && cnt > 1) ok = true;
        }
        if (ok) yes();
        else no();
    }
    else {
        mp.clear();
        for (int i=l; i<=r; i++) {
            v[i] = mex;
        }
        for (int i=0; i<n; i++) {
            mp[v[i]]++;
        }
        int prev = mex;
        mex = 0;
        while (mp[mex] > 0) mex++;
        if (prev + 1 == mex) yes();
        else no();
    }
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