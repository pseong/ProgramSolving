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
    string s;
    cin >> s;
    int n = s.size();
    int open = n / 2;
    int close = n / 2;
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') open--;
        else if (s[i] == ')') close--;
        else v.push_back(i);
    }
    if (open == 0 || close == 0) {
        yes();
        return;
    }
    for (int i=0; i<open; i++) {
        s[v[i]] = '(';
    }
    for (int i=open; i<v.size(); i++) {
        s[v[i]] = ')';
    }
    swap(s[v[open-1]], s[v[open]]);
    bool ok = true;
    int c = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') c++;
        else {
            c--;
            if (c < 0) {
                ok = false;
                break;
            }
        }
    }
    if (ok) no();
    else yes();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        solve(t);
    }
}