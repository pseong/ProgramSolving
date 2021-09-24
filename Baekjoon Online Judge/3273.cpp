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
    int x;
    cin >> x;
    sort(an, an+n);
    int left=0;
    int right=n-1;
    int ans=0;
    while(left<right) {
        if(an[left]+an[right]>x) {
            right--;
        } else if(an[left]+an[right]<x) {
            left++;
        } else {
            ans++;
            left++;
            right--;
        }
    }
    cout << ans;
}