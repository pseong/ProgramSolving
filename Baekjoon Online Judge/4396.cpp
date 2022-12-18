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

string s[20], o[20];
vector<string> ans(20, string(20, '.'));

int dx[] {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] {-1, 0, 1, -1, 1, -1, 0, 1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s[i];
    }
    for (int i=0; i<n; i++) {
        cin >> o[i];
    }
    bool boom = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (o[i][j] == 'x') {
                if (s[i][j] == '*') boom = true;
                else {
                    int cnt = 0;
                    for (int d=0; d<8; d++) {
                        int x = i + dx[d];
                        int y = j + dy[d];
                        if (x < 0 || x >= n || y < 0 || y >= n) continue;
                        if (s[x][y] == '*') cnt++;
                    }
                    ans[i][j] = cnt + '0';
                }
            }
        }
    }
    if (boom) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (s[i][j] == '*') ans[i][j] = '*';
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}