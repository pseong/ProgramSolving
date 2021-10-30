#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

int n, an[110];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        int prev=0;
        int ans=0;
        for(int i=0; i<n; i++) {
            int a;
            cin >> a;
            if(a>prev) {
                ans += a-prev-1;
                prev = a;
            }
            else {
                prev++;
            }
        }
        cout << ans << '\n';
    }
}