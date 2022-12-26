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

string s, t;
int ans;
void go() {
    if (s.size() == t.size()) {
        if (s == t) ans = 1;
        return;
    }
    if (t.back() == 'A') {
        t.pop_back();
        go();
        t.push_back('A');
    }
    if (t.front() == 'B') {
        reverse(t.begin(), t.end());
        t.pop_back();
        go();
        t.push_back('B');
        reverse(t.begin(), t.end());
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s >> t;
    go();
    cout << ans << '\n';
}