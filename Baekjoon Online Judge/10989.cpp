#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    
    int arr[10010]{ 0 };
    
    int n;
    cin >> n;
    while(n--) {
        int i;
        cin >> i;
        ++arr[i];
    }

    for(int i = 1; i <= 10000; i++) {
        for(int j = 1; j <= arr[i]; j++)
            cout << i << '\n';
    }
}