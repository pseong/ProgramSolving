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

string s;
vector<int> v;
ll ans, chk[300];

void go(int idx, int pprev, int prev, int l, ll cnt) {
    if (idx == s.size()) {
        if (l) ans += cnt;
        return;
    }
    if (s[idx] == '_') {
        if (pprev == prev) {
            if (prev == 1) {
                go(idx+1, prev, 0, l, cnt * 20);
                go(idx+1, prev, 0, 1, cnt);
            }
            else if (prev == 0) {
                go(idx+1, prev, 1, l, cnt * 5);
            }
        }
        else {
            go(idx+1, prev, 0, l, cnt * 20);
            go(idx+1, prev, 0, 1, cnt);
            go(idx+1, prev, 1, l, cnt * 5);
        }
    }
    else {
        if (pprev == prev && prev == chk[s[idx]]) return;
        go(idx+1, prev, chk[s[idx]], l | (s[idx] == 'L' ? 1 : 0), cnt);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    chk['A'] = 1;
    chk['E'] = 1;
    chk['I'] = 1;
    chk['O'] = 1;
    chk['U'] = 1;
    go(0, -1, -2, 0, 1);
    cout << ans << '\n';
}