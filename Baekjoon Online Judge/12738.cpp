#include <iostream>
#include <algorithm>

using namespace std;

int an[1000001]{0};
int store[1000001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }

    int idx=0;
    for(int i=0; i<n; i++) {
        if(idx>0&&store[idx-1]>=an[i]) {
            int a = lower_bound(store, store+idx, an[i])-store;
            store[a] = an[i];
        } else {
            store[idx] = an[i];
            idx++;
        }
    }
    cout << idx;
}