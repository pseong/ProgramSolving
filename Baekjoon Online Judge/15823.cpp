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

int n, m, v[101010];

bool cal(int x) {
    vector<int> chk(500001);
    int i = 0;
    int cnt = 0;
    for (int j=0; j<n; j++) {
        while (chk[v[j]]) {
            chk[v[i]]--;
            i++;
        }
        chk[v[j]] = 1;
        if (j - i + 1 == x) {
            cnt++;
            while (i <= j) {
                chk[v[i]]--;
                i++;
            }
        }
    }
    return cnt >= m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    int lo = 1;
    int hi = 100000;
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi) / 2;
        if (cal(m)) {
            ans = m;
            lo = m + 1;
        }
        else hi = m - 1;
    }
    cout << ans << '\n';
}