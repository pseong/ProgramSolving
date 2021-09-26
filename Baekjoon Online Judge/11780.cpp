#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int an[101][101]{0};
int trace[101][101]{0};

vector<int> out(int i, int j) {
    int k=trace[i][j];
    if(k==0) {
        vector<int> a{i, j};
        return a;
    }
    vector<int> a;
    a = out(i, k);
    a.pop_back();
    vector<int> b;
    b = out(k, j);
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            an[i][j] = 1000000000;
            if(i==j) {
                an[i][j] = 0;
            }
        }
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(an[a][b]>c) {
            an[a][b] = c;
        }
    }


    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i==j) an[i][j] = 0;
                if(an[i][j]>an[i][k]+an[k][j]) {
                    an[i][j] = an[i][k]+an[k][j];
                    trace[i][j] = k;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(an[i][j] == 1000000000) cout << 0 << '\n';
            else cout << an[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j || an[i][j]==1000000000) {
                cout << 0 << '\n';
                continue;
            }
            vector<int> o=out(i, j);
            cout << o.size() << ' ';
            for(int i=0; i<o.size(); i++) {
                cout << o[i] << ' ';
            }
            cout << '\n';
        }
    }
}