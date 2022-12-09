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
    
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> v[i];
        sum += v[i].size();
    }
    int cnt = (m - sum) / (n - 1); //  n - 1 - left 개는 cnt
    int left = (m - sum) % (n - 1); // left 개는 cnt + 1
    int up = left;
    int down = n - 1 - left;
    string ans = v[0];
    for (int i=1; i<n; i++) {
        if (v[i][0] >= 'a') {
            if (up) {
                ans += string(cnt + 1, '_');
                up--;
            }
            else {
                down--;
                ans += string(cnt, '_');
            }
        }
        else {
            if (down) {
                down--;
                ans += string(cnt, '_');
            }
            else {
                ans += string(cnt + 1, '_');
                up--;
            }
        }
        ans += v[i];
    }
    cout << ans << '\n';
}