def power(a, b, mod):
    r = 1
    while b:
        if b&1: r = r*a%mod
        a = a*a%mod
        b >>= 1
    return r