#include <iostream>
#include <array>

using namespace std;

long long n, b;

array<array<long long, 6>, 6> pow(array<array<long long, 6>, 6>& arr, long long b) {
    if(b==1) return arr;
    if(b%2==1) {
        array<array<long long, 6>, 6> arr2;
        array<array<long long, 6>, 6> arr3;
        arr2 = pow(arr, b-1);
        for(long long i=1; i<=n; i++) {
            for(long long j=1; j<=n; j++) {
                long long res=0;
                for(long long k=1; k<=n; k++) {
                    res += (arr2[i][k]*arr[k][j])%1000;
                }
                arr3[i][j] = res%1000;
            }
        }
        return arr3;
    }
    else {
        array<array<long long, 6>, 6> arr2;
        array<array<long long, 6>, 6> arr3;
        arr2 = pow(arr, b/2);
        for(long long i=1; i<=n; i++) {
            for(long long j=1; j<=n; j++) {
                long long res=0;
                for(long long k=1; k<=n; k++) {
                    res += (arr2[i][k]*arr2[k][j])%1000;
                }
                arr3[i][j] = res%1000;
            }
        }
        return arr3;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> n >> b;
    array<array<long long, 6>, 6> arr;
    for(long long i=1; i<=n; i++) {
        for(long long j=1; j<=n; j++) {
            cin >> arr[i][j];
            arr[i][j] %= 1000;
        }
    }
    arr = pow(arr, b);
    for(long long i=1; i<=n; i++) {
        for(long long j=1; j<=n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}