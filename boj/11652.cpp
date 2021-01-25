#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    long long arr[100010] { 0 };

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    arr[n + 1] = pow(2, 62) + 100;
    sort(arr + 1, arr + 1 + n);

    long long d = arr[1];
    int many = 1;

    int left = 1;
    int right = 2;

    for(; right <= n + 1; right++) {
        if(arr[right] != arr[right - 1]) {
            int length = right - left;
            if(length > many) {
                many = length;
                d = arr[left];
            } else if (length == many)
                if(d > arr[left]) d = arr[left];
            left = right;
        }
    }
    cout << d;
}