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

int ans, v[10][10], num[6]{5, 5, 5, 5, 5, 5};

void cal(int cnt) {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (v[i][j]) return;
        }
    }
    ans = min(ans, cnt);
}

bool valid(int x, int y, int c) {
    for (int i=x; i<x+c; i++) {
        for (int j=y; j<y+c; j++) {
            if (i < 0 || i >= 10 || j < 0 || j >= 10) return false;
            if (v[i][j] == 0) return false;
        }
    }
    return true;
}

void open(int x, int y, int c) {
    for (int i=x; i<x+c; i++) {
        for (int j=y; j<y+c; j++) {
            v[i][j] = 0;
        }
    }
}

void close(int x, int y, int c) {
    for (int i=x; i<x+c; i++) {
        for (int j=y; j<y+c; j++) {
            v[i][j] = 1;
        }
    }
}

void go(int x, int y, int cnt) {
    if (y >= 10) {
        y %= 10;
        x++;
        if (x == 10) {
            cal(cnt);
            return;
        }
    }
    if (v[x][y] == 0) go(x, y+1, cnt);
    else {
        for (int c=1; c<=5; c++) {
            if (num[c] == 0) continue;
            if (!valid(x, y, c)) continue;
            num[c]--;
            open(x, y, c);
            go(x, y+c, cnt + 1);
            num[c]++;
            close(x, y, c);
        }
    }
}

signed main() {
    
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            cin >> v[i][j];
        }
    }
    ans = 1e9;
    go(0, 0, 0);
    if (ans == 1e9) cout << -1 << '\n';
    else cout << ans << '\n';
}