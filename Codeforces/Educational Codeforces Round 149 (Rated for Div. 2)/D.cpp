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

bool ok(string& s) {
    int open = 0, close = 0;
    int n = s.size();
    for (int i=0; i<n; i++) {
        if (s[i] == '(') open++;
        else {
            close++;
            if (close > open) return false;
        }
    }
    return true;
}

void solve(int CASE) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int open = 0, close = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') open++;
        else close++;
    }
    if (open != close) {
        cout << -1 << '\n';
        return;
    }
    string rs = s;
    reverse(all(rs));
    if (ok(s) || ok(rs)) {
        cout << 1 << '\n';
        for (int i=0; i<n; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
        return; 
    }
    open = 0;
    close = 0;
    int open2 = 0, close2 = 0;
    vector<int> ans(n);
    for (int i=0; i<n; i++) {
        if (s[i] == '(') {
            if (close2 > open2) {
                open2++;
                ans[i] = 2;
            }
            else {
                open++;
                ans[i] = 1;
            }
        }
        else {
            if (open <= close) {
                close2++;
                ans[i] = 2;
            }
            else {
                close++;
                ans[i] = 1;
            }
        }
    }
    cout << 2 << '\n';
    for (int i=0; i<n; i++) {
        cout << ans[i] << ' ';
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