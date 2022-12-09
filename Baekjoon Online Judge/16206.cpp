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

bool comp(int a, int b) {
    if (a % 10 == 0 && b % 10 == 0) return a < b;
    if (a%10 == 0 && b%10 != 0) return true;
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), comp);
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (v[i] % 10 == 0) {
            int cnt = v[i] / 10;
            if (m >= cnt - 1) {
                m -= cnt - 1;
                ans += cnt;
            }
            else {
                ans += m;
                m = 0;
            }
        }
        else {
            int cnt = v[i] / 10;
            int can = min(cnt, m);
            ans += can;
            m -= can;
        }
    }
    cout << ans << '\n';
}