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

string mp[1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> m >> n;
    string s;
    cin >> s;
    int q = 0;
    for (int i=0; i<n; i++) {
        cin >> mp[i];
        if (mp[i][0] == '?') q = i;
    }
    vector<int> now(m);
    for (int j=0; j<m; j++) {
        int y = j;
        for (int i=0; i<q; i++) {
            if (y-1 >= 0 && mp[i][y-1] == '-') y--;
            else if (y < m && mp[i][y] == '-') y++;
        }
        now[j] = y; // 'A' + j
    }
    bool fail = false;
    vector<int> ans(m-1, -1);
    for (int j=0; j<m; j++) {
        int y = j;
        for (int i=n-1; i>q; i--) {
            if (y-1 >= 0 && mp[i][y-1] == '-') y--;
            else if (y < m - 1 && mp[i][y] == '-') y++;
        }
        if (now[s[j]-'A'] == y) {
            if (y-1 >= 0) {
                if (ans[y-1] == 1) fail = true; 
                ans[y-1] = 0;
            }
            if (y < m - 1) {
                if (ans[y] == 1) fail = true;
                ans[y] = 0;
            }
        }
        else if (now[s[j]-'A'] == y - 1) {
            if (y-1 >= 0) {
                if (ans[y-1] == 0) fail = true; 
                ans[y-1] = 1;
            }
            if (y < m - 1) {
                if (ans[y] == 1) fail = true;
                ans[y] = 0;
            }
        }
        else if (now[s[j]-'A'] == y + 1) {
            if (y-1 >= 0) {
                if (ans[y-1] == 1) fail = true; 
                ans[y-1] = 0;
            }
            if (y < m - 1) {
                if (ans[y] == 0) fail = true;
                ans[y] = 1;
            }
        }
        else fail = true;
    }
    if (fail) {
        cout << string(m-1, 'x') << '\n';
    }
    else {
        for (int i=0; i<m-1; i++) {
            if (ans[i] == 0) cout << '*';
            else cout << '-';
        }
    }
}