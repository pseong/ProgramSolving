#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    while(1) {
        string s;
        getline(cin, s);

        int result[4]{ 0 };
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 97 && s[i] <= 122)  result[0]++;
            else if(s[i] >= 65 && s[i] <= 90) result[1]++;
            else if(s[i] >= 48 && s[i] <= 57) result[2]++;
            else if(s[i] == 32) result[3]++;
        }
        if(result[0] + result[1] + result[2] + result[3] == 0) break;
        cout << result[0] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3] << '\n';
    }
}