#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    string s[n];
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }

    int a[4][4]{0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            a[i][j] = s[i][j] - 48;
        }
    }
    // 0 = -, 1 = |
    int ans=0;
    for(int i=0; i<(1<<n*m); i++) {
        int res=0;
        int conti=0;
        for(int j=0; j<n; j++) {
            int sum=0;
            for(int k=0; k<m; k++) {
                int num =j*m + k;
                if(!(i&(1<<num))) {
                    sum *= 10;
                    sum += a[j][k];
                    conti++;
                } else {
                    res += sum;
                    sum = 0;
                }
            }
            res += sum;
        }
        for(int j=0; j<m; j++) {
            int sum=0;
            for(int k=0; k<n; k++) {
                int num =k*m + j;
                if(i&(1<<num)) {
                    sum *= 10;
                    sum += a[k][j];
                } else {
                    res += sum;
                    sum = 0;
                }
            }
            res += sum;
        }
        ans = max(ans, res);
    }
    cout << ans;
}