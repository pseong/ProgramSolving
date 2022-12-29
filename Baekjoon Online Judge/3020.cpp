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

int n, h, cnt, c[505050], t[505050];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> h;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (i % 2 == 0) {
            c[1]++;
            c[a+1]--;
        }
        else {
            c[h-a+1]++;
            c[h+1]--;
        }
    }
    int now = 0;
    vector<int> ans{(int)1e9, 0};
    for (int i=1; i<=h; i++) {
        now += c[i];
        t[i] = now;
        if (ans[0] == t[i]) ans[1]++;
        else if (ans[0] > t[i]) {
            ans[0] = t[i];
            ans[1] = 1;
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}