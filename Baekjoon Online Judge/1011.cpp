#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    long long t;
    cin >> t;
    vector<long long> v;
    for(long long i=1; i<=100000; i++) {
        v.push_back((long long)i*(i+1));
    }
    while(t--) {
        long long x, y;
        cin >> x >> y;
        long long a = y - x;
        auto lb=lower_bound(v.begin(), v.end(), a);
        long long val=*lb;
        long long idx = lb - v.begin() + 1; 
        long long ans;
        if(a>val-idx) ans = idx*2;
        else ans = idx*2-1;
        cout << ans << '\n';
    }
}