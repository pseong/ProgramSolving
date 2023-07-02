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

// 0 : ㅎㅎ, 1 : ㅎㅉ, 2 : ㅉㅎ, 3 : ㅉㅉ

set<ti> st[4];
pi bias[4];
vector<int> g{ 0, 1, 2, 3 };

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int idx = (i-1)*n + j;
            if (i%2 && j%2) st[0].insert({i, j, idx});
            else if (i%2 && !(j%2)) st[1].insert({i, j, idx});
            else if (!(i%2) && j%2) st[2].insert({i, j, idx});
            else if (!(i%2) && !(j%2)) st[3].insert({i, j, idx});
        }
    }

    while (q--) {
        string s;
        cin >> s;
        if (s == "RO") {
            int a, b;
            for (int i=0; i<4; i++) {
                if (g[i] == 0) a = i;
                else if (g[i] == 1) b = i;
            }
            swap(g[a], g[b]);
            bias[a].second++;
            bias[b].second++;
        }
        else if (s == "RE") {
            int a, b;
            for (int i=0; i<4; i++) {
                if (g[i] == 2) a = i;
                else if (g[i] == 3) b = i;
            }
            swap(g[a], g[b]);
            bias[a].second++;
            bias[b].second++;
        }
        else if (s == "CO") {
            int a, b;
            for (int i=0; i<4; i++) {
                if (g[i] == 0) a = i;
                else if (g[i] == 2) b = i;
            }
            swap(g[a], g[b]);
            bias[a].first++;
            bias[b].first++;
        }
        else if (s == "CE") {
            int a, b;
            for (int i=0; i<4; i++) {
                if (g[i] == 1) a = i;
                else if (g[i] == 3) b = i;
            }
            swap(g[a], g[b]);
            bias[a].first++;
            bias[b].first++;
        }
        else {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            int a, b;
            if (r1%2 && c1%2) a = 0;
            else if (r1%2 && !(c1%2)) a = 1;
            else if (!(r1%2) && c1%2) a = 2;
            else a = 3;

            if (r2%2 && c2%2) b = 0;
            else if (r2%2 && !(c2%2)) b = 1;
            else if (!(r2%2) && c2%2) b = 2;
            else b = 3;

            for (int i=0; i<4; i++) {
                if (g[i] == a) {
                    a = i;
                    break;
                }
            }

            for (int i=0; i<4; i++) {
                if (g[i] == b) {
                    b = i;
                    break;
                }
            }

            r1 -= bias[a].first;
            r1 = (((r1 - 1) % n) + n) % n + 1;
            c1 -= bias[a].second;
            c1 = (((c1 - 1) % n) + n) % n + 1;

            r2 -= bias[b].first;
            r2 = (((r2 - 1) % n) + n) % n + 1;
            c2 -= bias[b].second;
            c2 = (((c2 - 1) % n) + n) % n + 1;

            ti A = {r1, c1, 1e9};
            ti B = {r2, c2, 1e9};

            auto it = st[a].lower_bound(A);
            it--;
            auto [x1, y1, idxA] = *it;
            st[a].erase(it);

            auto it2 = st[b].lower_bound(B);
            it2--;
            auto [x2, y2, idxB] = *it2;
            st[b].erase(it2);

            st[a].insert({x1, y1, idxB});
            st[b].insert({x2, y2, idxA});
        }
    }

    vector<vector<int>> ans(n + 1, vector<int>(n + 1));
    for (int i=0; i<4; i++) {
        for (auto [x, y, c] : st[i]) {
            ans[(x-1+bias[i].first)%n+1][(y-1+bias[i].second)%n+1] = c;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}