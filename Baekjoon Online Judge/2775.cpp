#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int an[15][15]{0};
    for(int i=0; i<=14; i++) {
        an[0][i] = i;
    }
    for(int i=1; i<=14; i++) {
        for(int j=1; j<=14; j++) {
            for(int l=1; l<=j; l++) {
                an[i][j] += an[i-1][l];
            }
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int k, n;
        cin >> k >> n;
        cout << an[k][n] << '\n';
    }
}