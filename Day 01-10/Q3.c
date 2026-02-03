/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.*/
n = int(input())

arr = list(map(int, input().split()))

k = int(input())

found = False
comparisons = 0

for i in range(n):
    comparisons += 1               
    if arr[i] == k:
        found = True
        print(f"Found at index {i}")
        break

if not found:
    print("Not Found")

print(f"Comparisons = {comparisons}")
