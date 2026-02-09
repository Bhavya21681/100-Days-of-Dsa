/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.*/
n = int(input())
a = list(map(int, input().split()))

if n == 0:
    print()
else:
    i = 0
    for j in range(1, n):
        if a[j] != a[i]:
            i += 1
            a[i] = a[j]
    
    print(*a[:i+1])
