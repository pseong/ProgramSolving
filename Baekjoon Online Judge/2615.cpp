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

int v[50][50];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 19;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (v[i][j-1] != v[i][j] && v[i][j+4] != v[i][j+5]) {
                set<int> st{v[i][j], v[i][j+1], v[i][j+2], v[i][j+3], v[i][j+4]};
                if (st.size() == 1 && *st.begin() != 0) {
                    cout << *st.begin() << '\n';
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
            if (v[i-1][j] != v[i][j] && v[i+4][j] != v[i+5][j]) {
                set<int> st{v[i][j], v[i+1][j], v[i+2][j], v[i+3][j], v[i+4][j]};
                if (st.size() == 1 && *st.begin() != 0) {
                    cout << *st.begin() << '\n';
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
            if (v[i][j] != v[i-1][j-1] && v[i+4][j+4] != v[i+5][j+5]) {
                set<int> st{v[i][j], v[i+1][j+1], v[i+2][j+2], v[i+3][j+3], v[i+4][j+4]};
                if (st.size() == 1 && *st.begin() != 0) {
                    cout << *st.begin() << '\n';
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
            if (v[i][j] != v[i+1][j-1] && v[i-4][j+4] != v[i-5][j+5]) {
                set<int> st{v[i][j], v[i-1][j+1], v[i-2][j+2], v[i-3][j+3], v[i-4][j+4]};
                if (st.size() == 1 && *st.begin() != 0) {
                    cout << *st.begin() << '\n';
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            }
        }
    }
    cout << 0 << '\n';
}