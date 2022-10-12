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

ll n, l, r, cnt;
string s;
void invert() {
    while (l <= r) {
        if (l >= n-1 - r) {
            if (s[r] == 'R') {
                s[r] = 'L';
                cnt -= n-1 - r;
                cnt += r;
                r--;
                return;
            }
            r--;
        }
        else {
            if (s[l] == 'L') {
                s[l] = 'R';
                cnt -= l;
                cnt += n-1 - l;
                l++;
                return;
            }
            l++;
        }
    }
}

void solve(int CASE) {
    cin >> n >> s;
    cnt = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'L') cnt += i;
        else cnt += n-1 - i;
    }
    l = 0;
    r = n-1;
    for (int i=1; i<=n; i++) {
        invert();
        cout << cnt << ' ';
    }
    cout << '\n';
}

int T = 1;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}