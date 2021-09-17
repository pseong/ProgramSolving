#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    int left=1;
    int right=k;
    int ans=0;
    while(left<=right) {
        int mid = (left+right)/2;
        int cnt=0;
        for(int i=1; i<=n; i++) {
            cnt += min(mid/i, n);
        }
        if(cnt<k) {
            left=mid+1;
        }
        else {
            ans = mid;
            right=mid-1;
        }
    }
    cout << ans;
}