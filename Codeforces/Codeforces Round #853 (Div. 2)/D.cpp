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

string query(string s, int k) {
    int n = s.size();
    if (k > 0) {
        string t = s;
        t.append(string(k, '0'));
        t.erase(t.begin(), t.begin() + k);
        string res(n, '0');
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) res[i] = '1';
        }
        return res;
    }
    else {
        k = -k;
        string t = s;
        t = string(k, '0') + t;
        t.erase(t.begin() + n, t.end());
        string res(n, '0');
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) res[i] = '1';
        }
        return res;
    }
}

void solve(int CASE) {
    string a, b;
    int n;
    cin >> n >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    bool o = false, oo = false;
    for (int i=0; i<n; i++) {
        if (a[i] == '1') o = true;
        if (b[i] == '1') oo = true;
    }
    if (o != oo) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    int idx = 0;
    for (int i=0; i<n; i++) {
        if (b[i] == '1') idx = i;
    }
    if (a[idx] != b[idx]) {
        int i2 = 0;
        for (int i=0; i<n; i++) {
            if (a[i] == '1') i2 = i;
        }
        a = query(a, i2 - idx);
        ans.push_back(i2 - idx);
    }
    int ai = 0;
    for (int i=n-1; i>=0; i--) {
        if (a[i] == '1') ai = i;
    }
    for (int i=idx+1; i<n; i++) {
        if (a[i] == '1') {
            a = query(a, ai - i);
            ans.push_back(ai - i);
        }
    }
    for (int i=idx-1; i>=0; i--) {
        if (a[i] != b[i]) {
            a = query(a, idx - i);
            ans.push_back(idx - i);
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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