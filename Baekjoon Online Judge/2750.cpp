#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int n;
    cin >> n;
    while(n--) {
        int i;
        cin >> i;
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    for(int i : v) {
        cout << i << '\n';
    }
}