#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int ans=0;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    do {
        int res=0;
        for(int i=0; i<n-1; i++) {
            res += abs(v[i]-v[i+1]);
        }
        if(ans < res) ans = res;
    } while(next_permutation(v.begin(), v.end()));
    cout << ans;
}