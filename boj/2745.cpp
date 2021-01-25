#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    string s;
    int b;
    cin >> s >> b;
    long long result = 0;
    for(int i = 0; i < s.size(); i ++) {
        int d = -1;
        if(s[i] >= '0' && s[i] <= '9') d = s[i] - '0';
        else d = s[i] - 'A' + 10;
        result += pow(b, (s.size() - i - 1)) * d;
    }
    cout << result;
}