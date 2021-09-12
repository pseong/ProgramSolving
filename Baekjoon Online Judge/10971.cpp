#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int a[11][11]{0};

    cin >> n;
    for(int i=0; i<n; i++) {
        v.push_back(i+1);
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) a[i][j] = 1000000;
        }
    }

    int ans=10000000;
    do {
        int res=0;
        for(int i=0; i<n-1; i++) {
            res += a[v[i]][v[i+1]];
        }
        res += a[v[n-1]][v[0]];
        if(res < ans) ans = res;
    } while(next_permutation(v.begin(), v.end()));

    cout << ans;
}