#include <iostream>

using namespace std;

int d(int n) {
    int sum=n;
    while(n!=0) {
        sum = sum+n%10;
        n /= 10;
    }
    return sum;
}

bool ans[10050]{0};
int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    for(int i=1; i<=10000; i++) {
        ans[d(i)] = true;
    }
    for(int i=1; i<=10000; i++) {
        if(!ans[i]) cout << i << '\n';
    }
}