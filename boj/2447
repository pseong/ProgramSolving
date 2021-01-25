#include <bits/stdc++.h>

using namespace std;

int mp[6562][6562]{ 0 };

void fill(int i, int j, int i2, int j2) {
    for(int n = i; n <= i2; n++) {
        for(int m = j; m <= j2; m++) {
            mp[n][m] = 1;
        }
    }
    mp[(i + i2) / 2][(j + j2) / 2] = 0;
}

void partition(int i, int j, int i2, int j2) {
    if(i2 - i + 1 == 3) fill(i, j, i2, j2);
    else {
        int gap = (i2 - i + 1) / 3;
        for(int n = i; n < i2; n += gap) {
            for(int m = j; m < j2; m += gap) {
                if(n == i+gap && m == j+gap) continue;
                partition(n, m, n+gap-1, m+gap-1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    partition(1, 1, n, n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(mp[i][j]) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }
}