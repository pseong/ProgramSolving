#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int s[30][30]{0};
vector<int> one;
vector<int> two;
int ans=100000;

void func(int index) {
    if(index == n+1) {
        int a=0;
        int b=0;
        for(int i=0; i<n/2; i++) {
            for(int j=i+1; j<n/2; j++) {
                a += s[one[i]][one[j]];
                a += s[one[j]][one[i]];
                b += s[two[i]][two[j]];
                b += s[two[j]][two[i]];
            }
        }
        ans = min(ans, abs(a-b));
        return;
    }
    if(one.size() < n/2) {
        one.push_back(index);
        func(index+1);
        one.pop_back();
    }
    if(two.size() < n/2) {
        two.push_back(index);
        func(index+1);
        two.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> s[i][j];
        }
    }
    func(1);
    cout << ans;
}