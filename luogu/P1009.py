t = 1
fact = 1
n = int(input())
res = 0

while t <= n:
    fact *= t
    res += fact
    t += 1

print(res)
