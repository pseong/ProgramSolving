#include <bits/stdc++.h>

using namespace std;

vector<char> vec[100];

void findad(char i) {
    cout << i;
    if(vec[i][0] != '.') findad(vec[i][0]);
    if(vec[i][1] != '.') findad(vec[i][1]);
}

void findmid(char i) {
    if(vec[i][0] != '.') findmid(vec[i][0]);
    cout << i;
    if(vec[i][1] != '.') findmid(vec[i][1]);
}

void findrear(char i) {
    if(vec[i][0] != '.') findrear(vec[i][0]);
    if(vec[i][1] != '.') findrear(vec[i][1]);
    cout << i;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    while(n--) {
        char a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back(b);
        vec[a].push_back(c);
    }

    findad('A');
    cout << '\n';
    findmid('A');
    cout << '\n';
    findrear('A');
}