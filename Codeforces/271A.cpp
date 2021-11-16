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

    int n;
    cin >> n;
    while(true) {
        n++;
        int a[11]{0};
        int n2=n;
        bool fail=false;
        while(n2!=0) {
            if(a[n2%10]==1) {
                fail = true;
                break;
            }
            a[n2%10] = 1;
            n2 /= 10;
        }
        if(!fail) {
            break;
        }
    }
    cout << n;
}