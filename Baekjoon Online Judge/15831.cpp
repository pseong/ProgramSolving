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

int n, b, w;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> b >> w;
    string s;
    cin >> s;
    int r = -1;
    int nowb = 0;
    int noww = 0;
    int ans = 0;
    for (int l=0; l<n; l++) {
        while (r + 1 < n && (s[r + 1] == 'W' || nowb + 1 <= b)) {
            r++;
            if (s[r] == 'W') noww++;
            else nowb++;
        }
        if (noww >= w) ans = max(ans, r - l + 1);
        if (s[l] == 'W') noww--;
        else nowb--;
    }
    cout << ans << '\n';
}