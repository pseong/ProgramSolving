import sys

t = []

def calc(mid):
    ret = 0
    for i in range(n):
        ret += mid // t[i]
    return ret

n, m = map(int,input().split())
for _ in range(n):
    t.append(int(sys.stdin.readline().rstrip()))

lo = 1
hi = 1000000000000000000
ans = 0
while (lo <= hi):
    mid = (lo + hi) // 2
    cal = calc(mid)
    if (cal >= m):
        ans = mid
        hi = mid - 1
    else:
        lo = mid + 1
    
print(ans)