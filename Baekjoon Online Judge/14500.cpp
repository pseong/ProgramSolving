#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int a[501][501]{ 0 };
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 4; j <= m; j++) {
            int res = a[i][j] + a[i][j-1] + a[i][j-2] + a[i][j-3];
            if(res > ans) ans = res;
        }
    }

    for(int i = 4; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int res = a[i][j] + a[i-1][j] + a[i-2][j] + a[i-3][j];
            if(res > ans) ans = res;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            int res = a[i][j] + a[i][j-1] + a[i-1][j] + a[i-1][j-1];
            if(res > ans) ans = res;
        }
    }

    for(int i = 3; i <= n; i++) {
        for(int j = 2; j <= m; j++) {
            int res = a[i][j] + a[i][j-1] + a[i-1][j-1] + a[i-2][j-1];
            if(res > ans) ans = res;

            res = a[i][j-1] + a[i][j] + a[i-1][j] + a[i-2][j];
            if(res > ans) ans = res;

            res = a[i][j] + a[i-1][j] + a[i-2][j] + a[i-2][j-1];
            if(res > ans) ans = res;

            res = a[i-2][j] + a[i-2][j-1] + a[i-1][j-1] + a[i][j-1];
            if(res > ans) ans = res;

            res = a[i][j] + a[i-1][j] + a[i-1][j-1] + a[i-2][j-1];
            if(res > ans) ans = res;

            res = a[i][j-1] + a[i-1][j-1] + a[i-1][j] + a[i-2][j];
            if(res > ans) ans = res;

            res = a[i][j] + a[i-1][j] + a[i-1][j-1] + a[i-2][j];
            if(res > ans) ans = res;

            res = a[i][j-1] + a[i-1][j] + a[i-1][j-1] + a[i-2][j-1];
            if(res > ans) ans = res;
        }
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 3; j <= m; j++) {
            int res = a[i][j-2] + a[i-1][j-2] + a[i-1][j-1] + a[i-1][j];
            if(res > ans) ans = res;

            res = a[i-1][j-2] + a[i-1][j-1] + a[i-1][j] + a[i][j];
            if(res > ans) ans = res;

            res = a[i][j-2] + a[i][j-1] + a[i][j] + a[i-1][j];
            if(res > ans) ans = res;

            res = a[i-1][j-2] + a[i][j-2] + a[i][j-1] + a[i][j];
            if(res > ans) ans = res;

            res = a[i][j-2] + a[i][j-1] + a[i-1][j-1] + a[i-1][j];
            if(res > ans) ans = res;

            res = a[i-1][j-2] + a[i-1][j-1] + a[i][j-1] + a[i][j];
            if(res > ans) ans = res;

            res = a[i-1][j-1] + a[i][j-2] + a[i][j-1] + a[i][j];
            if(res > ans) ans = res;

            res = a[i-1][j-2] + a[i-1][j-1] + a[i-1][j] + a[i][j-1];
            if(res > ans) ans = res;
        }
    }
    cout << ans;
}