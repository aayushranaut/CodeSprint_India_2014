from math import*
from fractions import*
def lcm(a, b):
    return (a*b)/gcd(a,b)
for _ in range(input()):
    n, m=map(int, raw_input().split())
    lis=map(int, raw_input().split())
    ll=reduce(lcm, lis)
    print n/ll
    