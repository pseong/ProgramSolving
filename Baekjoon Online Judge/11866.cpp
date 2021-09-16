#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    vector<int> v;
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        v.push_back(i);
    }
    int idx=-1;
    cout << '<';
    while(true) {
        idx += k;
        idx %= v.size();
        cout << v[idx];
        v.erase(v.begin()+idx);
        idx--;
        if(v.empty()) {
            cout << '>';
            break;
        } else {
            cout << ", ";
        }
    }
}