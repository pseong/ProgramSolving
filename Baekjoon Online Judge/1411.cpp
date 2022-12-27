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
    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            vector<char> chg(26, '.');
            vector<int> chk(26);
            bool ok = true;
            for (int k=0; k<(int)v[i].size(); k++) {
                if (chg[v[i][k]-'a'] == '.') {
                    chg[v[i][k]-'a'] = v[j][k];
                    if (chk[v[j][k]-'a']) ok = false;
                    chk[v[j][k]-'a'] = 1;
                }
                if (chg[v[i][k]-'a'] != v[j][k]) ok = false;
            }
            if (ok) ans++;
        }
    }
    cout << ans << '\n';
}