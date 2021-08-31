#include <iostream>

using namespace std;

int a[20]{0};
int n;
int oper[4]; // 순서 : +, -, *, /

pair<int, int> func(int num, int index, int plus, int minus, int mul, int div) {
    if(index == n) return {num, num};

    pair<int, int> res = {-1000000000, 1000000000};

    pair<int, int> val;
    if(plus>0) {
        val = func(num+a[index], index+1, plus-1, minus, mul, div);
        res.first = max(res.first, val.first);
        res.second = min(res.second, val.second);
    }
    if(minus>0) {
        val = func(num-a[index], index+1, plus, minus-1, mul, div);
        res.first = max(res.first, val.first);
        res.second = min(res.second, val.second);
    }
    if(mul>0) {
        val = func(num*a[index], index+1, plus, minus, mul-1, div);
        res.first = max(res.first, val.first);
        res.second = min(res.second, val.second);
    }
    if(div>0) {
        val = func(num/a[index], index+1, plus, minus, mul, div-1);
        res.first = max(res.first, val.first);
        res.second = min(res.second, val.second);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<4; i++) {
        int a;
        cin >> a;
        oper[i] = a;
    }

    auto ans = func(a[0], 1, oper[0], oper[1], oper[2], oper[3]);
    cout << ans.first << '\n' << ans.second;
}