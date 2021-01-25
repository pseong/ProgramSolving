#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vi;
    for(int i = 1; i <= n; i++)
        vi.push_back(i);
    
    cout << '<';

    int it = k - 1;
    while(vi.size() != 1) {
        cout << vi[it] << ", ";
        vi.erase(vi.begin() + it);
        it += k - 1;
        if(it >= vi.size()) it %= vi.size();
    }

    cout << vi[it] << '>';
}