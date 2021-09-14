#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    pair<int, int> an[100010];
    for(int i=0; i<n; i++) {
        int d, e;
        cin >> d >> e;
        an[i] = {e, d};
    }

    sort(an, an+n);

    int a[100010]{0};
    int b[100010]{0};
    for(int i=0; i<n; i++) {
        a[i] = an[i].second;
        b[i] = an[i].first;
    }

    int ans=0;
    int now=0;
    for(int i=0; i<n; i++) {
        if(a[i]>=now) {
            ans++;
            now = b[i];
        }
    }
    cout << ans;
}