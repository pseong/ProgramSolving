#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int ans = 0;
    int cnt = 1;
    int n;
    cin >> n;
    int i = 10;
    while(1) {
        if(n-(i-1) >= 0) {
            ans += cnt * (i*0.9);
        }
        else {
            i *= 0.1;
            i--;
            int temp = n - i;
            ans += cnt * temp;
            break;
        }
        i *= 10;
        cnt++;
    }
    cout << ans;
}