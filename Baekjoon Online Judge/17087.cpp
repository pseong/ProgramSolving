#include <bits/stdc++.h>

using namespace std;

int arr[100001]{ 0 };

int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr[i] = abs(a - s);
    }

    int ans = gcd(arr[0], arr[1]);
    for(int i = 1; i < n; i++) {
        ans = gcd(ans, arr[i]);
    }

    cout << ans;
}