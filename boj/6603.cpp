#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_moum[20]{0};
int L, C;
char a[20];
vector<char> ans;

void func(int start, int l, int moum, int jaum) {
    if(l < 1 && moum >= 1 && jaum >= 2) {
        for(char c : ans) {
            cout << c;
        }
        cout << '\n';
        return;
    }
    for(int i=start; i<=C; i++) {
        ans.push_back(a[i]);
        func(i+1, l-1, moum + is_moum[i], jaum + !is_moum[i]);
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> L >> C;
    
    for(int i=1; i<=C; i++) {
        cin >> a[i];
    }
    sort(a+1, a+C+1);
    for(int i=1; i<=C; i++) {
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') {
            is_moum[i] = 1;
        }
    }
    func(1, L, false, 0);
}