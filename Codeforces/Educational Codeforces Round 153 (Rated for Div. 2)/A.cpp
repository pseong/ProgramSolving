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

bool test(string& s, string& a) {
    int n = a.size();
    for (int i=0; i<=n; i++) {
        if (s.substr(i, n) == a) return false;
    }
    return true;
}

void solve(int CASE) {
    string s;
    cin >> s;
    int n = s.size();
    string ans1 = string(n, '(') + string(n, ')');
    string ans2 = "";
    for (int i=0; i<n; i++) ans2 += "()";
    if (test(ans1, s)) yes(), cout << ans1 << '\n';
    else if (test(ans2, s)) yes(), cout << ans2 << '\n';
    else no();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
#if TEST
    freopen("/Users/seonguk/project/ProgramSolving/input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}