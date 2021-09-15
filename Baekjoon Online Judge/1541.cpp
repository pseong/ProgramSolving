#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    string num="";
    int idx=0;
    int sum=0;
    int ans=0;
    bool minus=false;
    for(int i=0; i<str.size(); i++) {
        if(str[i]=='-') {
            int a=stoi(num);
            num = "";
            sum += a;
            if(!minus) ans += sum;
            else ans -= sum;
            minus = true;
            sum = 0;
        } else if(str[i]=='+') {
            int a=stoi(num);
            num = "";
            sum += a;
        }
        else {
            num.push_back(str[i]);
        }
    }
    int a=stoi(num);
    num = "";
    sum += a;
    if(minus) ans -= sum;
    else ans += sum;
    cout << ans;
}