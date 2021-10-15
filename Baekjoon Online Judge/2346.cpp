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
    deque<pii> dq;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        dq.push_back({a, i+1});
    }
    while(!dq.empty()) {
        int a=dq.front().F;
        int i=dq.front().S;
        cout << i << ' ';
        dq.pop_front();
        if(a>0) {
            for(int i=0; i<a-1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int i=0; i<abs(a); i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
}