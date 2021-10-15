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
    vector<int> v;
    for(int i=1; i<=n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    reverse(v.begin(), v.end());

    deque<int> dq;
    for(int i=0; i<n; i++) {
        int x=v[i];
        if(x==1) {
            dq.push_back(i+1);
        }
        else if(x==2) {
            int temp=dq.back();
            dq.pop_back();
            dq.push_back(i+1);
            dq.push_back(temp);
        }
        else {
            dq.push_front(i+1);
        }
    }
    while(!dq.empty()) {
        cout << dq.back() << ' ';
        dq.pop_back();
    }
}