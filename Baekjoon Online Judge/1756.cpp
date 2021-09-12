#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_moum[20]{0};
int L, C;
char a[20];
vector<char> ans;

void func(int index, int moum, int jaum) {
    if(ans.size() == L) {
        if(moum >= 1 && jaum >= 2) {
            for(char c : ans) {
                cout << c;
            }
            cout << '\n';
            return;
        }
        return;
    }
    if(index > C) return;
    ans.push_back(a[index]);
    func(index+1, moum + is_moum[index], jaum + !is_moum[index]);
    ans.pop_back();
    func(index+1, moum, jaum);
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
    func(1, 0, 0);
}