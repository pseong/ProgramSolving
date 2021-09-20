#include <iostream>
#include <array>

using namespace std;

long long b;

array<array<long long, 3>, 3> pow(array<array<long long, 3>, 3>& arr, long long b) {
    if(b==1) return arr;
    if(b%2==1) {
        array<array<long long, 3>, 3> arr2;
        array<array<long long, 3>, 3> arr3;
        arr2 = pow(arr, b-1);
        for(long long i=1; i<=2; i++) {
            for(long long j=1; j<=2; j++) {
                long long res=0;
                for(long long k=1; k<=2; k++) {
                    res += (arr2[i][k]*arr[k][j])%1000000007;
                }
                arr3[i][j] = res%1000000007;
            }
        }
        return arr3;
    }
    else {
        array<array<long long, 3>, 3> arr2;
        array<array<long long, 3>, 3> arr3;
        arr2 = pow(arr, b/2);
        for(long long i=1; i<=2; i++) {
            for(long long j=1; j<=2; j++) {
                long long res=0;
                for(long long k=1; k<=2; k++) {
                    res += (arr2[i][k]*arr2[k][j])%1000000007;
                }
                arr3[i][j] = res%1000000007;
            }
        }
        return arr3;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    cin >> b;

    array<array<long long, 3>, 3> arr;
    arr[1][1] = 1;
    arr[1][2] = 1;
    arr[2][1] = 1;
    arr[2][2] = 0;
    arr = pow(arr, b);
    cout << arr[1][2];
}