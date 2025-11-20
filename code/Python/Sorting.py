# (예제) 큰 수 만들기
def f(a, b):
    return(int(a+b)<int(b+a))-(int(a+b)>int(b+a)) #int(b+a)가 크면 1,int(a+b)가 크면 -1, 같으면 0
import functools
A = list(input().split())
print(int(''.join(sorted(A, key=functools.cmp_to_key(f)))))