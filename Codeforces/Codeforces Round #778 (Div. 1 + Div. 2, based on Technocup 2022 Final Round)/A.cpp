#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int an[1010]{ 0 };
        for (int i=0; i<n; i++) {
            cin >> an[i];
        }
        sort(an, an+n);
        cout << an[n-1] + an[n-2] << '\n';
    }
}