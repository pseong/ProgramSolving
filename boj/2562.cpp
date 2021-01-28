#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int mx = 0;
    int rate = 0;
    for(int i = 1; i <= 9; i++) {
        int a;
        cin >> a;
        if(mx < a) {
            mx = a;
            rate = i;
        }
    }
    cout << mx << '\n' << rate;
}