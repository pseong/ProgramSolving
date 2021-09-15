#include <iostream>
#include <algorithm>

using namespace std;

long long an[100010]{0};
long long road[100010]{0};

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    for(long long i=0; i<n-1; i++) {
        cin >> road[i];
    }
    for(long long i=0; i<n; i++) {
        cin >> an[i];
    }

    long long fuel=0;
    long long now=0;
    long long price=an[now];
    long long ans=0;
    while(now<n-1) {
        long long length=0;
        while(now<n-1) {
            now++;
            length += road[now-1];
            if(an[now]<price) break;
        }
        ans += price*length;
        price = an[now];
    }
    cout << ans;
}