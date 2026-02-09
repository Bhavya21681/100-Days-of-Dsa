/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.*/
n = int(input())
a = list(map(int, input().split()))
k = int(input())

count = 0

for i in range(n):
    count += 1
    if a[i] == k:
        print("Found at index", i)
        print("Comparisons =", count)
        exit()

print("Not Found")
print("Comparisons =", count)
