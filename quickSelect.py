def choose_pivot1(lst):
    return len(lst) - 1


def swap(A, B, ind1, ind2):
    n = len(A)
    m = len(B)
    firstA = True
    secondA = True
    if ind1 >= n:
        firstA = False
    if ind2 >= n:
        secondA = False
    if firstA and secondA:
        tmp = A[ind1]
        A[ind1] = A[ind2]
        A[ind2] = tmp
    elif not firstA and secondA:
        tmp = B[ind1 - n]
        B[ind1 - n] = A[ind2]
        A[ind2] = tmp
    elif firstA and not secondA:
        tmp = B[ind2 - n]
        B[ind2 - n] = A[ind1]
        A[ind1] = tmp
    elif not firstA and not secondA:
        tmp = B[ind1 - n]
        B[ind1 - n] = B[ind2 - n]
        B[ind2 - n] = tmp


def getter(A, B, ind):
    if ind <= len(A) - 1:
        return A[ind]
    else:
        return B[ind-len(A)]


def partition(A, B, p):
    n = len(A)
    m = len(B)
    swap(A, B, n + m - 1, p)

    i = -1
    j = n + m - 1
    v = getter(A, B, n + m - 1)
    while True:
        i = i + 1
        j = j - 1
        while i < n + m and getter(A, B, i) < v:
            i = i + 1
        while j > 0 and getter(A, B, j) > v:
            j = j - 1
        if i >= j:
            break
        else:
            swap(A, B, i, j)
    swap(A, B, n + m - 1, i)
    return i


def quickSelect(A, B, k):
    n = len(A)
    m = len(B)
    p = 0
    if len(B) == 0:
        p = choose_pivot1(A)
    else:
        p = choose_pivot1(B) + len(A)

    i = partition(A, B, p)
    if i == k:
        return getter(A, B, i)
    elif i > k:
        if i > n - 1:
            return quickSelect(A, B[0: i-n], k)
        else:
            return quickSelect(A[0: i], [], k)
    elif i < k:
        if i > n - 1:
            return quickSelect([], B[i-n+1:], k-i-1)
        else:
            return quickSelect(A[i+1:], B, k-i-1)

A = [1,2,3,41,51,51,51,2,3,123,123,123,12,412,512,51,25]
B = [1,23,123,123,145,12,5,15,15,61,51,651,65,16,51,6,5165,165,165,165,16,51]
A1 = [1,1,1,1,1,1]
B1 = [4,5,6]
print(quickSelect(A,B,len(A+B)//2))
print(sorted(A+B)[len(A+B)//2])
print(partition(B1, A1, 2))