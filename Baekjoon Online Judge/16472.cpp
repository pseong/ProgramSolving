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
    cin >> n;
    string s;
    cin >> s;
    int r = -1;
    vector<int> chk(26);
    int cnt = 0;
    int ans = 0;
    for (int l=0; l<(int)s.size(); l++) {
        while (r + 1 < (int)s.size() && cnt + (chk[s[r + 1]-'a'] == 0 ? 1 : 0) <= n) {
            r++;
            if (++chk[s[r]-'a'] == 1) cnt++;
        }
        ans = max(ans, r - l + 1);
        if (--chk[s[l]-'a'] == 0) cnt--;
    }
    cout << ans << '\n';
}