#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool prime[10000]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    prime[0] = 1;
    prime[1] = 1;
    for(long long i=4; i<=10000; i+=2) {
        prime[i] = 1;
    }
    for(long long i=3; i*i<=10000; i+=2) {
        if(!prime[i]) {
            for(long long j=i*2; j<=10000; j+=i) {
                prime[j] = 1;
            }
        }
    }
    vector<long long> pri;
    for(long long i=1; i<=10000; i++) {
        if(!prime[i]) {
            pri.push_back(i);
        }
    }
    sort(pri.begin(), pri.end());
    long long t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long a;
        long long b;
        long long i=0;
        long long j=pri.size()-1;
        while(j>=i) {
            long long sum=pri[i]+pri[j];
            if(sum==n) {
                a = i;
                b = j;
                i++;
                j--;
            } else if (sum>n) {
                j--;
            } else {
                i++;
            }
        }
        cout << pri[a] << ' ' << pri[b] << '\n';
    }
}