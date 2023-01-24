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

string s[2];
int n, cnt;

bool go(int i) {
    vector<vector<int>> chk(2, vector<int>(n));
    for (int j=0; j<n; j++) {
        if (s[i][j] != 'B') break;
        chk[i][j] = 1;
        if (s[i^1][j] == 'B') {
            i ^= 1;
            chk[i][j] = 1;
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
            if (s[i][j] == 'B' && chk[i][j] == 0) return false;
        }
    }
    return true;
}

void solve(int CASE) {
    cin >> n;
    cin >> s[0] >> s[1];
    cnt = 0;
    for (int i=0; i<n; i++) {
        cnt += (s[0][i] == 'B') + (s[1][i] == 'B');
    }
    if (go(0) || go(1)) yes();
    else no();
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