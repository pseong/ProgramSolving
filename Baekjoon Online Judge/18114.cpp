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

int chk[100000001];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        chk[v[i]]++;
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (v[i] == m) ans = 1;
        for (int j=i+1; j<n; j++) {
            if (v[i] + v[j] == m) ans = 1;
            chk[v[i]]--;
            chk[v[j]]--;
            int a = m - v[i] - v[j];
            if (a > 0 && chk[a]) ans = 1;
            chk[v[i]]++;
            chk[v[j]]++;
        }
    }
    cout << ans << '\n';
}