#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    string s;
    cin >> s;

    int arr[200]{ 0 };
    for(int i = 97; i <= 122; i++)
        arr[i] = -1;
    for(int i = 0; i < s.size(); i++)
        if(arr[s[i]] == -1) arr[s[i]] = i;
    
    for(int i = 97; i <= 122; i++)
        cout << arr[i] << ' ';
}