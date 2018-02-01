n, m = map(int, (raw_input().strip()).split(' '))
mi = 10000.0
for a0 in range(n):
    a, b = map(float, (raw_input().strip()).split(' '))
    if (mi > a/b):
        mi = a/b
print m*mi
