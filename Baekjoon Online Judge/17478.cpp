#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;
using pll=pair<ll, ll>;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

void pr(int now, int to) {
    if (now == to) {
        cout << string(now*4, '_') <<  "\"����Լ��� ������?\"\n";
        cout << string(now*4, '_') <<  "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
        cout << string(now*4, '_') <<  "��� �亯�Ͽ���.\n";
        return;
    }
    cout << string(now*4, '_') <<  "\"����Լ��� ������?\"\n";
    cout << string(now*4, '_') <<  "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
    cout << string(now*4, '_') <<  "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
    cout << string(now*4, '_') <<  "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
    pr(now+1, to);
    cout << string(now*4, '_') <<  "��� �亯�Ͽ���.\n";
}

int main() {

    int n; cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    pr(0, n);
}