#include <iostream>

using namespace std;

int a[100][100]{0};
int b[100][100]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int xa, ya;
    cin >> xa >> ya;

    for(int i=1; i<=xa; i++) {
        for(int j=1; j<=ya; j++) {
            cin >> a[i][j];
        }
    }

    int xb, yb;
    cin >> xb >> yb;

    for(int i=1; i<=xb; i++) {
        for(int j=1; j<=yb; j++) {
            cin >> b[i][j];
        }
    }

    for(int i=1; i<=xa; i++) {
        for(int j=1; j<=yb; j++) {
            int res=0;
            for(int k=1; k<=ya; k++) {
                res += a[i][k]*b[k][j];
            }
            cout << res << ' ';
        }
        cout << '\n';
    }
}