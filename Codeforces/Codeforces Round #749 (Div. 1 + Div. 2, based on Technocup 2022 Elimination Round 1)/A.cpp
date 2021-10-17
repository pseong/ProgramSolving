#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

bool prime[30000];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(int i=4; i<=25000; i+=2) {
        prime[i] = 1;
    }
    for(int i=3; i<=25000; i+=2) {
        if(prime[i]==0) {
            for(int j=i+i; j<=25000; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int an[110]{0};
        int sum=0;
        int hol=0;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
            sum += an[i];
            if(an[i]%2==1) hol=i;
        }
        if(prime[sum]==1) {
            cout << n << '\n';
            for(int i=1; i<=n; i++) {
                cout << i << ' ';
            }
        }
        else {
            cout << n-1 << '\n';
            for(int i=1; i<=n; i++) {
                if(i==hol) continue;
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}