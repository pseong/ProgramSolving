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

bool okSlump(int l, int r) {
    if (l > r) return false;
    int i = l;
    if (s[i] == 'D' || s[i] == 'E') {
        i++;
        int cnt = 0;
        while (i <= r && s[i] == 'F') {
            i++;
            cnt++;
        }
        if (cnt < 1) return false;
        if (i <= r && s[i] == 'G') {
            if (i == r) return true;
            else return false;
        }
        else return okSlump(i, r);
    }
    else return false;
}

bool okSlimp(int l, int r) {
    if (l > r) return false;
    int i = l;
    if (s[i] == 'A') {
        i++;
        if (s[i] == 'H') {
            if (i < r) return false;
            else return true;
        }
        else if (s[r] != 'C') return false;
        else if (s[i] == 'B') return okSlimp(i + 1, r - 1);
        else return okSlump(i, r - 1);
    }
    else return false;
}

void solve(int CASE) {
    cin >> s;
    int idx = 1;
    for (int i=0; i<(int)s.size(); i++) {
        if (s[i] == 'C') idx = i;
    }
    if (okSlimp(0, idx) && okSlump(idx + 1, (int)s.size() - 1)) cout << "YES\n";
    else cout << "NO\n";
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