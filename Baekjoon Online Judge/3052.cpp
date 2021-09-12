#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    bool a[42]{ 0 };
    int n = 10;
    while(n--) {
        int b;
        cin >> b;
        a[b%42] = true;
    }

    int cnt = 0;
    for(int i = 0; i < 42; i++) {
        if(a[i]) cnt++;
    }
    cout << cnt;
}