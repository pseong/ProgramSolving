#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;

int k, h;
vector<char> v;
int ans[300][300];
int re[4] = {1, 0, 3, 2};

void go(int x1, int x2, int y1, int y2, int idx) {
    char g = v[idx];
    if (idx != k*2) {
        if (g == 'U') {
            go(x1, (x1+x2)/2, y1, y2, idx+1);
        }
        else if (g == 'D') {
            go((x1+x2)/2+1, x2, y1, y2, idx+1);
        }
        else if (g == 'L') {
            go(x1, x2, y1, (y1+y2)/2, idx+1);
        }
        else {
            go(x1, x2, (y1+y2)/2+1, y2, idx+1);
        }
    }
    else if (idx == k*2) {
        assert(x1==x2 && y1==y2);
        ans[x1][y1] = h;
        return;
    }
    if (g == 'U') {
        int i1 = (x1+x2)/2;
        int i2 = (x1+x2)/2+1;
        int cnt = i1-x1+1;
        while (cnt--) {
            for (int j=y1; j<=y2; j++) {
                ans[i2][j] = (ans[i1][j]+2)%4;
            }
            i1--;
            i2++;
        }
    }
    else if (g == 'D') {
        int i1 = (x1+x2)/2;
        int i2 = (x1+x2)/2+1;
        int cnt = i1-x1+1;
        while (cnt--) {
            for (int j=y1; j<=y2; j++) {
                ans[i1][j] = (ans[i2][j]+2)%4;
            }
            i1--;
            i2++;
        }
    }
    else if (g == 'L') {
        int j1 = (y1+y2)/2;
        int j2 = (y1+y2)/2+1;
        int cnt = j1-y1+1;
        while (cnt--) {
            for (int i=x1; i<=x2; i++) {
                ans[i][j2] = re[ans[i][j1]];
            }
            j1--;
            j2++;
        }
    }
    else {
        int j1 = (y1+y2)/2;
        int j2 = (y1+y2)/2+1;
        int cnt = j1-y1+1;
        while (cnt--) {
            for (int i=x1; i<=x2; i++) {
                ans[i][j1] = re[ans[i][j2]];
            }
            j1--;
            j2++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> k;
    for (int i=0; i<2*k; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    cin >> h;

    go(0, (1<<k)-1, 0, (1<<k)-1, 0);

    for (int i=0; i<(1<<k); i++) {
        for (int j=0; j<(1<<k); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}