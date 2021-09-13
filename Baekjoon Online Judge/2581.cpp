#include <iostream>
#include <vector>

using namespace std;

bool prime[10001]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;

    prime[0] = 1;
    prime[1] = 1;
    for(int i=4; i<=10000; i+=2) {
        prime[i] = 1;
    }
    for(int i=3; i*i<=10000; i+=2) {
        if(!prime[i]) {
            for(int j=i*2; j<=10000; j+=i) {
                prime[j] = 1;
            }
        }
    }
    int mi=10000;
    int sum=0;
    for(int i=m; i<=n; i++) {
        if(!prime[i]) {
            sum += i;
            mi = min(mi, i);
        }
    }
    if(sum==0) {
        cout << -1;
    } else {
        cout << sum << '\n' << mi;
    }
}