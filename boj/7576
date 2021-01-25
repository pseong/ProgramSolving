#include <bits/stdc++.h>

using namespace std;

int m, n;

bool valid(int i, int j) {
    if(i < 1 || j < 1 || i > n || j > m) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int box[1010][1010]{ 0 };
    cin >> m >> n;

    queue<tuple<int, int, int>> que;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) que.push({i, j, 1});
        }
    }
     
    int h[] {-1, 1, 0, 0};
    int w[] {0, 0, -1, 1};
    while(!que.empty()) {
        auto a = que.front(); que.pop();
        int i = get<0>(a); int j = get<1>(a); int k = get<2>(a);

        for(int p = 0; p < 4; p++) {
            if(box[i + h[p]][j + w[p]] == 0 && valid(i + h[p], j + w[p])) {
                box[i + h[p]][j + w[p]] = k + 1;
                que.push({i + h[p], j + w[p], k + 1});
            }
        }
    }

    int mx = 0;
    bool result = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mx = max(mx, box[i][j]);
            if(box[i][j] == 0) result = 0;
        }
    }
    if(result) cout << mx - 1;
    else cout << -1;
}