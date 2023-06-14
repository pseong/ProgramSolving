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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    string t = s;
    string ans;
    for (int i=0; i<30; i++) {
        t.insert(t.begin(), '0');
        t.pop_back();
        string res(n, 'x');
        for (int i=0; i<n; i++) {
            res[i] = ((s[i]-'0') | (t[i]-'0')) + '0';
        }
        ans = max(ans, res);
    }
    if (ans.find('1') == string::npos) cout << 0 << '\n';
    else cout << ans.substr(ans.find('1')) << '\n';
}