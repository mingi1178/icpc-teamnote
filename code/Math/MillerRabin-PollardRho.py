# n<2^32: alist = [2, 7, 61]
# n<2^64
alist = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]

def miller_rabin(n, a):
    d = (n-1)//2
    while d%2 == 0:
        if pow(a, d, n) == n-1: return 1
        d //= 2
    tmp = pow(a, d, n)
    return tmp == n-1 or tmp == 1

def is_prime(n):
    if n <= 1: return 0
    if n <= 10**10:
        for i in range(2, int(n**0.5)+1):
            if n%i == 0: return 0
        return 1
    for a in alist:
        if not miller_rabin(n, a): return 0
    return 1

from random import randint
from math import gcd

def PollardRho(n):
    y = x = randint(2, n)
    c = randint(1, n)
    d = 1
    while d==1:
        x = x*x%n+c
        if x >= n: x -= n
        y = y*y%n+c
        if y >= n: y -= n
        y = y*y%n+c
        if y >= n: y -= n
        d = gcd(abs(x-y), n)
    if is_prime(d): return d
    return PollardRho(d)

res=[]
def getFactor(n):
    while n%2==0: n//=2; res.append(2)
    while n!=1 and not(is_prime(n)):
        d=PollardRho(n)
        while n%d==0: n//=d; res.append(d)
    if n!=1: res.append(n)