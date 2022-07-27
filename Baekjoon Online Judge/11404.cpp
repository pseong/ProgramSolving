#include <iostream>

using namespace std;

long long an[101][101]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            an[i][j] = 1000000000;
            if(i==j) an[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(an[a][b]>c) an[a][b] = c;
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(an[i][j] > an[i][k]+an[k][j])
                    an[i][j] = an[i][k]+an[k][j];
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(an[i][j] == 1000000000)
                an[i][j] = 0;
            cout << an[i][j] << ' ';
        }
        cout << '\n';
    }
}