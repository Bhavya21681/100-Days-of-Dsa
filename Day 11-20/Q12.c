/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).*/
m, n = map(int, input().split())

if m != n:
    print("Not a Symmetric Matrix")
else:
    mat = [list(map(int, input().split())) for _ in range(m)]
    sym = True
    for i in range(m):
        for j in range(m):
            if mat[i][j] != mat[j][i]:
                sym = False
    print("Symmetric Matrix" if sym else "Not a Symmetric Matrix")
