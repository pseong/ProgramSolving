#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        x--;
        y--;
        bool find = false;
        for (int k=x; k<N*M; k+=M) {
            if(k%N==y) {
                find = true;
                cout << k+1 << '\n';
                break;
            }
        }
        if(!find) {
            cout << -1 << '\n';
        }
    }

}