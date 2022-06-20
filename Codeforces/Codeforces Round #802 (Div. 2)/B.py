t = int(input())
for _ in range(t):
    n = int(input())
    x = input()
    if x[0] == '9':
        print(int('1'*(n+1)) - int(x))
    else:
        print(int('9'*n) - int(x))