#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int an[100001]{0};
    long long sum[100001]{0};
    int n, s;
    cin >> n >> s;
    for(int i=1; i<=n; i++) {
        cin >> an[i];
        sum[i] = sum[i-1]+an[i];
    }

    int left=0;
    int right=1;
    long long ans=1000000000000;
    while(right<=n) {
        int cal=sum[right]-sum[left];
        if(cal>=s) {
            if(ans>right-left) ans = right-left;
            left++;
        } else {
            right++;
        }
        if(left==right) right++;
    }
    if(ans==1000000000000) cout << 0;
    else cout << ans;
}