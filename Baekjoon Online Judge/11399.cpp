#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int an[1005]{0};
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    sort(an, an+n);
    int sum[1005]{0};
    int s=0;
    int ans=0;
    for(int i=0; i<n; i++) {
        s += an[i];
        sum[i] = s;
        ans += sum[i];
    }
    cout << ans;
}