#include <bits/stdc++.h>

using namespace std;

char a[51][51]{0};
int n = 0;
int ans = 0;
void scan() {
    for(int i=1; i<=n; i++) {
        int res = 1;
        for(int j=1; j<=n; j++) {
            if(a[i][j] == a[i][j-1]) res++;
            else res = 1;
            if(res > ans) ans = res;
        }
        res = 1;
        for(int j=1; j<=n; j++) {
            if(a[j][i] == a[j-1][i]) res++;
            else res = 1;
            if(res > ans) ans = res;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i != n) {
                swap(a[i][j], a[i+1][j]);
                scan();
                swap(a[i][j], a[i+1][j]);
            }
            if(j != n) {
                swap(a[i][j], a[i][j+1]);
                scan();
                swap(a[i][j], a[i][j+1]);
            }
        }
    }

    cout << ans;
}