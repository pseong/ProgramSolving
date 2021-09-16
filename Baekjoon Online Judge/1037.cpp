#include <iostream>
#include <algorithm>

using namespace std;

int an[60]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> an[i];
    }
    sort(an,an+n);
    cout << an[n-1]*an[0];
}