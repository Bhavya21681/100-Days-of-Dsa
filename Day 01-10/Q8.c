/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.*/
a, b = map(int, input().split())

def power(a, b):
    if b == 0:
        return 1
    if b == 1:
        return a
    return a * power(a, b - 1)

print(power(a, b))
