#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool func(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    sort(str.begin(), str.end(), func);
    cout << str;
}