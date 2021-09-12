#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int a[8]{ 0 };
    for(int i = 0; i < 8; i++) cin >> a[i];
    if(a[0] != 1 && a[0] != 8) {
        cout << "mixed";
        return 0;
    }
    for(int i = 1; i < 8; i++) {
        if(a[i] != a[i-1]+1 && a[i] != a[i-1]-1) {
            cout << "mixed";
            return 0;
        }
    }
    if(a[7] == 8) cout << "ascending";
    else cout << "descending";
}