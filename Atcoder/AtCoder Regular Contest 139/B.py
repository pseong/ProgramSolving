import sys

T = int(sys.stdin.readline().rstrip())
while T > 0:
    T = T - 1
    n, a, b, x, y, z = map(int, sys.stdin.readline().split())
    cost1 = x*a*b
    costA = y*b
    costB = z*a
    if (costA > costB):
        costB, costA = costA, costB
        b, a = a, b
        z, y = y, z
    if (cost1 <= costA):
        print(n*x)
        continue

    cost = 10000000000000000000
    for i in range(100000):
        _n = n-i*b
        _cost = z*i
        if (_n < 0):
            break
        _cost += ((int)(_n/a))*y + (_n-((int)(_n/a))*a)*x
        cost = min(cost, _cost)

    ffrom = (int)(n/b)
    to = max((int)(n/b)-100000, 0)
    for i in range(ffrom, to, -1):
        _n = n-i*b
        _cost = z*i
        if (_n < 0):
            break
        _cost += ((int)(_n/a))*y + (_n-((int)(_n/a))*a)*x
        cost = min(cost, _cost)
    print(cost)