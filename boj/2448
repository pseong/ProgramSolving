#include <bits/stdc++.h>

using namespace std;

int mp[3073][6500]{ 0 };

void fill(int i, int j, int i2, int j2) {
    mp[i][j+2] = 1;
    mp[i+1][j+1] = 1;
    mp[i+1][j+3] = 1;
    for(int m = j; m <= j2; m++)
        mp[i+2][m] = 1;
}

void partition(int i, int j, int i2, int j2) {
    if(i2 - i + 1 == 3) fill(i, j, i2, j2);
    else {
        int gapX = (j2-j) / 2;
        int gapY = (i2-i+1) / 2;
        partition(i, j+(gapX+1)/2, i+gapY-1, j+(gapX+1)/2+gapX-1);
        partition(i+gapY, j, i+2*gapY-1, j+gapX-1);
        partition(i+gapY, j+gapX+1, i+2*gapY-1, j+2*gapX);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    partition(1, 1, n, 2*n-1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 2*n-1; j++) {
            if(mp[i][j]) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }
}