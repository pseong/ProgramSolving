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

vector<vector<int>> v(6, vector<int>(3));
vector<vector<int>> now(6, vector<int>(3));
int ans;

bool valid() {
    for (int i=0; i<6; i++) {
        for (int j=0; j<3; j++) {
            if (now[i][j] > v[i][j]) return false;
        }
    }
    return true;
}

void go(int i, int j) {
    if (j == 6) {
        i++;
        j = i + 1;
    }
    if (i == 5) {
        if (v == now) ans = 1;
        return;
    }
    now[i][0]++;
    now[j][2]++;
    if (valid) go(i, j + 1);
    now[i][0]--;
    now[j][2]--;

    now[i][2]++;
    now[j][0]++;
    if (valid) go(i, j + 1);
    now[i][2]--;
    now[j][0]--;

    now[i][1]++;
    now[j][1]++;
    if (valid) go(i, j + 1);
    now[i][1]--;
    now[j][1]--;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int t=0; t<4; t++) {
        for (int i=0; i<6; i++) {
            for (int j=0; j<3; j++) {
                cin >> v[i][j];
            }
        }
        ans = 0;
        now.assign(6, vector<int>(3, 0));
        go(0, 1);
        cout << ans << ' ';
    }
}