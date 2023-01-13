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
    int dir = 0;
    if (s[0] == s[1]) {
        cout << s[0] << ' ' << s[1] << ' ' << s.substr(2) << '\n';
        return;
    }
    if (s[n-2] == s[n-1]) {
        cout << s.substr(0, n-2) << ' ' << s[n-2] << ' ' << s[n-1] << '\n';
        return;
    }
    for (int i=1; i<(int)s.size(); i++) {
        if (dir == 0) {
            if (s[i] > s[i-1]) dir = 1;
            else if (s[i] < s[i-1]) dir = -1;
        }
        else {
            if (s[i] > s[i-1] && dir == -1 || s[i] < s[i-1] && dir == 1) {
                cout << s.substr(0, i-1) << ' ' << s[i-1] << ' ' << s.substr(i) << '\n';
                return;
            }

        }
    }
    if (dir == 0) {
        cout << s[0] << ' ' << string(s.size() - 2, s[0]) << ' ' << s[0] << '\n';
        return;
    }
    cout << ":(\n";
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