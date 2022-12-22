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

int n1, m1, n2, m2;
int v[400][400], v2[400][400];

bool ok(int x, int y) {
    for (int i=0; i<n2; i++) {
        for (int j=0; j<m2; j++) {
            if (v[x+i][y+j] && v2[i+1][j+1]) return false;
        }
    }
    return true;
}

void rotate() {
    vector<vector<int>> tmp(200, vector<int>(200));
    for (int i=1; i<=n2; i++) {
        for (int j=1; j<=m2; j++) {
            tmp[j][n2+1-i] = v2[i][j];
        }
    }
    memset(v2, 0, sizeof v2);
    swap(n2, m2);
    for (int i=1; i<=n2; i++) {
        for (int j=1; j<=m2; j++) {
            v2[i][j] = tmp[i][j];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n1 >> m1;
    string s;
    for (int i=1; i<=n1; i++) {
        cin >> s;
        for (int j=1; j<=m1; j++) {
            v[i+200][j+200] = s[j-1] - '0';
        }
    }
    cin >> n2 >> m2;
    for (int i=1; i<=n2; i++) {
        cin >> s;
        for (int j=1; j<=m2; j++) {
            v2[i][j] = s[j-1] - '0';
        }
    }

    int ans = 1e9;
    for (int k=0; k<4; k++) {
        for (int i=200-n2; i<=200+n1+1; i++) {
            for (int j=200-m2; j<=200+m1+1; j++) {
                if (ok(i, j)) ans = min(ans, (max(i + n2 - 1, 200 + n1) - min(i, 201) + 1) * (max(j + m2 - 1, 200 + m1) - min(j, 201) + 1));
            }
        }
        rotate();
    }
    cout << ans << '\n';
}