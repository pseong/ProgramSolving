#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int an[100000]{0};
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    sort(an, an+n);
    int left=0;
    int right=n-1;
    long long ans[2]{0};
    long long gap=1000000000;
    while(left<right) {
        if(abs(an[left]+an[right])<gap) {
            ans[0] = an[left];
            ans[1] = an[right];
            gap = abs(an[left]+an[right]);
        } 
        long long add_left=abs(an[left+1]+an[right]);
        long long add_right=abs(an[left]+an[right-1]);
        if(add_left<add_right) {
            left++;
        }
        else if(add_left>add_right) {
            right--;
        }
        else left++;
    }
    sort(ans, ans+2);
    cout << ans[0] << ' ' << ans[1];
}