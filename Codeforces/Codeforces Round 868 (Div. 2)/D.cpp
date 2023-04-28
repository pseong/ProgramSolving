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

char get() {
    static int idx = -1;
    idx++;
    idx %= 3;
    return 'a' + idx;
}

void solve(int CASE) {
    int n, k;
    cin >> n >> k;
    vector<int> x(k), c(k);
    for (int i=0; i<k; i++) {
        cin >> x[i];
        x[i]--;
    }
    for (int i=0; i<k; i++) cin >> c[i];
    
    if (x[0] + 1 < c[0]) {
        no();
        return;
    }

    string ans(n, ' ');
    int now = 0;
    int cnt = 3;
    char t = 'd';
    for (int i=0; i<k; i++) {
        int need = c[i] - cnt;
        if (x[i] - now + 1 < need) {
            no();
            return;
        }
        cnt += need;
        for (int j=0; j<need; j++) {
            ans[now] = t;
            now++;
        }
        t++;
        while (now <= x[i]) {
            ans[now] = get();
            now++;
        }
    }
    while (now < n) {
        ans[now] = get();
        now++;
    }
    yes();
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t=1; t<=T; t++) {
        solve(t);
    }
}