#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int cont[101][101]{ 0 };
int m[101][101]{ 0 };
int n{ 0 };

int ii[]{-1, 1, 0, 0};
int jj[]{0, 0, -1, 1};

int valid(int i, int j) {
    if(i > n || j > n || i < 1 || j < 1) return false;
    else return true;
}

void dfs(int i, int j, int id) {
    cont[i][j] = id;
    for(int q = 0; q < 4; q++)
        if(cont[i + ii[q]][j + jj[q]] == 1) dfs(i + ii[q], j + jj[q], id);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    queue<tuple<int, int, int>> que;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> m[i][j];
            cont[i][j] = m[i][j];
            if(m[i][j] == 1) que.push({i, j, 1});
        }
    }

    int id = 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cont[i][j] == 1) {
                dfs(i, j, id);
                id++;
            }
        }
    }

    int result = 1000000000;
    while(!que.empty()) {
        auto a = que.front(); que.pop();
        int i = get<0>(a); int j = get<1>(a); int k =  get<2>(a);
        for(int q = 0; q < 4; q++) {
            if(valid(i + ii[q], j + jj[q])) {
                if(m[i + ii[q]][j + jj[q]] == 0) {
                    m[i + ii[q]][j +jj[q]] = k + 1;
                    cont[i + ii[q]][j + jj[q]] = cont[i][j];
                    que.push({i + ii[q], j + jj[q], k + 1});
                } else {
                    if(cont[i + ii[q]][j + jj[q]] != cont[i][j])
                        result = min(result, m[i + ii[q]][j + jj[q]] + m[i][j] - 2);
                }
            }
        }
    }
    cout << result;
}