#include <bits/stdc++.h>

using namespace std;

bool m[51][51]{ 0 };

int h = 0;
int w = 0;

void find(int i , int j ) {
    if(i < 1 || j < 1 || i > h || j > w || m[i][j] == 0) return;
    if(m[i][j] == 1) m[i][j] = 0;
    find(i - 1, j - 1);
    find(i - 1, j);
    find(i - 1, j + 1);
    find(i, j - 1);
    find(i, j + 1);
    find(i + 1, j - 1);
    find(i + 1, j);
    find(i + 1, j + 1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    while(1) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                cin >> m[i][j];

        int result = 0;
        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                if(m[i][j] == 1) {
                    find(i, j);
                    result++;
                }

        cout << result << '\n';

        for(int i = 1; i <= h; i++)
            for(int j = 1; j <= w; j++)
                m[i][j] = 0;
    }
}