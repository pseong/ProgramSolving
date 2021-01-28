#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mx = max(mx, a);
        sum += a;
    }

    cout << (double)sum/mx*100/ n;
}