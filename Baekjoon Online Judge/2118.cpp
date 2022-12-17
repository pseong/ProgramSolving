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

int sum, v[50505];

int dist(int len) {
    int ret = min(len, sum - len);
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n*2);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        v[i+n] = v[i];
        sum += v[i];
    }
    int j = -1;
    int now = 0;
    int ans = 0;
    for (int i=0; i<n; i++) {
        while (j<n*2 && now + v[j+1] <= sum / 2) {
            j++;
            now += v[j];
        }
        ans = max(ans, dist(now));  
        ans = max(ans, dist(now + v[j+1]));
        now -= v[i];
    }
    cout << ans << '\n';
}