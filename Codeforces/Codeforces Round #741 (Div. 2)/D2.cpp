#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

string s;
const int N=300000;
int n, q, an[N+10], sum[N+10], l, r;

int f(int i) {
    int cal=sum[i-1]-sum[l-1]-(sum[r]-sum[i]);
    if(cal==0) return 0;
    else if(cal>0) return 1;
    else return -1;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> q >> s;
        for(int i=0; i<n; i++) {
            if(s[i]=='+') {
                an[i+1] = 1;
            }
            else {
                an[i+1] = -1;
            }
            sum[i+1] = sum[i] + ((i&1) ? -an[i+1] : an[i+1]);
        }
        for(int i=0; i<q; i++) {
            cin >> l >> r;
            if(sum[r]-sum[l-1]==0) {
                cout << 0 << '\n';
            }
            else {
                if((l-r+1)&1) {
                    cout << 1 << '\n';
                }
                else {
                    l++;
                    cout << 2 << '\n';
                    cout << l-1 << ' ';
                }
            }
            int s=l;
            int e=r;
            while(s<=e) {
                int m=(s+e)/2;
                if(f(m)==0) {
                    cout << m << '\n';
                    break;
                }
                else if(f(m)!=f(s)) {
                    e = m-1;
                }
                else {
                    s = m+1;
                }
            }
        }
    }
}