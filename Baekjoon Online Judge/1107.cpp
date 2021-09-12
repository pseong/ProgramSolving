#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[10]{0};
    while(m--) {
        int b;
        cin >> b;
        a[b] = 1;
    }
    
    int ans = abs(n - 100);
    for(int i = 0; i < 10; i++) {
        if(a[i] && i != 0) continue;
        for(int j = 0; j < 10; j++) {
            if(a[j]) {
                if(!(j==0 && i==0)) {
                    continue;
                }
            }
            for(int k = 0; k < 10; k++) {
                if(a[k]) {
                    if(!(j==0 && i==0 && k==0)) {
                        continue;
                    }
                }
                for(int l = 0; l < 10; l++) {
                    if(a[l]) {
                        if(!(j==0 && i==0 && k==0 && l==0)) {
                            continue;
                        }
                    }
                    for(int q = 0; q < 10; q++) {
                        if(a[q]) {
                            if(!(j==0 && i==0 && k==0 && l==0 && q==0)) {
                                continue;
                            }
                        }
                        for(int z = 0; z < 10; z++) {
                            if(a[z]) continue;
                            int res = 0;
                            res = res + i * 100000;
                            res = res + j * 10000;
                            res = res + k * 1000;
                            res = res + l * 100;
                            res = res + q * 10;
                            res = res + z;
                            res = abs(n - res);

                            int minus = 6;
                            if(i==0) {
                                minus--;
                                if(j==0) {
                                    minus--;
                                    if(k==0) {
                                        minus--;
                                        if(l==0) {
                                            minus--;
                                            if(q==0) {
                                                minus--;
                                            }
                                        }
                                    }
                                }
                            }

                            if(res + minus < ans) {
                                ans = res + minus;
                                cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << q << ' ' << z << '\n';
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}