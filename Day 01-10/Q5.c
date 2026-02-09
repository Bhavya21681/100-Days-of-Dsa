/*Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/
p = int(input())
a = list(map(int, input().split()))
q = int(input())
b = list(map(int, input().split()))

i = j = 0
result = []

while i < p and j < q:
    if a[i] <= b[j]:
        result.append(a[i])
        i += 1
    else:
        result.append(b[j])
        j += 1

result += a[i:]
result += b[j:]

print(*result)
