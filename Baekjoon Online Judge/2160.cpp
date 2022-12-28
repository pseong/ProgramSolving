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
    vector<vector<string>> v(n, vector<string>(5));
    for (int k=0; k<n; k++) {
        for (int i=0; i<5; i++) {
            cin >> v[k][i];
        }
    }
    vector<int> ans{(int)1e9, -1, -1};
    for (int a=0; a<n; a++) {
        for (int b=a+1; b<n; b++) {
            int cnt = 0;
            for (int i=0; i<5; i++) {
                for (int j=0; j<7; j++) {
                    if (v[a][i][j] != v[b][i][j]) cnt++;
                }
            }
            if (cnt < ans[0]) {
                ans[0] = cnt;
                ans[1] = a;
                ans[2] = b;
            }
        }
    }
    cout << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';
}