#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int ans=0;
    int se=n;
    do {
        int a=se-se/10*10;
        int b=se/10;
        int one=(a+b)-(a+b)/10*10;
        se = a*10+one;
        ans++;
    } while(se!=n);
    cout << ans;
}