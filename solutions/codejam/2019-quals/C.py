"""
Code Jam 2019 Qualification Round
C. Cryptopangrams

aquablitz11 (2019-04-06)
"""

from math import gcd

T = int(input())
for t in range(1, T+1):
    N, L = map(int, input().split())
    arr = list(map(int, input().split()))
    P = [0]*(L+1)

    # find starting point
    fnd = 0
    for i in range(L-1): # loop from 0 to L-2
        g = gcd(arr[i], arr[i+1])
        if g != arr[i]:
            fnd = i
            P[i] = arr[i]//g 
            break
    # go left and right
    for i in range(fnd+1, L+1): # loop from fnd+1 to L
        P[i] = arr[i-1]//P[i-1]
    for i in range(fnd-1, -1, -1): # loop from fnd-1 to 0 (backward)
        P[i] = arr[i]//P[i+1]
    # build dictionary
    LP = dict()
    for k, v in enumerate(sorted(set(P))):
        LP[v] = chr(k+ord('A'))
    for i in range(L+1):
        P[i] = LP[P[i]]
    print("Case #" + str(t) + ": " + "".join(P))