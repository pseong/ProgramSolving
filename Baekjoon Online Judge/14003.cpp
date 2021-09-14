#include <iostream>
#include <algorithm>

using namespace std;

long long an[1000011]{0};
long long store[1000011]{0};
long long temp[1000011]{0};

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
            temp[i] = a;
        } else {
            store[idx] = an[i];
            temp[i] = idx;
            idx++;
        }
    }
    cout << idx << '\n';
    int cur=idx-1;
    for(int i=n-1; i>=0; i--) {
        if(temp[i]==cur) {
            store[cur] = an[i];
            cur--;
        }
    }
    for(int i=0; i<idx; i++) {
        cout << store[i] << ' ';
    }
}