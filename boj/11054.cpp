#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int a[1010]{ 0 };
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    int rmx[1010]{ 0 };
    int mx[1010]{ 0 };
    rmx[n] = 1;
    mx[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= i - 1; j++)
            if(a[i] > a[j]) mx[i] = max(mx[i], mx[j] + 1);
        if(!mx[i]) mx[i] = 1;
    }

    for(int i = n - 1; i >= 1; i--) {
        for(int j = n; j >= i + 1; j--)
            if(a[i] > a[j]) rmx[i] = max(rmx[i], rmx[j] + 1);
        if(!rmx[i]) rmx[i] = 1;
    }

    int result = 1;
    int bito[1010]{ 0 };
    for(int i = 1; i <= n; i++) {
        bito[i] = mx[i] + rmx[i] - 1;
        result = max(result, bito[i]);
    }

    cout << result;
}