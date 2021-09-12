#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long mx = 0;
    long long a[10001]{ 0 };
    int k, n;
    cin >> k >> n;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    long long result = 0;
    long long left = 1;
    long long right = mx;
    while(left <= right) {
        long long  mid = (left + right) / 2;
        int made = 0;

        for(int i = 1; i <= k; i++)
            made += a[i] / mid;
        
        if(made < n) right = mid - 1;
        else {
            left = mid + 1;
            result = max(result, mid);
        }
    }
    cout << result;
}