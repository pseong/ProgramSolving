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
    
    int result = 1;
    int mn[1010]{ 0 };
    mn[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++)
            if(a[i] < a[j]) mn[i] = max(mn[i], mn[j] + 1);
        if(!mn[i]) mn[i] = 1;
        result = max(result, mn[i]);
    }
    cout << result;
}