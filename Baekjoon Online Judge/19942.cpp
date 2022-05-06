#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using ti=tuple<int, int, int, int, int>;

int n, mp, mf, ms, mv;
vector<ti> v;
const int inf = 100000000;
int ans = inf;
vector<vector<int>> ansv;

int a,b,c,d,e;
vector<int> now;
void go(int i) {
    if (i == n) {
        if (a>=mp&& b>=mf && c>=ms && d>=mv) {
            if (ans > e) {
                ans = e;
                ansv.clear();
                ansv.push_back(now);
            }
            else if (ans == e) {
                ansv.push_back(now);
            }
        }
        return;
    }
    now.push_back(i);
    a += get<0>(v[i]);
    b += get<1>(v[i]);
    c += get<2>(v[i]);
    d += get<3>(v[i]);
    e += get<4>(v[i]);
    go(i+1);
    now.pop_back();
    a -= get<0>(v[i]);
    b -= get<1>(v[i]);
    c -= get<2>(v[i]);
    d -= get<3>(v[i]);
    e -= get<4>(v[i]);
    go(i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>mp>>mf>>ms>>mv;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c >> d >> e;
        v.push_back({a, b, c, d, e});
    }
    a=b=c=d=e=0;
    go(0);
    if (ans == inf) {
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    sort(ansv.begin(), ansv.end());
    for (int a : ansv[0]) {
        cout << a+1 << ' ';
    }
}