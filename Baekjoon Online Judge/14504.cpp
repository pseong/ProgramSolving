#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int sqrtN, a[101010], b[101010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    sqrtN = sqrt(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i=0; i<(n-1)/sqrtN; i++) {
        sort(b+i*sqrtN, b+(i+1)*sqrtN);
    }
    sort(b+(n-1)/sqrtN*sqrtN, b+n);

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int what;
        cin >> what;
        if (what==1) {
            int i, j, k;
            cin >> i >> j >> k;
            i--; j--;
            if (i/sqrtN == j/sqrtN) {
                int cnt = 0;
                for (int x=i; x<=j; x++) {
                    if (a[x] > k) cnt++;
                }
                cout << cnt << '\n';
            }
            else {
                int cnt = 0;
                while (i%sqrtN != 0) {
                    if (a[i] > k) cnt++;
                    i++;
                }
                while (j%sqrtN != sqrtN-1) {
                    if (a[j] > k) cnt++;
                    j--;
                }
                for (int x=i/sqrtN; x<=j/sqrtN; x++) {
                    cnt += b+(x+1)*sqrtN - upper_bound(b+x*sqrtN, b+(x+1)*sqrtN, k);
                }
                cout << cnt << '\n';
            }
        }
        else {
            int i, k;
            cin >> i >> k;
            i--;
            a[i] = k;
            for (int x=i/sqrtN*sqrtN; x<min((i/sqrtN+1)*sqrtN, n); x++) {
                b[x] = a[x];
            }
            sort(b+i/sqrtN*sqrtN, b+min((i/sqrtN+1)*sqrtN, n));
        }
    }
}