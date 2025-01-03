def padrt(i):
    if i==0:
        return "sa"
    return "pra" + padrt(i-1)

for i in range(3):
    print(padrt(i))
