#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int start = 666;
    int cnt = 0;
    while(1) {
        int ff = start;
        while(ff > 100) {
            if(ff % 1000 == 666) {
                cnt++;
                break;
            }
            else ff /= 10;
        }
        if(cnt == n) break;
        start++;
    }
    cout << start;
}