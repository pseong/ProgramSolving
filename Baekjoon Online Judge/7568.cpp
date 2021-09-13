#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    int x[200]{0};
    int y[200]{0};

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }


    for(int i=0; i<n; i++) {
        int ans=0;
        for(int j=0; j<n; j++) {
            if(x[j]>x[i]&&y[j]>y[i]) ans++;
        }
        cout << ans+1 << ' ';
    }
}