#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int a[100010]{ 0 };
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    int smx[100010]{ 0 };
    smx[1] = a[1];
    int result = smx[1];
    for(int i = 2; i <= n; i++) {
        smx[i] = max(smx[i - 1] + a[i], a[i]);
        result = max(result, smx[i]);
    }
    cout << result;
}