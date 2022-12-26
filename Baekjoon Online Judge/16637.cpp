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

int cal(int x, char c, int y) {
    if (c == '-') return x - y;
    else if (c == '*') return x * y;
    else return x + y;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    int c = n / 2;
    int ans = -1e9;
    for (int k=0; k<(1<<c); k++) {
        bool ok = false;
        for (int i=0; i<c; i++) {
            if (k & (1<<i) && k & (1<<(i+1))) ok = true;
        }
        if (ok) continue;
        int now = 0;
        for (int i=0; i<n; i+=2) {
            char c;
            if (i-1 >= 0) c = s[i-1];
            else c = '+';
            if (k & (1<<i/2)) {
                now = cal(now, c, cal(s[i] - '0', s[i+1], s[i+2] - '0'));
                i += 2;
            }
            else {
                if (i-1 >= 0) now = cal(now, c, s[i] - '0');
                else now = s[i] - '0';
            }
        }
        ans = max(ans, now);
    }
    cout << ans << '\n';
}