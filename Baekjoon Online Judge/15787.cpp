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
    vector<vector<int>> v(n+1, vector<int>(20));
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int i, x;
            cin >> i >> x;
            v[i][x-1] = 1;
        }
        else if (what == 2) {
            int i, x;
            cin >> i >> x;
            v[i][x-1] = 0;
        }
        else if (what == 3) {
            int i;
            cin >> i;
            for (int j=18; j>=0; j--) {
                v[i][j+1] = v[i][j];
            }
            v[i][0] = 0;
        }
        else if (what == 4) {
            int i;
            cin >> i;
            for (int j=1; j<20; j++) {
                v[i][j-1] = v[i][j];
            }
            v[i][19] = 0;
        }
    }
    int ans = 0;
    set<vector<int>> st;
    for (int i=1; i<=n; i++) {
        int prev = st.size();
        st.insert(v[i]);
        int next = st.size();
        if(prev != next) ans++;
    }
    cout << ans << '\n';
}