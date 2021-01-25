#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    string s;
    getline(cin, s);

    int sum = 0;
    for(int i = 0; i < s.size(); i++)
        sum += stoi(s.substr(i, 1));
    cout << sum;
}