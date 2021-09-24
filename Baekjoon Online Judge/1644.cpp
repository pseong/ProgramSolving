#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

bool prime[4000100]{0};
vector<int> primes;
int sum[10000000]{0};
int idx=1;
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    memset(prime,1,sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    prime[2] = 0;
    sum[1] = 2;
    primes.push_back(-1);
    primes.push_back(2);
    for(int i=3; i<=4000000; i+=2) {
        if(prime[i]) {
            primes.push_back(i);
            for(int j=i+i; j<=4000000; j+=i) {
                prime[j] = 0;
            }
            idx++;
            sum[idx] = sum[idx-1]+primes[idx];
        }
    }
    int n;
    cin >> n;
    int left=0;
    int right=1;
    int ans=0;
    while(right<=primes.size()) {
        int cal=sum[right]-sum[left];
        if(cal<n) {
            right++;
        } else if(cal>n) {
            left++;
        } else {
            ans++;
            left++;
            right++;
        }
    }
    cout << ans;
}