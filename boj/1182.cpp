#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, s;
    cin >> n >> s;
    
    int a[30]{0};
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    int ans=0;
    for(int i=1; i<(1<<n); i++) {
        int sum=0;
        for(int j=0; j<n; j++) {
            if(i&(1<<j)) sum += a[j];
        }
        if (sum == s) ans++;
    }

    cout << ans;
}