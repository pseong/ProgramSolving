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
        int s, n;
        cin >> s >> n;
        vector<int> v;
        for(int i=s; i>0; i/=10) {
            v.push_back(i%10);
        }
        while(accumulate(v.begin(), v.end(), 0)<n) {
            for(int i=1; i<v.size(); i++) {
                if(v[i]>0) {
                    v[i]--;
                    v[i-1] += 10;
                    break;
                }
            }
        }
        int sum=accumulate(v.begin(), v.end(), 0);
        int cnt=sum-n+1;
        int res=0;
        int ten=1;
        bool finish=false;
        for(int i=0; i<v.size(); i++) {
            while(v[i]>0) {
                v[i]--;
                cnt--;
                res += ten;
                if(cnt==0) {
                    finish = true;
                    break;
                }
            }
            if(finish) break;
            ten *= 10;
        }
        ten = 1;
        cout << res << ' ';
        for(int i=0; i<v.size(); i++) {
            if(v[i]>0) {
                for(int j=0; j<v[i]; j++) {
                    cout << ten << ' ';
                }
            }
            ten *= 10;
        }
        cout << '\n';
    }
}