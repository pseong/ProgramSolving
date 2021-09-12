#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int c;
    cin >> c;
    int an[1050]{0};
    cout.precision(3);
    cout << fixed;
    while(c--) {
        int t;
        cin >> t;
        int sum=0;
        for(int i=0; i<t; i++) {
            cin >> an[i];
            sum += an[i];
        }
        double avg=(double)sum/t;
        int cnt=0;
        for(int i=0; i<t; i++) {
            if(an[i]>avg) cnt++;
        }
        double ans=(double)cnt/t*100;
        cout << ans << "%" << '\n';
    }
}