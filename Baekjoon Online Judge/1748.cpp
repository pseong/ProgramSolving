#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int ans = 0;
    int cnt = 1;
    int n;
    cin >> n;
    for(int start=1; start<=n; start*=10) {
        int end = start*10-1;
        if(end > n) {
            end = n;
        }
        ans += (end-start+1)*cnt;
        cnt++;
    }
    cout << ans;
    
}