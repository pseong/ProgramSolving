#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<pii> q;
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int what;
        cin >> what;
        if (what == 1) {
            int x, c;
            cin >> x >> c;
            q.push({x, c});
        }
        else {
            int c;
            cin >> c;
            ll ans = 0;
            while (c) {
                if (q.front().second <= c) {
                    ans += (ll)q.front().first * q.front().second;
                    c -= q.front().second;
                    q.pop();
                }
                else {
                    ans += (ll)q.front().first * c;
                    q.front().second -= c;
                    c -= c;
                }
            }
            cout << ans << '\n';
        }
    }
}