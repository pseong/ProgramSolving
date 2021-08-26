#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    while(true) {
        int n;
        cin >> n;
        if(n==0) break;
        
        vector<int> v;
        for(int i=0; i<n; i++) {
            if(i>=0 && i<=5) {
                v.push_back(0);
            } else {
                v.push_back(1);
            }
        }

        int a[50]{0};
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        do {
            for(int i=0; i<n; i++) {
                if(!v[i]) cout << a[i] << ' ';
            }
            cout << '\n';
        } while(next_permutation(v.begin(), v.end()));
        cout << '\n';
    }
}