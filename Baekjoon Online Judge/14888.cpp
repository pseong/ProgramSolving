#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[20];
vector<int> oper;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    // 0:+, 1:-, 2:*, 3:/
    for(int i=0; i<4; i++) {
        int a;
        cin >> a;
        while(a--) oper.push_back(i);
    }

    int ans_max=-1000000000;
    int ans_min=1000000000;
    do {
        int res=a[0];
        for(int i=1; i<n; i++) {
            switch (oper[i-1])
            {
            case 0:
                res+=a[i];
                break;
            case 1:
                res-=a[i];
                break;
            case 2:
                res*=a[i];
                break;
            case 3:
                res/=a[i];
                break;
            }
        }
        ans_min = min(ans_min, res);
        ans_max = max(ans_max, res);
    } while(next_permutation(oper.begin(), oper.end()));

    cout << ans_max << '\n' << ans_min;
}