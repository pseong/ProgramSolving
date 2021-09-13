#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    int an[100]{0};
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                int sum=an[i]+an[j]+an[k];
                if(sum>ans&&sum<=m) ans = sum;
            }
        }
    }
    cout << ans;
}