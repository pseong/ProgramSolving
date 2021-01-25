#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        int d = s[i] - '0';
        vector<int> vi;
        while(1) {
            int r = d % 2;
            d = d / 2;
            vi.push_back(r);
            if(d == 0) break;
        }
        if(i > 0)
            for(int i = vi.size(); i < 3; i++)
                vi.push_back(0);
        for(auto it = vi.rbegin(); it != vi.rend(); it++)
            cout << *it;
    }
}