#include <bits/stdc++.h>

using namespace std;

int n, m;

bool valid(int i, int j) {
    if(i < 1 || j < 1 || i > n || j > m) return false;
    else return true;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int box[110][110] {0};
    cin >> n >> m;

    string s;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        
        for(int j = 1; j <= m; j++) {
            box[i][j] = s[j - 1] - '0';
        }
    }

    int h[] {-1, 1, 0, 0};
    int w[] {0, 0, -1, 1};

    queue<tuple<int, int, int>> que;
    int result = 1;

    box[1][1] = 2; 
    que.push({1, 1, 2});
    while(!que.empty()) {
        auto a = que.front(); que.pop();
        int i = get<0>(a); int j = get<1>(a); int k = get<2>(a);
        if(i == n && j == m) {
            result = k;
            break;
        }
        for(int p = 0; p < 4; p++) {
            if(box[i + h[p]][j + w[p]] == 1 && valid(i + h[p], j + w[p])) {
                box[i + h[p]][j + w[p]] = k + 1;
                que.push({i + h[p], j + w[p], k + 1});
            }
        }
    }
    cout << result - 1;
}