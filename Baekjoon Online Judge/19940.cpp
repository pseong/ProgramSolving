#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int, int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<ti> t(61, {-1, -1, -1, -1, -1});
    queue<int> q;
    q.push(0);
    t[0] = {0, 0, 0, 0, 0};
    while (q.size()) {
        int y = q.front(); q.pop();
        int a, b, c, d, e;
        tie(a, b, c, d, e) = t[y];
        if (y-1 >= 0 && get<0>(t[y-1]) == -1) {
            t[y-1] = {a, b, c, d, e+1};
            q.push(y-1);
        }
        if (y+1 <= 60 && get<0>(t[y+1]) == -1) {
            t[y+1] = {a, b, c, d+1, e};
            q.push(y+1);
        }
        if (y-10 >= 0 && get<0>(t[y-10]) == -1) {
            t[y-10] = {a, b, c+1, d, e};
            q.push(y-10);
        }
        if (y+10 <= 60 && get<0>(t[y+10]) == -1) {
            t[y+10] = {a, b+1, c, d, e};
            q.push(y+10);
        }
        if (y+60 <= 60 && get<0>(t[y+60]) == -1) {
            t[y+60] = {a+1, b, c, d, e};
            q.push(y+60);
        }
    }
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int a, b, c, d, e;
        tie(a, b, c, d, e) = t[n%60];
        a += n/60;
        cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
    }
}