#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int sc[3][100010]{{ 0 }};
    int mxsc[3][100010]{{ 0 }};

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> sc[1][i];
        for(int i = 1; i <= n; i++)
            cin >> sc[2][i];

        mxsc[1][1] = sc[1][1];
        mxsc[2][1] = sc[2][1];
        for(int i = 1; i <= n; i++) {
            mxsc[1][i] = max(mxsc[2][i - 1] + sc[1][i], mxsc[1][i - 1] - sc[1][i - 1] + sc[1][i]);
            mxsc[2][i] = max(mxsc[1][i - 1] + sc[2][i], mxsc[2][i - 1] - sc[2][i - 1] + sc[2][i]);
        }
        
        int result = max(mxsc[1][n], mxsc[2][n]);
        cout << result << '\n';
    }
}