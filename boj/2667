#include <bits/stdc++.h>

using namespace std;

string s[30];

int n = 0;
int sizee = 0;

void find(int i , int j ) {
    if(i < 0 || j < 0 || i >= n || j >= n || s[i][j] == '0') return;
    if(s[i][j] == '1') {
        s[i][j] = '0';
        sizee++;
    }
    find(i - 1, j);
    find(i, j + 1);
    find(i + 1, j);
    find(i, j - 1);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    vector<int> vec;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '1') {
                find(i, j);
                vec.push_back(sizee);
                sizee = 0;
            }
        }
    }

    sort(vec.begin(), vec.end());
    cout << vec.size() << '\n';
    for(int i : vec)
        cout << i << '\n';
}