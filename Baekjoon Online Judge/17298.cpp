#include <bits/stdc++.h>
using namespace std;

int arr[1000000]{ 0 };
int ans[1000000]{ 0 };

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int>v;
    v.push_back(0);
    for(int i = 1; i < n; i++) {
        while(!v.empty() && arr[v.back()] < arr[i]) {
            ans[v.back()] = arr[i];
            v.pop_back();
        }
        v.push_back(i);
    }

    for(int i : v) {
        ans[i] = -1;
    }

    for(int i =0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}