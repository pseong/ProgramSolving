#include <iostream>
#include <vector>

using namespace std;

bool prime[300000]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    while(true) {
        int n;
        cin >> n;
        if(n==0) break;

        prime[0] = 1;
        prime[1] = 1;
        for(int i=4; i<=300000; i+=2) {
            prime[i] = 1;
        }
        for(int i=3; i*i<=300000; i+=2) {
            if(!prime[i]) {
                for(int j=i*2; j<=300000; j+=i) {
                    prime[j] = 1;
                }
            }
        }
        int ans=0;
        for(int i=n+1; i<=n*2; i++) {
            if(!prime[i]) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}