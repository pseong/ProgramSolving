#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

vector<int> m[101010];
int mxl[101010];
int mxr[101010];
int mxl2[101010];
int mxr2[101010];

int overlap(int a, int b, int x, int y) {
    if (b < x || y < a) return 0;
    return min(b, y) - max(a, x) + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y;
    cin >> y >> x;
    for (int i=1; i<=x; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 0) {
            m[i].push_back(0);
            m[i].push_back(0);
        }
        else {
            m[i].push_back(y-b+1);
            m[i].push_back(y-a+1);
        }
    }
    m[0].push_back(0);
    m[0].push_back(0);
    m[x+1].push_back(0);
    m[x+1].push_back(0);

    for (int i=1; i<=x; i++) {
        mxl[i] = mxl[i-1];
        if (m[i][0] <= 1) {
            mxl[i] = max(mxl[i], m[i][1]);
            mxl2[i] = 0;
        }
        else if (m[i][0] != 0) {
            mxl2[i] = max(mxl2[i-1], m[i][1]);
            if (m[i-1][0] > m[i][1] || m[i-1][1] < m[i][0]) mxl2[i] = m[i][1];
        }
    }

    for (int i=x; i>=1; i--) {
        mxr[i] = mxr[i+1];
        if (m[i][0] <= 1) {
            mxr[i] = max(mxr[i], m[i][1]);
            mxr2[i] = 0;
        }
        else {
            mxr2[i] = max(mxr2[i+1], m[i][1]);
            if (m[i+1][0] > m[i][1] || m[i+1][1] < m[i][0]) mxr2[i] = m[i][1];
        }
    }

    ll ans = 0;
    for (int i=1; i<=x; i++) {
        int on = min(mxl[i], mxr[i]);
        if (m[i][0] == 1) on -= m[i][1];
        ans += on;

        if (m[i][0] > 1) {
            int a = min(on, 1);
            int b = on;
            ans -= overlap(a, b, m[i][0], m[i][1]);

            int on2 = min(mxl2[i], mxr2[i]) - m[i][1];
            if (on2 > 0) {
                ans += on2;
                int a2 = m[i][1] + 1;
                int b2 = m[i][1] + on2;
                ans -= overlap(a, b, a2, b2);
            }
        }
    }
    cout << ans;
}