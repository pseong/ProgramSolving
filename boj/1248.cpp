#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
char s[30][30]{0};
int ans[30]{0};
bool ok = false;

void func(int index) {
    if(index == n+1) {
        ok = true;
        return;
    }
    for(int i=-10; i<=10; i++) {
        if(ok) return;

        ans[index] = i;
        int sum=0;
        for(int j=1; j<=index; j++) {
            sum += ans[j];
        }

        bool valid = true;
        for(int j=1; j<=index; j++) {
            if(!(sum > 0 && s[j][index] == '+' || sum < 0 && s[j][index] == '-' || sum == 0 && s[j][index] == '0')) {
                valid = false;
            }
            sum -= ans[j];
        }
        
        if(!valid) {
            continue;
        }
        func(index+1);
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            cin >> s[i][j];
        }
    }
    func(1);
    
    for(int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
}