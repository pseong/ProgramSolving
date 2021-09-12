#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;

bool next_permutation() {
    int idx_start = n-1;
    while(idx_start>0 && v[idx_start-1] > v[idx_start]) idx_start--;
    if(idx_start==0) return false;
    for(int i=n-1; i>=idx_start; i--) {
        if(v[idx_start-1] < v[i]) {
            swap(v[idx_start-1], v[i]);
            reverse(v.begin()+idx_start, v.end());
            return true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        v.push_back(i+1);
    }
    do {
        for(int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    } while(next_permutation());
}