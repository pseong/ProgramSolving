#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, s;
    cin >> n >> s;
    int n1=n/2;
    int n2=n-n1;
    int an1[20]{0};
    int an2[20]{0};
    for(int i=0; i<n1; i++) {
        cin >> an1[i];
    }
    for(int i=0; i<n2; i++) {
        cin >> an2[i];
    }

    vector<int> a;
    vector<int> b;
    for(int i=0; i<(1<<n1); i++) {
        int sum=0;
        for(int j=0; j<n1; j++) {
            if(i&(1<<j)) {
                sum += an1[j];
            }
        }
        a.push_back(sum);
    }
    for(int i=0; i<(1<<n2); i++) {
        int sum=0;
        for(int j=0; j<n2; j++) {
            if(i&(1<<j)) {
                sum += an2[j];
            }
        }
        b.push_back(sum);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans=0;
    int i=0;
    int j=b.size()-1;
    while(i<a.size()&&j>=0) {
        int sum=a[i]+b[j];
        if(sum==s) {
            ll cnt1=1;
            ll cnt2=1;
            i++;
            j--;
            while(i<a.size()&&a[i]==a[i-1]) {
                cnt1++;
                i++;
            }
            while(j>=0&&b[j]==b[j+1]) {
                cnt2++;
                j--;
            }
            ans += cnt1*cnt2;
        }
        else if(sum<s) {
            i++;
        }
        else {
            j--;
        }
    }
    cout << ans;
}