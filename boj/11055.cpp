#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;

    int a[1010]{ 0 };
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    int sum[1010]{ 0 };
    sum[1] = a[1];
    int result = sum[1];

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++)
            if(a[i] > a[j]) sum[i] = max(sum[i], sum[j] + a[i]);
        if(!sum[i]) sum[i] = a[i];
        result = max(result, sum[i]);
    }
    cout << result;
}