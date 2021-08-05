#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int a[9]{ 0 };
    int sum = 0;
    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i]; 
    }
    sort(a, a+9);

    for(int i=0; i<=7; i++) {
        for(int j=i+1; j<=8; j++) {
            if(sum-a[i]-a[j] == 100) {
                for(int l=0; l<=8; l++) {
                    if(l!=i && l!=j) {
                        cout << a[l] << '\n';
                    }
                }
                return 0;
            }
        }
    }
}