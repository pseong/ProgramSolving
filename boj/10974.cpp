#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        v.push_back(i+1);
    }
    do {
        for(int i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    } while(next_permutation(v.begin(), v.end()));
}