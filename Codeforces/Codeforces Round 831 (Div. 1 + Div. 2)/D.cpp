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
void no() { cout << "TIDAK" << '\n'; }
void yes() { cout << "YA" << '\n'; }

void solve(int CASE) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(k);
    for (int i=0; i<k; i++) cin >> v[i];
    v.push_back(k + 1);
    int left = n*m - 2;
    vector<int> chk(k + 1);
    int cur = 0;
    for (int i=k; i>=1; i--) {
        if (v[cur] == i) cur++;
        else if (v[cur] != i) {
            if (chk[i]) left++;
            else {
                if (left == 2) {
                    no();
                    return;
                }
                chk[v[cur]] = 1;
                left--;
                cur++;
                i++;
            }
        }
    }
    yes();
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