n, m = map(int, input().split())
up=1
down=1
for i in range(n-m+1, n+1):
    up *= i
for i in range(1, m+1):
    down *= i
print(up//down)