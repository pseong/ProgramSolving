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

int v[30][30];

signed main() {
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> v[i][j];
        }
    }
    int ans = 1e9;
    for (int k=1; k<(1<<n)-1; k++) {
        vector<int> team[2];
        for (int i=0; i<n; i++) {
            if (k & (1<<i)) team[1].push_back(i);
            else team[0].push_back(i);
        }
        int cnt[2] { 0 };
        for (int j=0; j<2; j++) {
            for (int i=0; i<(int)team[j].size(); i++) {
                for (int k=i+1; k<(int)team[j].size(); k++) {
                    cnt[j] += v[team[j][i]][team[j][k]];
                    cnt[j] += v[team[j][k]][team[j][i]];
                }
            }
        }
        ans = min(ans, abs(cnt[0] - cnt[1]));
    }
    cout << ans << '\n';
}