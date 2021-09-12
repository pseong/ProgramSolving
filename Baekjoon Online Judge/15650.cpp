#include <iostream>
#include <vector>

using namespace std;

int n, m;
int ok[9]{ 0 };
vector<int> v;

void show() {
    for(int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}

void func(int start, int select) {
    if(select == m) {
        show();
        return;
    }
    if(start == n+1) {
        return;
    }
    v.push_back(start);
    func(start+1, select+1);
    v.pop_back();
    func(start+1, select);
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m;
    func(1, 0);
}