#include <bits/stdc++.h>

using namespace std;

int mp[2200][2200]{ 0 };
int result[3]{ 0 };

bool valid(int i, int j, int i2, int j2) {
    int pre = mp[i][j];
    for(int n = i; n <= i2; n++) {
        for(int m = j; m <= j2; m++) {
            if(pre != mp[n][m]) return false;
        }
    }
    result[++pre]++;
    return true;
}

void partition(int i, int j, int i2, int j2) {
    if(valid(i, j, i2, j2)) return;
    int third = (i2 - i + 1) / 3;
    for(int n = i; n <= i2; n += third) {
        for(int m = j; m <= j2; m += third) {
            partition(n, m, n + third - 1, m + third - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> mp[i][j];
        }
    }
    partition(1, 1, n, n);
    for(int i = 0; i < 3; i++) {
        cout << result[i] << '\n';
    }
}