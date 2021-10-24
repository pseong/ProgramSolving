#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define F first
#define S second

const int N=100000;
int an[N+10];
int bn[N+10];
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> an[i];
        }
        bool odd=false;
        if(n&1) {
            odd = true;
            for(int i=1; i<n-3; i+=2) {
                if(an[i]*an[i+1]>0) {
                    cout << -abs(an[i+1]) << ' ' << abs(an[i]) << ' ';
                }
                else {
                    cout << abs(an[i+1]) << ' ' << abs(an[i]) << ' ';
                }
            }
        }
        else {
            for(int i=1; i<n; i+=2) {
                if(an[i]*an[i+1]>0) {
                    cout << -abs(an[i+1]) << ' ' << abs(an[i]) << ' ';
                }
                else {
                    cout << abs(an[i+1]) << ' ' << abs(an[i]) << ' ';
                }
            }
        }
        if(odd) {
            if(an[n-2]+an[n-1]!=0) {
                cout << -an[n] << ' ' << -an[n] << ' ' << an[n-2]+an[n-1];
            }
            else if(an[n-2]+an[n]!=0) {
                cout << -an[n-1] << ' ' << an[n-2]+an[n] << ' ' << -an[n-1];
            }
            else if(an[n-1]+an[n]!=0) {
                cout << an[n]+an[n-1] << ' ' << -an[n-2] << ' ' << -an[n-2];
            }
        }
        cout << '\n';
    }
}