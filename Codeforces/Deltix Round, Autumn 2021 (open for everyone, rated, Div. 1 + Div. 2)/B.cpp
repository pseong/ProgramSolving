#include <bits/stdc++.h>
#define int long long
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

int n, q;
string s;
bool chk(int i) {
    return (i >= 0 && i+2 < n && s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c');
}
void solve() {
    cin >> n >> q >> s;
    int sz = s.size();
    int cnt = 0;
    for (int i=0; i<sz-2; i++) {
        cnt += chk(i);
    }
    for (int Q=1; Q<=q; Q++) {
        int i; char c;
        cin >> i >> c;
        i--;
        cnt -= chk(i-2);
        cnt -= chk(i-1);
        cnt -= chk(i);
        s[i] = c;
        cnt += chk(i-2);
        cnt += chk(i-1);
        cnt += chk(i);
        cout << cnt << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}